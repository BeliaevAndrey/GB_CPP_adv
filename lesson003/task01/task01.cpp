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
    payment current;
    int count;
    fileIn.read((char *)&count, sizeof(count));

    std::cout << "Loading: " << std::endl;
    for (int i = 0; i < count; i++)
    {
        int nameLen;
        std::string line; // = "stub";
        std::string date = "00.00.0000";
        fileIn.read((char *)&nameLen, sizeof(nameLen));
        line.resize(nameLen);
        fileIn.read((char *)line.c_str(), nameLen);
        std::cout << nameLen << " " << line << std::endl;
        current.name = line;
        fileIn.read((char *)date.c_str(), date.length());
        std::cout << nameLen << " " << date << std::endl;
        current.date = date;
        payments.push_back(current);
    }
}

void appendList(std::ofstream &fileOut, std::vector<payment> &payments)
{
    std::cout << "Writing..." << std::endl;
    std::cout << "payments.size()" << payments.size() << std::endl;
    int paySize = payments.size();
    fileOut.write((char *)&paySize, sizeof(paySize));

    for (int i = 0; i < payments.size(); i++)
    {
        // std::string name = "rec" +
        //                      std::to_string(std::rand() % 1000 + 500);
        int len = payments[i].name.size();
        std::cout << len << " " << std::endl;
        fileOut.write((char *)&len, sizeof(len));
        fileOut.write((char *)payments[i].name.c_str(), len);
        fileOut.write((char *)payments[i].date.c_str(),
                      payments[i].date.length());
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

payment readData()
{
    // void printLine(payment &);
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

    // printLine(curPayment);

    return curPayment;
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
        std::ifstream fileIn(listPath, std::ios::binary);
        std::vector<payment> payments;

        loadList(fileIn, payments);
        printList(payments);

        fileIn.close();
    }
    else if (command == "add")
    {
        std::vector<payment> payments;
        // loadList(payments);
        // printList(payments);
        std::ofstream fileOut(listPath);
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