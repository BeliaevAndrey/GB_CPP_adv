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

#include "phone.h"


int main()
{
    std::string menu = "Commands are:\nADD\nCALL\nSMS\nEXIT\n";
    std::cout << menu << std::endl;

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
        else if (command == "PRINT_BOOK") {
            phone->printBook();
        }
        else std::cout << "Command not recognized. (Check letters case)"
            << std::endl;

    }

    return 0;
}
