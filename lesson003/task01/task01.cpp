/*
1. Ведомость учёта
Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно
обобщить и дополнить использованием структур.

Формат ведомости прежний:
сначала - имя и фамилия получателя денег,
далее - дата выдачи в формате ДД.ММ.ГГГГ,
затем - сумма выплаты в рублях.
Данные разделяются пробелами. В конце
каждой записи должен быть перевод строки. Структура данных должна
соответствовать этому формату.
При старте программы пользователь отправляет команду: list или add.
Команда list осуществляет чтение из файла ведомости, как и прежде, только
уже в структуры данных, и отображает их на экране. Команда add добавляет
новую запись в конец ведомости.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

const std::string listPath = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson003/task01/payment_list.bin";

struct payment
{
    std::string name = "Unknown Unknownson";
    std::string date = "00.00.0000";
    int amount = 0;
};

void loadList(std::ifstream &fileIn, std::vector<payment> &payments)
{
    if (!fileIn.is_open())
        return;

    payment current;
    int count;
    fileIn.read((char *)&count, sizeof(count));
    if (count == 0)
    {
        std::cout << "0 records in file" << std::endl;
        return;
    }

    std::cout << "Loading: " << std::endl;
    for (int i = 0; i < count; i++)
    {
        int nameLen;
        std::string line;
        std::string date = "00.00.0000";
        int amount;
        fileIn.read((char *)&nameLen, sizeof(nameLen));
        line.resize(nameLen);
        fileIn.read((char *)line.c_str(), nameLen);
        current.name = line;
        fileIn.read((char *)date.c_str(), date.length());
        current.date = date;
        fileIn.read((char *)&amount, sizeof(amount));
        current.amount = amount;
        payments.push_back(current);
    }
}

void appendList(std::ofstream &fileOut, std::vector<payment> &payments)
{
    std::cout << "Writing..." << std::endl;
    int paySize = payments.size();
    fileOut.write((char *)&paySize, sizeof(paySize));

    for (int i = 0; i < payments.size(); i++)
    {

        int len = payments[i].name.size();
        fileOut.write((char *)&len, sizeof(len));
        fileOut.write((char *)payments[i].name.c_str(), len);
        fileOut.write((char *)payments[i].date.c_str(),
                      payments[i].date.length());
        fileOut.write((char *)&payments[i].amount,
                      sizeof(payments[i].amount));
    }
}

void printList(std::vector<payment> &payments)
{
    std::cout << "Current list: " << std::endl;
    for (int i = 0; i < payments.size(); i++)
    {
        std::cout << payments[i].name << " ";
        std::cout << payments[i].date << " ";
        std::cout << payments[i].amount << std::endl;
    }
}

bool readData(payment &curPayment)
{
    bool validateName(std::string);
    bool validateDate(std::string);
    bool validateNumbers(std::string, bool isDate = false);

    std::string name = "";
    std::string tmp = "";
    int amount;
    int complete = 0;

    std::cout << "Input name: ";
    std::cin >> name;
    if (validateName(name))
    {
        complete++;
        std::cout << "complete 1 " << complete << std::endl;
    }

    std::cout << "Input surname: ";
    std::cin >> tmp;
    if (validateName(tmp))
    {
        name += (" " + tmp);
        curPayment.name = name;
        complete++;
        std::cout << "complete 2 " << complete << std::endl;
    }

    std::cout << "Input date (DD.MM.YYYY): ";
    std::cin >> tmp;
    if (validateDate(tmp))
    {
        curPayment.date = tmp;
        complete++;
        std::cout << "complete 3 " << complete << std::endl;
    }

    std::cout << "Input amount: ";
    std::cin >> tmp;
    if (validateNumbers(tmp))
    {
        curPayment.amount = std::stoi(tmp);
        complete++;
        std::cout << "complete 4 " << complete << std::endl;
    }

    if (complete == 4)
    {
        std::cout << "complete end " << complete << std::endl;
        return true;
    }
    else
    {
        std::cout << "complete fail: " << complete << std::endl;
        std::cout << "Corrupt data. Please try again" << std::endl;
        return false;
    }
}

bool leapYear(int year)
{
    return year % 4 == 0 || year % 400 == 0 && year % 100 != 0;
}

bool validateNumbers(std::string numLine, bool isDate = false)
{
    std::cout << "Validating numbers" << std::endl;

    bool flag = false;
    int countDots = 0;

    // if (isDate && numLine.size() < 10)
    // {
    //     std::cout << "Date string is too short." << std::endl;
    //     return false;
    // }

    for (int i = 0; i < numLine.size(); i++)
    {
        std::cout << numLine[i] << std::endl;
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
            /* ASCII codes: '0' = 48; '9' = 57 */
            if ((int)numLine[i] >= 48 && (int)numLine[i] <= 57)
            {
                std::cout << "right "
                          << numLine[i]
                          << (int)numLine[i]
                          << std::endl;

                flag = true;
            }
            else
            {
                std::cout << "wrong? "
                          << numLine[i]
                          << (int)numLine[i]
                          << std::endl;
                flag = false;
            }
        }
    }
    return flag;
}

bool validateDate(std::string date)
{
    std::cout << "Validating date" << std::endl;
    bool validateNumbers(std::string, bool);
    bool leapYear(int);

    if (date.length() < 10)
    {
        std::cout << "Date string is too short." << std::endl;
        return false;
    }

    if (!validateNumbers(date, true))
    {
        std::cout << "numbers invalid "
                  << std::endl;

        return false;
    }

    int months31[] = {1, 3, 5, 7, 8, 10, 12};

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 5));
    int year = std::stoi(date.substr(6, 9));

    if (day < 1 || year < 1970 || month < 1 || month > 12)
        return false;

    if (month == 2)
    {
        if (leapYear(year) && day <= 29)
        {
            return true;
        }
        else
        {
            std::cout << "wrong?"
                      << day << " "
                      << "(day <= 28) " << (day <= 28)
                      << std::endl;

            return day <= 28;
        }
    }
    else
    {
        for (int i = 0; i < sizeof(months31); i++)
            if (months31[i] == month)
                return day <= 31;
    }
    return day <= 30;
}

bool validateName(std::string name)
{
    std::cout << "Validating name" << std::endl;

    int upperLettersA = 65; // capitals ASCII
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
        std::cout << "First letter must be capital."
                  << std::endl;
        return false;
    }
    return true;
}

int main()
{
    std::string command = "0";

    while (command != "exit")
    {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "list")
        {
            std::ifstream fileIn(listPath, std::ios::binary);
            std::vector<payment> payments;

            loadList(fileIn, payments);
            printList(payments);

            fileIn.close();
        }
        else if (command == "add")
        {
            std::ifstream fileIn(listPath, std::ios::binary);
            std::vector<payment> payments;
            loadList(fileIn, payments);
            fileIn.close();
            printList(payments);

            payment currentPayment;
            if (readData(currentPayment))
            {
                std::ofstream fileOut(listPath, std::ios::binary);
                payments.push_back(currentPayment);
                appendList(fileOut, payments);
                fileOut.close();
            }
        }
        else if (command == "exit")
        {
            std::cout << "Exiting..." << std::endl;
        }
        else
        {
            std::cout << "Command not recognized." << std::endl;
        }
    }

    return 0;
}