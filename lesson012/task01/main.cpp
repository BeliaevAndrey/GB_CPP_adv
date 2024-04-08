/*
Задание 1. Пользовательские запросы

Что нужно сделать

Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису
httpbin.org. Пользователь взаимодействует с программой с помощью команд: "get",
"post", "put", "delete", "patch". В зависимости от команды к серверу httpbin.
org осуществляется запрос того или иного типа. Содержимое ответа сервера
выводится в стандартный вывод. Программа завершается, когда пользователь вводит
команду "exit".

*/

#include <iostream>
#include <string>

#include <cpr/cpr.h>

std::string address = "http://httpbin.org/";


void funcGet(cpr::Response& r) {
    r = cpr::Get(cpr::Url(address + "get"));
}

void funcPost(cpr::Response& r) {
    r = cpr::Post(cpr::Url(address + "post"));
}

void funcPut(cpr::Response& r) {
    r = cpr::Put(cpr::Url(address + "put"));
}

void funcDelete(cpr::Response& r) {
    r = cpr::Delete(cpr::Url(address + "delete"));
}

void funcPatch(cpr::Response& r) {
    r = cpr::Patch(cpr::Url(address + "patch"));
}

void printResponse(cpr::Response& r) {
    std::cout << "status code: " << r.status_code << std::endl;
    std::cout << "text:        \n" << r.text << std::endl;
}

int main()
{
    cpr::Response response;
    std::string command = "";
    bool runFlag = true;
    while (runFlag) {
        std::cout << "Input command: ";
        std::cin >> command;

        if (command == "get") {
            funcGet(response);
            printResponse(response);
        }

        else if (command == "post") {
            funcPost(response);
            printResponse(response);

        }
        else if (command == "put") {

            funcPut(response);
            printResponse(response);

        }

        else if (command == "delete") {
            funcDelete(response);
            printResponse(response);

        }

        else if (command == "patch") {
            funcPatch(response);
            printResponse(response);

        }
        else if (command == "exit") {
            std::cout << "Exiting..." << std::endl;
            runFlag = false;
        }
        else std::cout << "Unknown commands" << std::endl;
    }
    return 0;
}