#include <iostream>
#include <string>

#include "phonenumber.h"


PhoneNumber::PhoneNumber() {}

PhoneNumber::PhoneNumber(std::string phone) {
    phoneNo = phone;
}

std::string PhoneNumber::getNumber() {
    return phoneNo;
}

void PhoneNumber::printPhone() {
    std::cout << phoneNo << std::endl;
}

bool PhoneNumber::eq(PhoneNumber o) {
    return (phoneNo == o.getNumber());
}

bool PhoneNumber::eq(std::string o) {
    return (phoneNo == o);
}
