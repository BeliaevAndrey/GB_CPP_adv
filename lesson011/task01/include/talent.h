// lesson011/task01/include/talent.h
#pragma once

#include <string>

class Talent {
    std::string name;

protected:
    virtual void setName(std::string inName);

public:
    std::string getName();
    virtual std::string report()=0;

};


/* Talents */

class Dance : virtual public Talent {
public:
    Dance();
    virtual std::string report() override;
};


class Swim : virtual public Talent {
public:
    Swim();
    virtual std::string report() override;
};


class Sing : virtual public Talent {
public:
    Sing();
    virtual std::string report() override;
};
