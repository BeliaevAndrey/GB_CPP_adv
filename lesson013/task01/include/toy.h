#pragma once

#include <iostream>
#include <string>
#include <memory>

class Toy {
private:
    std::string name_;
public:
    Toy(const std::string& name);
    std::string getName();
    ~Toy();
};
