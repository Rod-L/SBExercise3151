#include <iostream>
#include "SharedToys.h"

class ToyOwner {
public:
    SharedToyPtr myToy;

    ToyOwner(): myToy(make_shared_toy()) {};
    explicit ToyOwner(Toy& toy): myToy(SharedToyPtr(&toy)) {};
    explicit ToyOwner(SharedToyPtr& toy): myToy(SharedToyPtr(toy)) {};
};

int main() {
    std::cout << "Starting" << std::endl;
    std::string toy_name = "Test";
    SharedToyPtr test = make_shared_toy(toy_name);

    ToyOwner owner1(test);
    ToyOwner owner2(test);

    std::cout << "Ending" << std::endl;
}
