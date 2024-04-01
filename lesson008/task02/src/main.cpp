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

/* commands:
add
call
sms
exit
*/

#include <iostream>
#include <map>
#include <string>

class Phone
{
    std::map<PhoneNumber, std::string> pBook;

    bool checkPhone(std::string& phone) {
        int lLim = 48, uLim = 57;
        if (phone[0] != '+')
            return false;
        for (int i = 1; i < phone.length(); i++)
            if (phone[i] > uLim || phone[i] < lLim)
                return false;
        return true;
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
            pBook[PhoneNumber(phone)] = name;
        }
        else
            std::cout << "rong phone format." << std::endl;
    }

    void call() {

    }

    void sms() {

    }

    void exit() {

    }
};

class PhoneNumber
{
    std::string phoneNo;

public:
    PhoneNumber(std::string phone) {
        phoneNo = phone;
    }

    void printPhone() {
        std::cout << phoneNo << std::endl;
    }
};



int main()
{

    return 0;
}
