/*
Задание 2. Регистратура
Что нужно сделать
Напишите программу «Регистратура». На вход программе приходят строки с
фамилиями или строка Next. Пришедшие люди становятся в очередь, а по запросу
Next необходимо вызвать в регистратуру человека с фамилией, идущей первой в
__лексикографическом порядке__ (по алфавиту), и вывести его фамилию на экран.
Фамилии пациентов могут повторяться. Каждый запрос (на добавление и вывод)
должен работать за O(logn).

Пример:
← Sidorov
← Ivanov
← Ivanov
← Petrov
← Next
→ Ivanov
← Next
→ Ivanov
← Next
→ Petrov
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

void nextPatient(map<string, int> &queue)
{
    if (queue.empty())
    {
        cout << "Nobody is waiting." << endl;
        return;
    }

    if (queue.begin()->second == 1)
    {
        cout << queue.begin()->first << endl;
        queue.erase(queue.begin());
    }
    else
    {
        queue.begin()->second -= 1;
        cout << queue.begin()->first << endl;
    }
}

void appendQueue(map<string, int> &queue, string &surname)
{
    if (queue.count(surname) == 0)
    {
        queue.insert(make_pair(surname, 1));
    }
    else
    {
        map<string, int>::iterator it = queue.begin();
        queue.find(surname)->second += 1;
    }
}

int main()
{
    string command;
    map<string, int> queue;

    while (true)
    {
        cout << "Input surname of command (Next) or 'exit' to exit: ";
        cin >> command;
        if (command == "exit" || command == "Exit")
        {
            cout << "Exiting..." << endl;
            break;
        }
        if (command == "Next" || command == "next")
        {
            nextPatient(queue);
        }
        else
            appendQueue(queue, command);
    }

    return 0;
}