/*
Задание 2. Реализация программы симуляции мобильного телефона
Что нужно сделать Реализуйте программу простой симуляции работы мобильного
телефона. По мобильному телефону можно звонить и отправлять СМС. Также
мобильный телефон содержит адресную книгу. Телефон и отдельные записи
адресной книги должны быть реализованы с помощью классов. Все номера
телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

* Команда add добавляет в адресную книгу новый номер телефона и ассоциирует
    его с именем контакта. Оба эти параметра команда получает от пользователя
    через стандартный ввод.
* Команда call запрашивает у пользователя имя контакта или номер телефона,
    на который требуется позвонить. Сам по себе звонок симулируется с помощью
    вывода в консоль сообщения CALL с номером телефона, на который
    осуществляется вызов.
* Команда sms. Запрашивает у пользователя номер телефона (или имя контакта),
    на который требуется послать сообщение. Само сообщение также вводится через
    стандартный ввод.
* Команда exit -- выход из программы.

Советы и рекомендации
Сам по себе тип номера телефона вы тоже можете реализовать с помощью
отдельного класса.

Что оценивается
Корректность работы программы.
*/

#include <iostream>
#include <map>
#include <string>
class PhoneNumber
{
    std::string phoneNo;

public:
    PhoneNumber() {}

    PhoneNumber(std::string phone) {
        phoneNo = phone;
    }

    std::string getNumber() {
        return phoneNo;
    }

    void printPhone() {
        std::cout << phoneNo << std::endl;
    }

    bool eq(PhoneNumber o) {
        return (phoneNo == o.getNumber());
    }

    bool eq(std::string o) {
        return (phoneNo == o);
    }

};

class Phone
{
    std::map<std::string, std::string> pBook;

    bool checkPhone(std::string& phone) {
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

    bool searchContact(std::string name, PhoneNumber* phoneNo) {
        for (std::map<std::string, std::string>::iterator it = pBook.begin();
            it != pBook.end(); it++) {
            if (it->second == name) {
                *phoneNo = it->first;
                return true;
            }
        }
        return false;
    }

    bool searchContact(PhoneNumber* phoneNo, std::string name) {
        for (std::map<std::string, std::string>::iterator it = pBook.begin();
            it != pBook.end(); it++) {
            if (phoneNo->eq(it->first)) {
                name = it->second;
                return true;
            }
        }
        return false;
    }

public:
    Phone() {}
    void add() {
        std::string phone;
        std::cout << "Input number: ";
        std::cin >> phone;
        if (checkPhone(phone)) {
            std::cout << "Input name: ";
            std::string name;
            std::cin >> name;
            PhoneNumber phone = PhoneNumber(phone);
            pBook[phone.getNumber()] = name;
            // pBook.insert(std::pair<std::string, std::string>(phone.getNumber(), name));
        }
        else
            std::cout << "Wrong phone format." << std::endl;
    }

    void call(std::string value) {
        if (checkPhone(value)) {
            PhoneNumber* number = new PhoneNumber(value);
            std::string name;
            if (searchContact(number, name)) {
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
            PhoneNumber* number = new PhoneNumber();
            if (searchContact(value, number)) {
                std::cout << "Calling: " << value << " "
                    << number->getNumber()
                    << std::endl;
                delete number;
                number = nullptr;
            }
            else
                std::cout << "Not found" << std::endl;
        }
    }

    void sms(std::string value) {
        if (checkPhone(value)) {
            PhoneNumber* number = new PhoneNumber(value);
            std::string name;
            if (searchContact(number, name)) {
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
            PhoneNumber* number = new PhoneNumber();
            if (searchContact(value, number)) {
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
    }

    void getSms(std::string& message) {
        std::cout << "Input message text:\n";
        std::getline(std::cin, message);
    }

    void exit(bool& activeFlag) {
        std::cout << "exiting..." << std::endl;
        activeFlag = false;
    }

    void printBook() {
        for (std::map<std::string, std::string>::iterator it = pBook.begin();
            it != pBook.end(); it++) {
            PhoneNumber phone = it->first;
            std::cout << it->second << " "
                << phone.getNumber()
                << std::endl;
        }

    }
};


int main()
{
    Phone* phone = new Phone();
    bool activeFlag = true;
    std::string command;
    while (activeFlag) {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "ADD") {
            phone->add();
        }
        else if (command == "CALL") {
            std::string value;
            std::cout << "Input name or number: ";
            std::cin >> value;
            phone->call(value);
        }
        else if (command == "SMS") {
            std::string value;
            std::cout << "Input name or number: ";
            std::cin >> value;
            phone->sms(value);
        }
        else if (command == "EXIT") {
            phone->exit(activeFlag);
        }
        else std::cout << "Command not recognized. (Check letters case)"
            << std::endl;

    }

    return 0;
}
