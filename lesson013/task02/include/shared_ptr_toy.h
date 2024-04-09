#pragma once

#include "toy.h"
#include <memory>


class shared_ptr_toy
{
private:
    int count = 0;
    Toy* object;
public:
    shared_ptr_toy();
    shared_ptr_toy(std::string&);
    shared_ptr_toy(Toy&);
    
    // ~shared_ptr_toy();

    shared_ptr_toy& operator=(const Toy&);
    bool operator==(const shared_ptr_toy&);
    operator bool();
    int use_count();
    void reset();

};

shared_ptr_toy make_shared_toy(const Toy&);
shared_ptr_toy make_shared_toy(std::string name);
