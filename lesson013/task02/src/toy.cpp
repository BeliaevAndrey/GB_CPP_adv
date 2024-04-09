#include "toy.h"

Toy::Toy(const std::string& name) {
    name_ = name;
}

Toy::~Toy() {
    std::cout << "Toy " << name_ << " was dropped " << std::endl;
}

std::string Toy::getName() { return name_; }
