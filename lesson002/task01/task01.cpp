/*
Задание 1. Реализация записи в ведомость учёта
Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать простую программу записи в эту ведомость. Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки. При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в текстовом режиме. Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.

Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью. Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным диапазоном символов в дате. К примеру, вызов std::stoi(date.substr (3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.
*/

#include <iostream>
#include <fstream>
#include <string>

std::string path = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson002/task01/payment_list.txt";

int main()
{
    void writeFile(std::string);
    bool validateDate(std::string);
    bool validateNumbers(std::string, bool isDate = false);
    bool validateName(std::string);

    bool flag = true;

    while (flag)
    {
        std::string record;
        std::string tmp = "";
        int complete = 0;

        std::cout << "Input Name: ";
        std::cin >> tmp;
        // std::cout << "validate name: " << validateName(tmp) << std::endl;
        if (validateName(tmp))
        {
            record += tmp + " ";
            complete++;
        }
        std::cout << "Input Surname: ";
        std::cin >> tmp;
        // std::cout << "validate surname: " << validateName(tmp) << std::endl;
        if (validateName(tmp))
        {
            record += tmp + " ";
            complete++;
        }

        std::cout << "Input date (YYYY.MM.DD): ";
        std::cin >> tmp;
        // std::cout << "validate date: " << validateDate(tmp) << std::endl;
        if (validateDate(tmp))
        {
            record += tmp + " ";
            complete++;
        }
        else
            std::cout << "Incorrect date." << std::endl;

        std::cout << "Input amount: ";
        std::cin >> tmp;

        if (validateNumbers(tmp))
        {
            record += tmp + "\n";
            complete++;
        }
        else
            std::cout << "Incorrect amount." << std::endl;

        if (complete == 5)
            writeFile(record);
        else
            std::cout << "The record is corrupt."
                      << " Please try again."
                      << std::endl;

        std::cout << "Proceed to next record (Y/n)? ";
        std::cin >> tmp;
        if (tmp == "n" || tmp == "N")
            flag = false;
    }

    return 0;
}

void writeFile(std::string record)
{
    std::ofstream file;
    file.open(path, std::ios::app);
    std::cout << "Recording: " << record << std::endl;
    file << record;
    file.close();
}

bool validateDate(std::string date)
{
    bool validateNumbers(std::string, bool);

    if (!validateNumbers(date, true))
        return false;

    bool leapYear(int);

    int months31[] = {1, 3, 5, 7, 8, 10, 12};

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 6));
    int day = std::stoi(date.substr(8, 9));

    if (day < 1 || year < 1970 || month < 1 || month > 12)
        return false;

    if (month == 2)
    {
        if (leapYear(year) && day <= 29)
            return true;
        else
            return day <= 28;
    }
    else
    {
        for (int i = 0; i < sizeof(months31); i++)
            if (months31[i] == month)
                return day <= 31;
    }
    return day <= 30;
}

bool validateNumbers(std::string numLine, bool isDate = false)
{
    bool flag = false;
    int countDots = 0;

    if (isDate && numLine.size() < 10)
    {
        std::cout << "Date string is too short." << std::endl;
        return false;
    }

    for (int i = 0; i < numLine.size(); i++)
    {
        if (numLine[i] == '.')
        {
            countDots++;
            if (isDate && countDots > 2 || !isDate && countDots > 1)
            {
                std::cout << "Too many dots." << std::endl;
                return false;
            }
        }
        else
        {
            /* ASCII codes: 'A' = 48; 'Z' = 57 */
            if ((int)numLine[i] >= 48 && (int)numLine[i] <= 57)
                flag = true;
            else
                flag = false;
        }
    }
    return flag;
}

bool leapYear(int year)
{
    return year % 4 == 0 || year % 400 == 0 && year % 100 != 0;
}

bool validateName(std::string name)
{
    int upperLettersA = 65;
    int upperLettersZ = 90;

    bool validateNumbers(std::string, bool isDate = false);

    if (validateNumbers(name))
    {
        std::cout << "Name/surname should not contain numbers."
                  << std::endl;
        return false;
    }
    if ((int)name[0] < upperLettersA || (int)name[0] > 90)
    {
        std::cout << "Filrst letter must be capital."
                  << std::endl;
        return false;
    }
    return true;
}
