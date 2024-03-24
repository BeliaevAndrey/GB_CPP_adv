/* DRAFT */
/*
Задание 4. Реализация симуляции банкомата

Что нужно сделать
Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут
храниться только бумажные купюры номиналом от 100 до 5000 рублей. Максимально в
банкомате может храниться только 1000 купюр. Все они записываются в отдельный
файл. У банкомата, как у устройства, две основных операции — снятие денег
пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится
символ плюс “+”. Количество купюр рассчитывается так, чтобы банкомат был
заполнен полностью. Все купюры при этом выбираются случайным образом.

Если на старте программы в консоль вводится минус (“-”), то симулируется снятие
пользователем денег. Пользователь указывает сумму с точностью до 100 рублей. Мы
будем считать, что каждый клиент обладает неограниченным балансом в системе и
теоретически может снять любую сумму. На практике, если данная сумма не может
быть снята из-за отсутствия подходящих денег в машине, показывается сообщение,
что эта операция невозможна. После выполнения любой из операций программа
завершает выполнение. Состояние банкомата должно храниться в отдельном бинарном
файле, автономно.

Советы и рекомендации
Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

const std::string pathATM = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson002/task04/atm.txt";
int nominals[] = {100, 500, 1000, 2000, 5000};
const int capacity = 1000;

void parintATM()
{
    std::ifstream atm(pathATM);
    while (!atm.eof())
    {
        int tmp;
        atm >> tmp;
        std::cout << tmp;
    }
}

void check(std::vector<int> &charge)
{
    std::ifstream atm(pathATM);
    int banknote, position = 0;
    if (atm.good())
        while (!atm.eof())
        {
            // atm.seekg(position);
            atm >> banknote;
            std::cout << banknote << " -> " << position++ << std::endl;
            charge.push_back(banknote);
            // position += atm.gcount();
        }

    atm.close();
}

void writeATM(std::vector<int> &recharge)
{
    std::ofstream atm(pathATM);
    for (int i = 0; i < recharge.size(); i++)
    {
        atm << recharge[i] << std::endl;
    }

    atm.close();
}

void fillUp()
{
    std::vector<int> charge;
    check(charge);
    if (!charge.size())
    {
        for (int i = 0; i < capacity; i++)
        {
            charge.push_back(nominals[std::rand() % 5]);
        }
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if (charge[i] == 0)
                charge[i] = nominals[std::rand() % 5];
        }
    }
    writeATM(charge);
}

void searchAndGet(int setOfNominals[], int amtOfNominals[], int &amount)
{
    std::vector<int> total;
    int count = 0;
    check(total);
    std::cout << "search and get" << std::endl; // todo RMS
    // for (int i = 0; i < sizeof(nominals) / sizeof(nominals[0]); i++)
    // {
    //     std::cout << i << " "
    //               << "amtOfNominals[i] ";
    //     std::cout << i << " " << amtOfNominals[i];
    //     std::cout << i << " "
    //               << " setOfNominals[i] ";
    //     std::cout << i << " " << setOfNominals[i] << std::endl;
    // }
    for (int i = 0; i < sizeof(nominals) / sizeof(nominals[0]); i++)
    {
        while (amtOfNominals[i])
        {
            std::cout << "amtOfNominals[i] "
                      << amtOfNominals[i]
                      << std::endl; // todo RMS
            for (int i = 0; i < total.size(); i++)
            {
                if (total[i] == setOfNominals[i])
                {
                    std::cout << total[i] << " = " << setOfNominals[i] << std::endl;
                    amtOfNominals[i]--;
                    count += total[i];
                    total[i] = 0;
                }
            }
        }
    }
    for (int i = 0; i < sizeof(nominals); i++)
    {
        if (setOfNominals[i])
            std::cout << "Not enough nominals in atm." << std::endl;
    }
    if (count == amount)
    {
        std::cout << "You are getting: " << count << std::endl;
    }
    else
        std::cout << "Something went wrong: " << count << std::endl;
}

void deduce(int &amount)
{
    std::cout << "deduce 1" << std::endl; // todo RMS
    // std::vector<int> total;
    int setOfNominals[] = {0, 0, 0, 0, 0};
    int amtOfNominals[] = {0, 0, 0, 0, 0};
    int count = 0, index = 0;
    // check(total);
    while (count != amount)
    {
        for (int i = 0; i < sizeof(nominals); i++)
        {
            if (nominals[i] == amount)
            {
                setOfNominals[i] = nominals[i];
                amtOfNominals[i] = 1;
                count += nominals[i];
            }
        }
        // todo RMS
        std::cout << "count" << count << " amount " << amount << std::endl;
        int index = sizeof(nominals) - 1;
        while (count < amount)
        {
            for (; index >= 0; index--)
            {
                if (nominals[index] < (amount - count))
                {
                    amtOfNominals[index] = (amount - count) / nominals[index];
                    count += amtOfNominals[index] * nominals[index];
                }
            }
            if (count + nominals[index - 1] > amount)
                --index;
            if (!index && count < amount)
            {
                std::cout << "Unable to change the amount." << std::endl;
                break;
            }
        }
    }
    searchAndGet(setOfNominals, amtOfNominals, amount);
}

int main()
{
    std::srand(std::time(nullptr));
    char command = '0';

    while (command != 'e')
    {
        if (command == '+')
            fillUp();
        else if (command == '-')
        {
            int amount = 0;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            if (amount > 0 && !(amount % 100))
            {
                deduce(amount);
            }
            else
                std::cout << "Amount must be more than 0"
                          << " and to be a multiply of 100."
                          << " Try again, please"
                          << std::endl;
        }

        std::cout << "Input command "
                  << "('+' -- fill ATM, '-' -- deduce, 'e' -- exit): ";
        std::cin >> command;
    }

    return 0;
}