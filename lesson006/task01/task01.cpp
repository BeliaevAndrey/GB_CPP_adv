/*
Задание 1. Реализация программы учёта времени

Что нужно сделать

Используя функцию получения текущего времени std::time, реализуйте простейший
менеджер учёта времени. Пользователь взаимодействует с программой с помощью
команд:

*    Команда begin начинает отслеживание новой задачи. После ввода этой команды
    пользователь должен ввести название задачи, над которой он планирует сейчас
    работать. Если уже была начата какая-то другая задача, предыдущая должна быть автоматически завершена и начата новая.

*    Команда end заканчивает отслеживание текущей задачи. Если текущей начатой
    задачи нет, то команда ничего не делает.

*    Команда status выводит на экран информацию о всех законченных задачах и
    времени, которое было на них потрачено. Также выводится название текущей
    выполняемой задачи, если таковая имеется.

*    Команда exit выходит из программы.

Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в
часах, которое было затрачено.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

double duration(time_t start, time_t finish);

string begin();
void endTask();
void status();

map<string, pair<time_t, time_t>> tasks;
string current = "";

string begin()
{
    string taskName;

    cout << "Input task name: ";
    cin >> taskName;

    endTask();

    if (taskName == "exit")
        return "exit";

    time_t t = time(nullptr);

    tasks.insert(pair<string, pair<time_t, time_t>>
        (taskName, pair<time_t, time_t>(time(nullptr), 0)));

    return taskName;
}

void endTask()
{
    time_t t = time(nullptr);
    for (map<string, pair<time_t, time_t>>::iterator it = tasks.begin();
        it != tasks.end(); it++) {
        if (it->first == current) {
            it->second.second = t;
        }
    }

}

double duration(time_t start, time_t finish) {
    return difftime(finish, start) / 3600;

}

void status()
{
    if (tasks.empty()) {
        cout << "No current tasks." << endl;
        return;
    }

    for (map<string, pair<time_t, time_t>>::iterator it = tasks.begin();
        it != tasks.end(); it++) {
        cout << "Task: \"" << it->first << "\" status: " << endl;
        if (it->second.second == 0) {
            cout << "Task running. " << it->first << endl;
        }
        else {
            cout << "Finished, ";
            cout << "\t Duration: "
                << duration(it->second.first, it->second.second)
                << endl;
        }
    }
}

int main()
{
    vector<string> tasks;
    string command;
    while (command != "exit") {

        cout << "Enter command: " << endl;
        cin >> command;

        if (command == "begin") {
            current = begin();
            if (current == "exit") return 0;
            cout << "Task \"" << current << "\" added." << endl;
        }
        else if (command == "status") {
            status();
        }
        else if (command == "end") {
            endTask();
        }
        else if (command == "current") {
            cout << "Current: " << current << endl;
        }
        else if (command == "exit") {
            endTask();
            status();
        }
    }
    return 0;
}
