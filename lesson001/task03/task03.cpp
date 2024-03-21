/*
Задание 3. Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:

имя и фамилия человека;
количество денег, которые были выплачены лицу;
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с максимальной суммой выплат.

Пример данных ведомости:
Tom Hanks, 35500, 10.11.2020
Rebecca Williams, 85000, 1.1.2021
Sally Field, 15600, 15.8.2021
Michael Humphreys, 29400, 23.5.2020
Harold Herthum, 74300, 9.6.2019
George Kelly, 45000, 12.3.2018
Bob Penny, 12500, 13.5.2020
John Randall, 23400, 2.10.2020
Sam Anderson, 6500, 15.7.2020
Margo Moorer, 12350, 24.2.2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::string path = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson001/task03/payment_list.txt";

    std::string tmp; // временная переменная
    std::vector<std::string> names, dates;
    int count = 0,       // счётчик (индекс)
        maxPayIndex = 0, // индекс максимального платежа
        cursorPos = 0;   // позиция курсора
    double payment, // платёж
        total = 0;  // общая сумма
    std::vector<double> amounts;

    std::ifstream source;
    source.open(path);

    while (!source.eof())
    {
        source.seekg(cursorPos);
        
        source >> tmp;
        names.push_back(tmp + " ");
        cursorPos += tmp.size() + 1;

        source >> tmp;
        names[count] += tmp;
        cursorPos += tmp.size() + 1;

        source >> tmp;
        cursorPos += tmp.size() + 1;

        payment = std::stod(tmp);

        if (amounts.size() > 0 && amounts[maxPayIndex] < payment)
        {
            maxPayIndex = count;
        }
        
        amounts.push_back(payment);
        source >> tmp;
        dates.push_back(tmp);
        cursorPos += tmp.size() + 1;
        count++;
        total += payment;
    }

    std::cout << "Total: " << total << std::endl;
    std::cout << "Maximal payment: "
              << amounts[maxPayIndex]
              << " Name: "
              << names[maxPayIndex]
              << std::endl;

    source.close();
    return 0;
}