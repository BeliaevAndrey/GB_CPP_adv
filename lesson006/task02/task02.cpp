/*
Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения. В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. Сигналом окончания ввода дней рождения является “end” введённое в качестве имени. После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. Если день рождения уже был в этом году, данные о пользователе пропускаются. Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом. Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.
*/


#include <iostream>
#include <string>
#include <map>

#include <ctime>
#include <iomanip>


using namespace std;

void insertBD(map<time_t, string>store, string& name, string& bDate)
{
    std::cout << "bDate: " << bDate << std::endl;
    std::cout << "name: " << name << std::endl;
    std::cout << "SM 1: " << std::endl;

    bDate += " 00.00.00";
    std::cout << "SM 2: " << std::endl;
    const char* dt = bDate.c_str();
    std::cout << "SM 3: " << std::endl;
    std::tm* d;
    std::cout << "SM 4: " << std::endl;

    d->tm_hour = 0;
    std::cout << "SM 4.4: " << std::endl;

    d->tm_min = 0;
    std::cout << "SM 4.5: " << std::endl;

    d->tm_sec = 0;
    std::cout << "SM 5: " << std::endl;


    d->tm_year = std::stoi(bDate.substr(0, 4));
    std::cout << "SM 4.1: " << std::endl;

    d->tm_mon = std::stoi(bDate.substr(5, 7)) - 1;
    std::cout << "SM 4.2: " << std::endl;

    d->tm_mday = std::stoi(bDate.substr(8, 9));
    std::cout << "SM 4.3: " << std::endl;


    std::cout << "tm_year: " << d->tm_year << std::endl;
    std::cout << "tm_mon:  " << d->tm_mon << std::endl;
    std::cout << "tm_mday: " << d->tm_mday << std::endl;
    std::cout << "tm_hour: " << d->tm_hour << std::endl;
    std::cout << "tm_min:  " << d->tm_min << std::endl;
    std::cout << "tm_sec:  " << d->tm_sec << std::endl;

    strptime(dt, "%Y.%m.%d %H:%M:%S", d);
    std::cout << "SM 6: " << std::endl;

    std::cout << "dt: " << dt << std::endl;
    std::cout << "SM 7: \n"
        << "mktime(d): "
        << mktime(d)
        << std::endl;

    pair<time_t, string> bd = make_pair(mktime(d), name);
    store.insert(bd);
    // store[dt] = name;
    std::cout << "SM 8: " << std::endl;
}

int main()
{
    string command;
    map<time_t, string> birthdays;

    while (command != "end") {

        string name, bd;
        cout << "Input name and birthday [name YYYY.MM.DD] (\"end\" to stop): ";
        cin >> name >> bd;
        std::cout << "SM 0: " << std::endl;
        insertBD(birthdays, name, bd);

    }

    return 0;
}