#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "toy.h"
#include "shared_ptr_toy.h"

class Dog {

private:
    std::string name;
    int age;
    shared_ptr_toy currentToy;

public:
    Dog(std::string, int);

    Dog();

    void voice();

    std::string getName();
    int getAge();
    shared_ptr_toy getToy();

    void pickupToy(shared_ptr_toy);
    void dropToy();
};
