/*Задание 1. Телефонный справочник

Что нужно сделать
Напишите программу «Телефонный справочник». На вход программе поступают запросы
трёх типов:

69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что
абоненты по разным номерам могут иметь одинаковые фамилии. В таком случае на
запрос 3 необходимо выдать все номера через пробелы. Операции запросов должны
работать за O(logn) или O(logn × количество номеров с этой фамилией).

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

std::string CONDITIONS = "Request format:"
                         "XX-XX-XX Surname -- добавить телефон и фамилию абонента в справочник\n"
                         "where 'X' -- is strictly a digit ('-' sign is also allowed)\n"
                         "XX-XX-XX -- узнать фамилию абонента по номеру телефона\n"
                         "Surname -- узнать телефон абонента по фамилии\n";

std::map<std::string, std::string> pBook;

void printPhoneBook()
{
    std::cout << "\nPhone book content: " << std::endl;
    for (std::map<std::string, std::string>::iterator it = pBook.begin();
         it != pBook.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    std::cout << std::endl;
}

int getPhone(std::pair<std::string, std::vector<std::string>> answer)
{
    return 2;
}

int getSurname(std::string &phone,
               std::pair<std::string, std::string> &answer)
{
    for (std::map<std::string, std::string>::iterator it = pBook.begin();
         it != pBook.end(); it++)
    {
        if (it->second == phone)
        {
            std::pair<int, int> newPair();
            answer = std::pair<std::string, std::string>(it->first, it->second);
            return 1;
        }
    }
    return -2;
}

bool validateLetter(char letter)
{
    int cLower = 65, cUpper = 90,
        nLower = 90, nUpper = 122;
    int code = (int)letter;
    std::cout << "letter: " << letter << std::endl;
    return (code >= cLower && code <= cUpper) ||
           (code >= nLower && code <= nUpper);
}

bool validateDigit(char digit)
{
    int lower = 48, upper = 57;
    // todo SEMAPHORE
    std::cout << "digit: " << digit << " " << (int)digit << std::endl
              << (((int)digit >= lower && (int)digit <= upper) || (digit = '-'))
              << std::endl;
    return (((int)digit >= lower && (int)digit <= upper) ||
            (digit = '-'));
}

int parseReqAndWrite(std::string &request,
                     std::pair<std::string, std::string> &answer,
                     std::pair<std::string,
                               std::vector<std::string>> &multiAnswer)
{
    std::string phone = "", surname = "";
    int i = 0;
    if (validateDigit(request[i]))
    {
        std::cout << "digit on start" << std::endl; // todo SEMAPHORE
        while (request[i] != ' ' && request[i] != '\0')
        {
            if (validateDigit(request[i]))
            {
                phone += request[i];
                ++i;
            }
            else
                break;
        }

        i += 1;
    }
    std::cout << "i" << i << std::endl;
    for (; i < request.length(); i++)
        if (validateLetter(request[i]))
        {
            surname += request[i];
        }
        else
            return -1;

    std::cout << "surname:      " << surname << "\n" // todo SEMAPHORE
              << std::boolalpha << "(surname == \"\")"
              << (surname == "") << "\n"
              << "phone:        " << phone << "\n"
              << "request:      " << request
              << std::endl;

    if (surname == "")
    {
        return getSurname(request, answer);
    }

    else if (phone == "")
    {
        return 2;
    }
    else
    {
        pBook.insert(std::pair<std::string, std::string>(phone, surname));
        return 3;
    }
}

int main()
{
    // std::string conditions = "Request format:"
    //                          "XX-XX-XX Surname -- добавить телефон и фамилию абонента в справочник\n"
    //                          "where 'X' -- is strictly a digit ('-' sign is also allowed)\n"
    //                          "XX-XX-XX -- узнать фамилию абонента по номеру телефона\n"
    //                          "Surname -- узнать телефон абонента по фамилии\n";

    std::map<std::string, std::string> pBook;
    std::pair<std::string, std::string> answer;
    std::pair<std::string, std::vector<std::string>> multiAnswer;
    std::string request;
    std::cout << CONDITIONS << std::endl;
    std::cout << "Enter your request: ";
    std::getline(std::cin, request);
    int aCode = parseReqAndWrite(request, answer, multiAnswer);
    std::cout << "aCode" << aCode << std::endl;
    switch (aCode)
    {
    case 4:
        std::cout << "Wrong request format." << std::endl;
        break;
    case -2:
        std::cout << "Not found." << std::endl;
        break;
    case 1:
        std::cout << "Found: "
                  << answer.first << " "
                  << answer.second
                  << std::endl;
        break;
    case 2:
        std::cout << "case 2 answer->" << std::endl;
        break;
    case 3:
        std::cout << "Entity is added to phone book." << std::endl;
        break;
    default:
        std::cout << "Unidentified error. " << aCode << std::endl;
        break;
    }

    // std::cout << request << std::endl;
    printPhoneBook();
    return 0;
}
