#pragma once

#include <iostream>
#include <string>

class PhoneNumber
{
    std::string phoneNo;

public:
    PhoneNumber();

    PhoneNumber(std::string phone);

    std::string getNumber();

    void printPhone();

    bool eq(PhoneNumber o);

    bool eq(std::string o);




};
