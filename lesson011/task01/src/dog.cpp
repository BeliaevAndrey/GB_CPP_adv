#include "dog.h"

Dog::Dog(std::string inName, Talent* inTalent)
{
    setType("Dog");
    setName(inName);
    setTalent(inTalent);
}

void Dog::voice() {
    std::cout << "Bark!" << std::endl;
}

// void Dog::run() {
//     std::cout << getName() << " is running!" << std::endl;
// }

// void Dog::jump() {
//     std::cout << getName() << " is jumping!" << std::endl;
// }
