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
#include <vector>
#include <map>


/* класс задача */
class Task
{
    int tID = 0;
    char tType;
public:

    Task() {};

    Task(char tType, int tID) {
        this->tType = tType;
        this->tID = tID;
    }

    std::string toString() {
        std::string taskData = "Type: ";
        taskData += tType + " Task id:" + std::to_string(tID);
        return taskData;
    }
};

/* Базовый класс "служащий" */
class Employee
{
    int eID = 0;
    int gID = 0;
    std::string name;
    bool busy = false;  // работник занят/свободен (группа, если менеджер)
    Task* task;
protected:

    void setEID(int eID) { this->eID = eID; }
    void setGID(int gID) { this->gID = gID; }
    void setName(std::string* name) { this->name = *name; }
    void setBusy() { this->busy = true; };

    int getEID() { return this->eID; }
    std::string getName() { return name; }

public:
    ~Employee() {   // деструктор
        delete task;
        task = nullptr;
    }

    int putTask(Task* task) {
        this->task = task;
        busy = true;
        return eID;
    }

    virtual void giveTask();


    int getGID() { return gID; }

    bool isBusy() { return busy; }

    std::string toString() {
        std::string introduce = "id: " + std::to_string(eID);
        introduce += " Name: " + name;
        introduce += isBusy() ? this->task->toString() : " Free\n";

        return introduce;
    }




};


/*  Служащий - Работник */
class Worker : public Employee
{
public:
    Worker(int gID, int eID)
    {
        setEID(gID * 100 + eID);
        setGID(gID);
        std::string name = "Worker #" + std::to_string(eID);
        setName(&name);
    }

};

/* класс группа */
class Group
{
    int groupSize = 0;
    int gID = 0;    // идентификатор группы
    std::vector <Employee*> employees;

protected:


    void setGID(int num) {
        gID = groupSize + num;
    }


public:

    Group(int inSize, int num) {

        groupSize = inSize;
        gID = num;
    }
    ~Group() {
        for (int i = 0; i < employees.size(); i++)
        {
            delete employees[i];
            employees[i] = nullptr;
        }
    }

    int getGID() { return gID; }
    int getSize() { return groupSize; }

    std::vector<Employee*>& getEmployees() { return employees; }

    void addEmployee(Employee* e) {
        employees.push_back(e);
    }
    std::string toString() {
        std::string group = "Group: " + std::to_string(gID) += "\n";
        group += "Manager: " + employees[0]->toString();
        for (int i = 1; i < employees.size(); i++)
        {
            group += "Worker:  " + employees[i]->toString();
        }
        return group + "\n";
    }
};

/* Класс команда */
class Team {

    int tSize = 0;
    std::vector<Group*> groups;


public:
    ~Team() { // деструктор
        for (int i = 0; i < groups.size(); i++)
        {
            delete groups[i];
            groups[i] = nullptr;
        }
    }

    Group* getGroup(int gID) {
        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i]->getGID() == gID) return groups[i];
        }
        return nullptr;
    }

    void addGroup(Group* g) {

        groups.push_back(g);
    }


    void printTeam() {
        std::cout << "The Team are: " << std::endl;

        for (int i = 0; i < this->groups.size(); i++)
        {
            std::cout << groups[i]->toString();
        }
        std::cout << std::endl;
    }

    bool anyFree() {
        for (int i = 0; i < groups.size(); i++)
        {
            if (!groups[i]->getEmployees()[0]->isBusy())
                return true;
        }
        return false;
    }

    Employee* getFreeTeam() {
        for (int i = 0; i < groups.size(); i++)
        {
            Employee* manager = groups[i]->getEmployees()[0];
            if (!manager->isBusy())
                return manager;
        }
        return nullptr;
    }

    void gatherTeam();
    std::vector<Employee*> getManagers();

};

/* Служащий - менеджер */
class Manager : public Employee
{
    char taskTypes[3] = { 'A', 'B', 'C' };
    std::map<int, Task*> groupTasks;
    Group* group;
    Team* team;

public:

    Manager(int gID, Team* t, Group* g)
    {

        this->setEID(gID * 100);
        std::string mName = "Manager #" + std::to_string(gID);
        this->setName(&mName);
        this->team = t;
        this->group = g;
    }

    int generateTask(int tID) {
        std::srand(tID);
        Task* task = new Task(taskTypes[rand() % 3], tID);
        int eID = giveTask(task);
        if (eID == 0) {
            setBusy();  // Работники в группе заняты
            return 0;   // Задача НЕ поставлна
        }

        groupTasks.insert(std::make_pair(eID, task));
        return eID;     // задача поставлена работнику с id = eID
    }

    int giveTask(Task* task)
    {
        for (int i = 0; i < group->getSize(); i++)
        {
            Employee* e = group->getEmployees()[i];
            if (!e->isBusy())   // Назначить задачу если не занят
                return e->putTask(task);
        }
        return 0;       // все работники заняты, задача не поставлена.
    }

};

/*
Вынесено для соблюдения последовательности наследования.
Manager должен попасть в команду, до того как будет
скомпилирован этот метод.
*/
void Team::gatherTeam() {

    int groupsAmount = 0, groupSize = 0;
    while (groupsAmount < 1)
    {
        std::cout << "Input amount of groups: ";
        std::cin >> groupsAmount;
        if (groupsAmount < 1)
            std::cout << "Amount of groups can't be lesser than 1."
            << std::endl;
    }

    while (groupSize < 2)
    {
        std::cout << "Input group size: ";
        std::cin >> groupSize;
        if (groupSize < 2)
            std::cout << "Group size can't be lesser than 2." << std::endl;
    }

    for (int i = 0; i < groupsAmount; i++)
    {
        int groupID = groupSize % groupsAmount * 100 + i + 1;
        Group* g = new Group(groupSize, groupID);
        g->addEmployee(new Manager(groupID, this, g));
        for (int j = 1; j < groupSize; j++)
        {
            g->addEmployee(new Worker(groupID, j));
        }

        addGroup(g);
    }
}

std::vector<Employee*> Team::getManagers() {


}



int main(int argc, char const* argv[])
{
    std::cout << "Start..." << std::endl;

    Team* t = new Team();
    t->gatherTeam();

    while (t->anyFree()) {
        int task;
        std::cout << "Input task number: ";
        std::cin >> task;
    }

    // t->printTeam();

    return 0;

}
