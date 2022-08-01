#include "SharedToys.h"

std::string DEFAULT_TOY_NAME = "None";

//// Toy class

Toy::Toy(): name(DEFAULT_TOY_NAME) {}
Toy::Toy(std::string& _name): name(_name) {}


//// SharedToyPtr class

SharedToyPtr::SharedToyPtr(Toy* _obj): obj(_obj) {
    refsCount = new int(1);
}

SharedToyPtr::~SharedToyPtr() {
    std::cout << "Deleting shared toy ptr, current references amount: " << *refsCount << std::endl;
    --*refsCount;
    assert(*refsCount >= 0);
    if (*refsCount == 0) {
        delete obj;
        delete refsCount;
        std::cout << "No references left after deletion, deleting object." << std::endl;
    } else {
        std::cout << "References left after deletion: " << *refsCount << ", preserving object." << std::endl;
    }
}

SharedToyPtr::SharedToyPtr(const SharedToyPtr& other) {
    // Do not create new toy upon copying shared ptr,
    // instead assign same toy to this object and increase ref count
    obj = other.obj;
    refsCount = other.refsCount;
    ++*refsCount;
}

SharedToyPtr& SharedToyPtr::operator=(const SharedToyPtr& other) {
    if (&other == this) return *this;
    if (obj != nullptr) {
        if (*refsCount <= 1) {
            // Delete toy and counter, if noone uses this toy anymore
            delete obj;
            delete refsCount;
        } else {
            // If there are other users, only decrease counter
            --*refsCount;
        }
    }
    obj = other.obj;
    refsCount = other.refsCount;
    ++*refsCount;
    return *this;
}

SharedToyPtr make_shared_toy(std::string& name) {
    auto toy = new Toy(name);
    return SharedToyPtr(toy);
}

SharedToyPtr make_shared_toy() {
    auto toy = new Toy(DEFAULT_TOY_NAME);
    return SharedToyPtr(toy);
}