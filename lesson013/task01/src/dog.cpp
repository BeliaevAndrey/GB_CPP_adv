#include "dog.h"

Dog::Dog(std::string inName, int inAge) :
    name(inName)
{
    age = (inAge >= 0 && inAge < 30) ? inAge : 0;
}

Dog::Dog() : Dog("Junior", 0)
{};


std::string Dog::getName() { return name; }

int Dog::getAge() { return age; }

/* Геттер */
std::shared_ptr<Toy> Dog::getToy()
{
    return currentToy;
}

void Dog::voice()
{
    std::cout << "Bark!" << std::endl;
}

/* Подобрать игрушку */
void Dog::pickupToy(std::shared_ptr<Toy> inToy)
{
    if (currentToy == inToy)
    {
        std::cout << name << ": "
            << "I already have this toy." << std::endl;
        return;
    }
    if (inToy.use_count() == 2) {
        if (currentToy)
            dropToy();
        currentToy = inToy;
    }
    else
        std::cout << name << ": "
        << "Another dog is playing with this toy." << std::endl;
}

/* Бросить игрушку */
void Dog::dropToy()
{
    if (currentToy == nullptr)
    {
        std::cout << name << ": " << "Nothing to drop." << std::endl;
        return;
    }
    currentToy.reset(); // todo: checkup thoroughly
}
