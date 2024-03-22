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
    void wrteFile(char[]);
    bool validateDate(std::string);
    bool validatePayment(std::string);
    std::string record;

    std::string tmp = "";

    while (tmp != "-2")
    {

        std::cout << "Input date (YYYY.MM.DD): ";
        std::cin >> tmp;
        if (tmp != "-2")
            std::cout << "validate date: " << validateDate(tmp) << std::endl;
    }
    return 0;
}

void writeFile(char record[])
{
    std::ofstream file;
    file.open(path, std::ios::binary);
    file.write(record, sizeof(*record));
}

bool validateDate(std::string date)
{
    bool validateNumbers(std::string, bool);

    if (!validateNumbers(date, true))
    {
        std::cout << "1st" << std::endl;
        return false;
    }
    bool leapYear(int);

    int months31[] = {1, 3, 5, 7, 8, 10, 12};

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 6));
    int day = std::stoi(date.substr(8, 9));

    if (day < 1 || year < 1970 || month < 1 || month > 12)
    {
        std::cout << "2nd" << std::endl;
        return false;
    }

    if (month == 2)
    {
        if (leapYear(year) && day <= 29)
        {
            std::cout << "3rd" << std::endl;
            return true;
        }
        else
        {
            std::cout << "4th" << std::endl;
            return day <= 28;
        }
    }
    else
    {
        for (int i = 0; i < sizeof(months31); i++)
        {
            if (months31[i] == month)
            {
                std::cout << "5th" << std::endl;
                return day <= 31;
            }
        }
    }
    std::cout << "5th" << std::endl;
    return day <= 30;
}

bool validateNumbers(std::string numLine, bool isDate = false)
{
    std::cout << "isDate: " << isDate << std::endl;
    int countDots = 0;
    /* codes for 0, 1, 2, 3, 4, 6, 8, 9*/
    int nums[] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};

    for (int i = 0; i < numLine.size(); i++)
    {
        std::cout << "num validator " << numLine[i] << std::endl;
        for (int i = 0; i < sizeof(nums); i++)
        {
            if (numLine[i] == '.')
            {
                countDots++;
                if (isDate && countDots > 2 || !isDate && countDots > 1)
                    return false;
            }
            if (nums[i] == (int)numLine[i] || numLine[i] == '.')
                continue;
            else
            {
                // todo RMS
                std::cout << "\n"
                          << "nums: "
                          << nums[i]
                          << " (int)numLine[i]: "
                          << (int)numLine[i]
                          << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool leapYear(int year)
{
    return year % 4 == 0 || year % 400 == 0 && year % 100 != 0;
}