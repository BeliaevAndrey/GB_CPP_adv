#pragma once

#include <map>

#include "phonenumber.h"

class Phone
{
    std::map<std::string, std::string> pBook;

    bool checkPhone(std::string& phone);
    bool searchContact(std::string& valueIn, std::string valueOut);
    std::map<std::string, std::string> getPBook();

public:
    Phone();
    void add();
    void call(std::string value);
    void sms(std::string value);
    void getSms(std::string& message);
    void printBook();
    void exit(bool&);
};

