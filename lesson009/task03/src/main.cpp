/*
Задание 3. Симуляция работы компании
Что нужно сделать
Реализуйте симуляцию работы компании. В компании существует вертикальное
управление с иерархией. Есть основные рабочие, подчинённые, разбитые на
команды. У каждой команды есть менеджер среднего звена. Всей компанией
руководит глава компании. У всех сотрудников, включая руководителя, есть имена.

Глава компании выполняет стратегическое управление. Он определяет основной
вектор движения - задачи верхнего уровня. Менеджеры среднего звена разбивают
эти задачи на подзадачи и раздают их своим подчинённым. Подчинённые выполняют
работу.

Реализация данной логики должна проходить упрощённым образом. Указания главы
компании поступают из стандартного ввода и являются не более чем целочисленными
идентификаторами.
Данные идентификаторы служат зерном для генератора случайных чисел. Каждый из
менеджеров, принимая себе эту целочисленную команду, добавляет к ней свой
порядковый номер и вызывает с результирующей суммой функцию std::srand().
На основе этой суммы вычисляется общее количество задач, которое требуется
выполнить данной командой, - от 1 до количества работников в группе. Всего есть
три типа задач для работников: A, B и C. Они тоже выбираются случайно и
распределяются между незанятыми рабочими.
При старте программы пользователь указывает в стандартном вводе количество
команд и количество работников в каждой из команд.
Далее пользователь вводит целые числа, которые соответствуют указаниям
руководителя компании. Когда какой-то работник или менеджер получил указания
или задачу, об этом сообщается в стандартный вывод, включая имя работающего
сотрудника. Программа завершается, когда все работники заняты какими-то
задачами.

*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

class Task
{
private:
    int tID;
    char type;
public:
    Task(int tID, char type) {
        this->tID = tID;
        this->type = type;
    }
    int getTID() { return tID; }
    int getType() { return type; }
};

class Employee
{
private:
    int eID;
    std::string name;
    bool busy = false;
public:
    Employee(int eID, std::string& name) {
        this->eID = eID;
        this->name = name;
    }
    int getEID() { return eID; }
    std::string getName() { return name; }
    bool isBusy() { return busy; }
    void setBusy() { this->busy = true; }
};

class Worker : public Employee
{
private:
    Task* task = nullptr;
public:
    Worker(int eID, std::string name) :Employee(eID, name) {
        std::cout << name << std::endl;
    }
    ~Worker() {
        delete task;
        std::cout << "deleted worker # " << getEID() << std::endl;
    }

    Task* getTask() { return task; }
    void setTask(Task* task) {
        this->task = task;
        setBusy();
        std::cout << this->getName() << std::endl;
        std::cout << "I have the task: "
            << task->getTID()
            << " of type: "
            << (char)task->getType()
            << std::endl;
    }
};


class Manager : public Employee
{
private:
    std::vector<Worker*> workers;
    char taskTypes[3]{ 'A', 'B', 'C' };
    int groupSize = 0;
    std::map<Worker*, Task*>* tasks;
public:
    Manager(int eID, std::string name, int groupSize) :
        Employee(eID, name)
    {
        this->groupSize = groupSize;
        gatherGroup();
        std::cout << name << std::endl;
        this->tasks = new std::map<Worker*, Task*>;
    }
    ~Manager() {
        for (int i = 0; i < groupSize; i++)
        {
            delete workers[i];
        }
        std::cout << "deleted manager." << getEID() << std::endl;
    }

    void gatherGroup() {
        for (int i = 0; i < groupSize; i++)
        {
            int wID = (getEID() + (i + 1)) * 10;
            std::string name = "Worker # " + std::to_string(wID);
            workers.push_back(new Worker(wID, name));
        }
    }

    Worker* getFree() {
        for (int i = 0; i < workers.size(); i++)
        {
            if (!(workers[i]->isBusy())) return workers[i];
        }
        return nullptr;
    }

    void giveTask(int taskNo) {
        std::srand(taskNo + getEID());
        int taskAmt = (rand() % groupSize) + 1;
        for (int i = 0; i < taskAmt; i++)
        {
            Task* task = new Task(taskNo, taskTypes[taskNo % 3]);
            Worker* worker = getFree();
            if (worker != nullptr) {
                worker->setTask(task);
                tasks->insert(std::make_pair(worker, task));
            }
            else {
                setBusy();
                std::cout << getEID()
                    << " All workers busy! " << std::endl;
                return;
            }
        }
    }
    void printTaks() {
        std::cout << "Group " << getEID() << " tasks" << std::endl;
        for (
            std::map<Worker*, Task*>::iterator it = tasks->begin();
            it != tasks->end(); ++it) {
            std::cout << it->first->getName() << " " << it->second->getTID() << std::endl;
        }
    }
};

class Team
{
private:
    std::vector<Manager*>* managers = nullptr;
public:
    Team() {
        this->managers = new std::vector<Manager*>;
    }
    ~Team() {
        for (int i = 0; i < managers->size(); i++)
        {
            delete managers->at(i);
        }
    }
    void addManager(int groupNo, int groupSize) {
        int mID = groupNo * 10;
        std::string name = "Manager # " + std::to_string(mID);
        managers->push_back(new Manager(mID, name, groupSize));
    }

    Manager* getFreeGroup() {
        for (int i = 0; i < managers->size(); i++)
        {
            if (!managers->at(i)->isBusy())
                return managers->at(i);
        }
        std::cout << "All managers busy" << std::endl;
        return nullptr;
    }

    bool setTask(int taskNo) {
        Manager* m = getFreeGroup();
        if (m != nullptr) {
            m->giveTask(taskNo);
            return true;
        }
        return false;
    }
    void printTeamTasks() {
        std::cout << "Team tasks list: " << std::endl;
        for (int i = 0; i < managers->size(); i++)
            managers->at(i)->printTaks();

    }

};

int main()
{
    bool runFlag = true;
    int groupsAmt = 0;
    int groupSize = 0;
    Team* t = new Team();

    std::cout << "Input groups amount: ";
    std::cin >> groupsAmt;
    std::cout << "Input groups size: ";
    std::cin >> groupSize;

    for (int i = 0; i < groupsAmt; i++)
    {
        t->addManager(i + 1, groupSize);
    }

    while (runFlag) {
        int taskID;
        std::cout << "Input task ID: ";
        std::cin >> taskID;

        runFlag = t->setTask(taskID);
    }

    std::cout << "Everyone is busy." << std::endl;

    t->printTeamTasks();

    delete t;
    return 0;
}