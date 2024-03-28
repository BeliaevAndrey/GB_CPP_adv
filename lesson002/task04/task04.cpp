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

void printATM()
{
    std::ifstream atm(pathATM);
    while (!atm.eof())
    {
        int tmp;
        atm >> tmp;
        std::cout << tmp;
    }
}

void readATM(int charge[])
{
    std::ifstream atm(pathATM, std::ios::binary);
    int banknote, position = 0;
    if (atm.is_open())
    {
        atm.read((char *)charge, capacity);
        atm.close();
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            charge[i] = 0;
        }
    }
}

void writeATM(int recharge[])
{
    std::ofstream atm(pathATM, std::ios::binary);
    for (int i = 0; i < capacity; i++)
    {
        atm << recharge[i] << std::endl;
    }

    atm.close();
}

void fillUp()
{
    int charge[capacity];
    readATM(charge);

    // todo RMS

    std::cout << "fillup reads...\n " << std::endl;
    for (int k = 0; k < capacity; k++)
    {
        if (charge[k] % 100)
            std::cout << k << " " << charge[k] << " ";
    }
    std::cout << "CONTINUE?: ";
    int ff;
    std::cin >> ff;
    // todo end

    for (int i = 0; i < capacity; i++)
    {
        if (charge[i] == 0)
        {
            charge[i] = nominals[std::rand() % 5];
        }
    }

    writeATM(charge);
}


int main()
{
    std::srand(std::time(nullptr));
    char command = '0';
    int charge[capacity];

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
                // std::cout << "deducing..." << deduce(amount) << std::endl;
                readATM(charge);
                int count = 0;
                for (int i = sizeof(nominals) - 1; i >= 0; i--)
                {
                    int banknote = nominals[i];
                    for (int j = 0; j < capacity; j++)
                    {
                        if (banknote == charge[j])
                        {
                            if (banknote <= amount)
                            {
                                count += banknote;
                                charge[j] = 0;
                                if (count == amount)
                                {
                                    std::cout << "You get: " << count << std::endl;
                                    writeATM(charge);
                                    return 0;
                                }
                            }
                        }
                    }
                }
                std::cout << "Not enough appropriate banknotes." << std::endl;
                return 1;
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