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

std::string CONDITIONS = "Формат запроса:\n"
                         "XX-XX-XX Surname -- добавить телефон и фамилию абонента в справочник\n"
                         "XX-XX-XX -- узнать фамилию абонента по номеру телефона\n"
                         "Surname -- узнать телефон абонента по фамилии\n"
                         "где: 'X' -- строго цифра (допустим разделитель '-'\n"
                         "фамилия -- строго латиницей\n"
                         "\nprint book -- вывести весь сравочник\n"
                         "exit -- выход\n";

std::map<std::string, std::string> pBook;

/* Вывести на экран всю книгу */
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

/* получить список номеров по фамилии */
int getPhone(std::string &surname,
             std::vector<std::pair<std::string, std::string>> &answer)
{
    for (std::map<std::string, std::string>::iterator it = pBook.begin();
         it != pBook.end(); it++)
    {
        if (it->second == surname)
        {
            std::pair<int, int> newPair();
            answer.push_back(
                std::pair<std::string, std::string>(it->second, it->first));
        }
    }
    return answer.size() > 0 ? 2 : -2;
}

/* Получить фамилию но номеру */
int getSurname(std::string &phone,
               std::pair<std::string, std::string> &answer)
{
    for (std::map<std::string, std::string>::iterator it = pBook.begin();
         it != pBook.end(); it++)
    {
        if (it->first == phone)
        {
            std::pair<int, int> newPair();
            answer = std::pair<std::string, std::string>(it->first, it->second);
            return 1;
        }
    }
    return -2;
}

/* Валидация цифр */
bool validateLetter(char letter)
{
    int cLower = 65, cUpper = 90,
        nLower = 90, nUpper = 122;
    int code = (int)letter;
    return (code >= cLower && code <= cUpper) ||
           (code >= nLower && code <= nUpper);
}

/* Валидация букв*/
bool validateDigit(char &digit)
{
    int lower = 48, upper = 57;
    return (((int)digit >= lower && (int)digit <= upper) ||
            (digit == '-'));
}

/* Распарсить запрос и вызвать необходимую фукнцию */
int parseReqAndWrite(std::string &request,
                     std::pair<std::string, std::string> &answer,
                     std::vector<std::pair<std::string,
                                           std::string>> &multiAnswer)
{
    std::string phone = "", surname = ""; // дефолтные значения вместо флагов
    int i = 0;
    if (validateDigit(request[i]))
    {
        while (request[i] != ' ' && request[i] != '\0')
        {
            if (validateDigit(request[i]))
            {
                phone += request[i]; // конкатенация номера
                ++i;
            }
            else
                break;
        }
        i += 1; // пропустить пробел
    }

    for (; i < request.length(); i++)
        if (validateLetter(request[i]))
            surname += request[i]; // конкатенация фамилии
        else
            return -1;
    if (surname == "")
        // получить фамилию по номеру и код возврата
        return getSurname(request, answer);
    else if (phone == "")
        // получить список номеров по фамилии и код возврата
        return getPhone(request, multiAnswer);
    else
        // добавить запись в справочник
        pBook.insert(std::pair<std::string, std::string>(phone, surname));
    return 3;
}

int main()
{
    std::pair<std::string, std::string> answer;
    std::vector<std::pair<std::string, std::string>> multiAnswer;
    std::string request;
    std::cout << CONDITIONS << std::endl;
    while (true)
    {
        std::cout << "Enter your request ('exit' to exit): ";
        std::getline(std::cin, request);
        if (request == "exit")
            break;
        if (request == "print book")
            printPhoneBook();
        else
        {
            int aCode = parseReqAndWrite(request, answer, multiAnswer);
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
                std::cout << "Found: "
                          << multiAnswer.size()
                          << " entities"
                          << std::endl;
                std::cout << multiAnswer[0].first << std::endl;
                for (int i = 0; i < multiAnswer.size(); i++)
                {
                    std::cout << i + 1 << " " << multiAnswer[i].second << std::endl;
                }
                multiAnswer.clear();
                break;
            case 3:
                std::cout << "Entity is added to phone book." << std::endl;
                break;
            default:
                std::cout << "Unidentified error. " << aCode << std::endl;
                break;
            }
        }
    }

    return 0;
}
