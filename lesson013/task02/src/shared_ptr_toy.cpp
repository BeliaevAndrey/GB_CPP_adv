#pragma once

#include "shared_ptr_toy.h"



shared_ptr_toy::shared_ptr_toy()
{
    object = nullptr;
    counter = nullptr;
}

shared_ptr_toy::shared_ptr_toy(std::string name)
{
    object = new Toy(name);
    counter = new int(1);
}

shared_ptr_toy::shared_ptr_toy(Toy* other) {
    object = other;
    counter = new int(1);
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& other)
{
    object = other.object;
    counter = other.counter;
    if (counter)
        *counter += 1;
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& other)
{
    if (this != &other) {
        reset();
        object = other.object;
        counter = other.counter;
        if (counter) *counter += 1;
    }

    return *this;
}

shared_ptr_toy::~shared_ptr_toy()
{
    if (!object) return;

    *counter -= 1;
    if (*counter == 0)
    {
        delete object;
        delete counter;
        object = nullptr;
        counter = nullptr;
    }

};

void shared_ptr_toy::reset() {
    if (!object) return;

    *counter -= 1;
    if (*counter == 0)
    {
        delete object;
        delete counter;
    }
}

shared_ptr_toy::operator bool()
{
    return object != nullptr;
}

bool shared_ptr_toy::operator==(const shared_ptr_toy& other)
{
    return object == other.object;
}

Toy* shared_ptr_toy::getToy()
{
    if (object) return object;
    return nullptr;
}

int shared_ptr_toy::use_count()
{
    if (object) return *counter;
    return 0;
}
