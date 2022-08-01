#pragma once
#include <iostream>
#include <cassert>

//// Toy class

class Toy {
    std::string name;
public:
    Toy();
    explicit Toy(std::string& _name);
};

//// SharedToyPtr class

class SharedToyPtr {
    int* refsCount;
    Toy* obj;
public:
    explicit SharedToyPtr(Toy* _obj);
    ~SharedToyPtr();
    SharedToyPtr(const SharedToyPtr& other);
    SharedToyPtr& operator=(const SharedToyPtr& other);
};

SharedToyPtr make_shared_toy(std::string& name);
SharedToyPtr make_shared_toy();