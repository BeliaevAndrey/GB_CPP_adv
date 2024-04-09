#pragma once

#include <iostream>
#include <string>

class Toy {
private:
    std::string name_;
public:
    Toy(const std::string& name);
    std::string getName();
    ~Toy();
};
