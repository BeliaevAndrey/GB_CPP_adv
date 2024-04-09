#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "toy.h"

class Dog {

private:
    std::string name;
    int age;
    std::shared_ptr<Toy> currentToy;

public:
    Dog(std::string, int);

    Dog();

    void voice();

    std::string getName();
    int getAge();
    std::shared_ptr<Toy> getToy();

    void pickupToy(std::shared_ptr<Toy>);
    void dropToy();
};
