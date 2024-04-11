#include "employee.h"

Employee::Employee(int eID, std::string& name) {
    this->eID = eID;
    this->name = name;
}
int Employee::getEID() { return eID; }

std::string Employee::getName() { return name; }

bool Employee::isBusy() { return busy; }

void Employee::setBusy() { this->busy = true; }


Worker::Worker(int eID, std::string name) :Employee(eID, name) {
    std::cout << name << std::endl;
}
Worker::~Worker() {
    delete task;
}

Task* Worker::getTask() { return task; }

void Worker::setTask(Task* task) {
    this->task = task;
    setBusy();
    std::cout << this->getName() << std::endl;
    std::cout << "I have the task: "
        << task->getTID()
        << " of type: "
        << (char)task->getType()
        << std::endl;
}


Manager::Manager(int eID, std::string name, int groupSize) :
    Employee(eID, name)
{
    this->groupSize = groupSize;

    gatherGroup();

    std::cout << name << std::endl;

    this->tasks = new std::map<Worker*, Task*>;
}
Manager::~Manager() {
    for (int i = 0; i < groupSize; i++)
    {
        delete workers[i];
    }
}

void Manager::gatherGroup() {
    for (int i = 0; i < groupSize; i++)
    {
        int wID = (getEID() + (i + 1)) * 10;
        std::string name = "Worker # " + std::to_string(wID);
        workers.push_back(new Worker(wID, name));
    }
}

Worker* Manager::getFree() {
    for (int i = 0; i < workers.size(); i++)
    {
        if (!(workers[i]->isBusy())) return workers[i];
    }
    return nullptr;
}

void Manager::giveTask(int taskNo) {
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
void Manager::printTaks() {
    std::cout << "Group " << getEID() << " tasks" << std::endl;
    for (
        std::map<Worker*, Task*>::iterator it = tasks->begin();
        it != tasks->end(); ++it) {
        std::cout << it->first->getName() << " " << it->second->getTID() << std::endl;
    }
}
