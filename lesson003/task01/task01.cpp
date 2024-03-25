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

void loadList(std::vector<payment> payments)
{
    int count = 0;
    std::ifstream fileIn(listPath, std::ios::binary);

    if (fileIn.is_open())
    {
        // if (fileIn.end)
        //     return;
        while (!fileIn.eof())
        {
            // int dateLen = 10;
            int nameLen;
            fileIn.read((char *)&nameLen, sizeof(nameLen));
            std::cout << "Loading name... nameLen: " << nameLen << std::endl;
            std::cout << "nameLen "
                      << nameLen
                      << " dateLen "
                      /*<< dateLen*/
                      << std::endl;

            fileIn.read((char *)payments[count].name.c_str(),
                        nameLen);

            std::cout << "Loading date... dateLen: "
                      << sizeof(payments[count].date)
                      << std::endl;

            fileIn.read((char *)payments[count].date.c_str(),
                        sizeof(payments[count].date));

            std::cout << "Loading amount... " << std::endl;

            fileIn.read((char *)&payments[count].amount,
                        sizeof(payments[count].amount));

            ++count;
        }
    }

    fileIn.close();
}

void appendList(std::ofstream &fileOut, std::vector<payment> payments)
{
    for (int i = 0; i < payments.size(); i++)
    {
        // char zz = '\0';
        int nameLen = payments[i].name.length();
        int amountLen = sizeof(payments[i].amount);
        int dateLen = sizeof(payments[i].date);
        std::cout << "nameLen "
                  << nameLen
                  << " amountLen "
                  << amountLen << std::endl
                  << " dateLen "
                  << dateLen << std::endl;
        // std::cin >> zz;

        fileOut.write((char *)&nameLen,
                      payments[i].name.length());

        fileOut.write((char *)payments[i].name.c_str(),
                      nameLen);

        fileOut.write((char *)payments[i].date.c_str(),
                      sizeof(payments[i].date));

        fileOut.write((char *)&payments[i].amount,
                      sizeof(payments[i].amount));
    }
}

payment readData()
{
    void printLine(payment &);
    payment curPayment;
    std::string name = "";
    std::string tmp = "";
    int amount;

    std::cout << "Input name: ";
    std::cin >> name;
    std::cout << "Input surname: ";
    std::cin >> tmp;
    name += (" " + tmp);
    curPayment.name = name;

    std::cout << "Input date: ";
    std::cin >> tmp;
    curPayment.date = tmp;
    std::cout << "Input amount: ";
    std::cin >> tmp;
    curPayment.amount = std::stoi(tmp);

    printLine(curPayment);

    return curPayment;
}

void printLine(payment &listLine)
{
    std::cout << listLine.name << " "
              << listLine.date << " "
              << listLine.amount << std::endl;
}

void printList(std::vector<payment> payments)
{
    std::cout << "Currently in list:" << std::endl;
    for (int i = 0; i < payments.size(); i++)
    {
        std::cout << payments[i].name << " "
                  << payments[i].date << " "
                  << payments[i].amount << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::string command = "0";

    // while (command != "exit")
    // {
    std::cout << "Input command: ";
    std::cin >> command;
    if (command == "list")
    {
        std::vector<payment> payments;
        loadList(payments);
        printList(payments);
    }
    else if (command == "add")
    {
        std::vector<payment> payments;
        // loadList(payments);
        printList(payments);
        std::ofstream fileOut(listPath, std::ios::binary);
        payments.push_back(readData());
        appendList(fileOut, payments);
        fileOut.close();
    }
    else if (command == "exit")
    {
        std::cout << "Exiting..." << std::endl;
    }
    else
    {
        std::cout << "Command not recognized." << std::endl;
    }
    // }

    return 0;
}