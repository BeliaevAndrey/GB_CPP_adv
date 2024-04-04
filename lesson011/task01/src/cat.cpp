#include "cat.h"

Cat::Cat(std::string inName, Talent* inTalent)
{
    setType("Cat");
    setName(inName);
    setTalent(inTalent);
}

/* Basic */
void Cat::voice() {
    std::cout << "Meow!" << std::endl;
}

// void Cat::run() {
//     std::cout << getName() << " is running!" << std::endl;
// }

// void Cat::jump() {
//     std::cout << getName() << " is jumping!" << std::endl;
// }

