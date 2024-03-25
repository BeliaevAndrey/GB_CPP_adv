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

const std::string listPath = "payment_list.txt";

struct payment
{
    std::string name = "Unknown Unknownson";
    std::string date = "00.00.0000";
    int payment = 0;
};

void loadList(std::ifstream &file, payment)
{
    int dateLen = 10;
    int nameLen;
}

void appendList()
{
}

int main()
{
    std::string command = "0";
    std::vector<payment> payments;
    while (command != "exit")
    {
        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "list")
        {
            std::ofstream fileOut(listPath, std::ios::binary);

            fileOut.close();
        }
        else if (command == "add")
        {
            std::ofstream fileOut(listPath, std::ios::binary);

            fileOut.close();
        }
        else if (command == "exit")
        {
            std::cout << "Exiting" << std::endl;
        }
        else
        {
            std::cout << "Command not recognized." << std::endl;
        }
    }

    return 0;
}