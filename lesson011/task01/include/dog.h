// lesson011/task01/include/dog.h
#pragma once

#include "animal.h"

class Dog : virtual public Animal
{

public:
    Dog(std::string inName, Talent* inTalent);

    /* Basic skills */
    virtual void voice() override;

};

