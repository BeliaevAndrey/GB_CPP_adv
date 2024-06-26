/*
Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения. В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. Сигналом окончания ввода дней рождения является “end” введённое в качестве имени. После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. Если день рождения уже был в этом году, данные о пользователе пропускаются. Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом. Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.

Советы и рекомендации
Для подсчёта ближайшего дня используйте данные из структуры даты tm.
*/


#include <iostream>
#include <string>
#include <map>

#include <ctime>
#include <iomanip>


using namespace std;

void findClosest(map<time_t, string>& birthdays) {
    int minDelta = birthdays.begin()->first;
    time_t closest;

    /* calculate now for comparison */
    time_t now = time(nullptr);
    tm* t = localtime(&now);
    cout << "now: " << asctime(t) << endl;
    t->tm_hour = 0;
    t->tm_min = 0;
    t->tm_sec = 0;
    now = mktime(t);

    for (map<time_t, string>::iterator it = birthdays.begin();
        it != birthdays.end(); it++)
    {
        if (abs(it->first - now) == 0)
        {
            t = localtime(&birthdays.find(it->first)->first);
            cout << "Today! Birthday: \n";
            cout << put_time(t, "%M.%d") << " "
                << birthdays.find(it->first)->second << endl << endl;
        }
        else if (it->first > now && minDelta > (it->first - now))
        {
            minDelta = (it->first - now);
            closest = it->first;
        }
    }
    cout << endl;
    t = localtime(&birthdays.find(closest)->first);
    cout << "Closest Birthday:\n" << endl;
    cout << birthdays.find(closest)->second << " "
        << put_time(t, "%m.%d") << endl;


}

void insertBD(map<time_t, string>& store, string& name, string& bDate)
{
    time_t t = time(nullptr);
    tm* d = localtime(&t);

    d->tm_hour = 0;
    d->tm_min = 0;
    d->tm_sec = 0;

    d->tm_mon = stoi(bDate.substr(0, 2)) - 1;
    d->tm_mday = stoi(bDate.substr(3, 4));
    d->tm_isdst = 0; // No daylight saving

    store.insert(make_pair(mktime(d), name));
}

int main()
{
    string command;
    map<time_t, string> birthdays;

    while (command != "end")
    {
        string name, bd;
        cout << "Input name and birthday [name MM.DD] (\"end\" to stop): ";
        cin >> name;
        if (name == "end") break;
        cin >> bd;
        insertBD(birthdays, name, bd);
    }

    findClosest(birthdays);

    return 0;
}