#pragma once

#include <string>

#include "toy.h"


class shared_ptr_toy {
    Toy* object;
    int* counter;

public:
    shared_ptr_toy();

    shared_ptr_toy(std::string name);

    shared_ptr_toy(Toy* other);

    shared_ptr_toy(const shared_ptr_toy& other);

    shared_ptr_toy& operator=(const shared_ptr_toy& other);

    ~shared_ptr_toy();

    void reset();

    operator bool();

    bool operator==(const shared_ptr_toy& other);

    Toy* getToy();

    int use_count();

};
