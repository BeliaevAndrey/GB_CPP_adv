// lesson011/task01/include/dog.h
#pragma once

#include "animal.h"

class Cat : virtual public Animal
{

public:
    Cat(std::string inName, Talent* inTalent);

    /* Basic skills */
    virtual void voice() override;

    
};

