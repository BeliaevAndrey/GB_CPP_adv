// lesson011/task01/include/animal.h
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "talent.h"

class Animal {
private:
    std::string type;
    std::string name;
    std::vector<Talent*> talents;

protected:
    void setName(std::string inName);
    void setType(std::string inType);

public:
    virtual void setTalent(Talent* inTalent);
    virtual Talent* getTalent(std::string tName);

    std::string getName();
    std::string getType();
    std::string introduceSelf();

    /* Basic skills */
    virtual void voice() = 0; // class becomes abstract
    virtual void run();
    virtual void jump();

    /* Trained skills */
    void show_talents();


};
