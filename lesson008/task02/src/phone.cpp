#include <map>

#include "phone.h"

bool Phone::checkPhone(std::string& phone) {
    int lLim = 48, uLim = 57;
    if (phone[0] != '+')
    {
        std::cout << "First must be '+'" << std::endl;
        return false;
    }
    if (phone[1] != '7')
    {
        std::cout << "Second must be '7'" << std::endl;
        return false;
    }
    if (phone.length() < 12)
    {
        std::cout << "Number is too short" << std::endl;
        return false;
    }
    for (int i = 1; i < phone.length(); i++)
        if (phone[i] > uLim || phone[i] < lLim)
            return false;
    return true;
}

bool Phone::searchContact(std::string& valueIn, std::string valueOut) {
    if (checkPhone(valueIn)) {
        for (std::map<std::string, std::string>::iterator
            it = pBook.begin(); it != pBook.end(); it++) {
            if (it->first == valueIn) {
                valueOut = it->second;
                return true;
            }
        }
    }
    else {
        for (std::map<std::string, std::string>::iterator
            it = pBook.begin(); it != pBook.end(); it++) {
            if (it->second == valueIn) {
                valueOut = it->first;
                return true;
            }
        }

    }
    return false;
}

Phone::Phone() {}
void Phone::add() {
    std::string phone;
    std::cout << "Input number: ";
    std::cin >> phone;
    if (checkPhone(phone)) {
        std::cout << "Input name: ";
        std::string name;
        std::cin >> name;
        pBook.insert(std::make_pair(phone, name));

    }
    else
        std::cout << "Wrong phone format." << std::endl;
}

void Phone::call(std::string value) {
    if (checkPhone(value)) {
        PhoneNumber* number = new PhoneNumber(value);
        std::string name;
        if (searchContact(value, name)) {
            std::cout << "Calling: " << name << " "
                << number->getNumber()
                << std::endl;
            delete number;
            number = nullptr;
        }
        else
            std::cout << "Not found" << std::endl;

    }
    else {
        std::string number;
        if (searchContact(value, number)) {
            std::cout << "Calling: " << value << " "
                << number
                << std::endl;
        }
        else
            std::cout << "Not found" << std::endl;
    }
}

void Phone::sms(std::string value) {
    if (checkPhone(value)) {
        PhoneNumber* number = new PhoneNumber(value);
        std::string name;
        if (searchContact(value, name)) {
            std::cout << "Recipient found ";
            std::string message;
            getSms(message);
            std::cout << "SMS: " << value << " "
                << number->getNumber() << "\n"
                << "Mesage:\n"
                << message
                << std::endl
                << std::endl;
            delete number;
            number = nullptr;
        }
        else
            std::cout << "Not found" << std::endl;

    }
    else {
        std::string number;
        if (searchContact(value, number)) {
            std::cout << "Recipient found. ";
            std::string message = "";
            getSms(message);
            std::cout << "SMS: " << value << " "
                << number << "\n"
                << "Mesage:\n"
                << message
                << std::endl
                << std::endl;
        }
        else
            std::cout << "Not found" << std::endl;
    }
}
void Phone::getSms(std::string& message) {
    std::cin.ignore();
    std::cout << "Input message text:\n";
    getline(std::cin, message);
}

void Phone::exit(bool& activeFlag) {
    std::cout << "exiting..." << std::endl;
    activeFlag = false;
}

std::map<std::string, std::string> Phone::getPBook() {
    return pBook;
}

void Phone::printBook() {
    std::cout << "Phone book\n" << std::endl;
    for (std::map<std::string, std::string>::iterator it = getPBook().begin();
        it != getPBook().end(); it++) {
        PhoneNumber phone = it->first;
        std::cout << it->second << " "
            << phone.getNumber()
            << std::endl;
    }
}
