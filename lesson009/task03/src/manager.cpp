#include <manager.h>


Manager::Manager(int gID, Team* t, Group* g)
{
    this->setEID(gID);
    std::string mName = "Manager # - " + gID;
    this->setName(&mName);
    this->team = t;
    this->group = g;
}

int Manager::generateTask(int tID) {
    std::srand(tID);
    Task* task = new Task(taskTypes[rand() % 3], tID);
    int eID = giveTask(task);
    if (eID == 0) {
        setBusy();
        return 0;
    }

    groupTasks.insert(std::make_pair(eID, task));
    return eID;
}

int Manager::giveTask(Task* task) {
    for (int i = 0; i < group->getSize(); i++)
    {
        Employee* e = group->getEmployees()[i];
        if (!e->isBusy())
            return e->putTask(task);
    }
    return 0;
}