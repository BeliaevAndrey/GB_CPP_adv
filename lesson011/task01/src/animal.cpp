#include "animal.h"

void Animal::setName(std::string inName) { name = inName; }

void Animal::setType(std::string inType) { type = inType; }

std::string Animal::getName() { return name; }

void Animal::setTalent(Talent* inTalent) {
    talents.push_back(inTalent);
}

Talent* Animal::getTalent(std::string name) {
    for (int i = 0; i < talents.size(); i++)
    {
        if (talents[i]->getName() == name)
        {
            return talents[i];
        }
    }
    return nullptr;
}

std::string Animal::getType() { return type; }

std::string Animal::introduceSelf() {
    std::string answer = getType() + " ";
    answer += getName();
    return answer;
}

void Animal::show_talents() {
    for (int i = 0; i < talents.size(); i++)
        std::cout << "It can " << talents[i]->getName() << std::endl;
}

void Animal::run() {
    std::cout << getName() << " is running!" << std::endl;
}

void Animal::jump() {
    std::cout << getName() << " is jumping!" << std::endl;
}
