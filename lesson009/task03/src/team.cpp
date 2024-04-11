#include "team.h"
#include "task.h"
#include "employee.h"

Team::Team() {
    this->managers = new std::vector<Manager*>;
}
Team::~Team() {
    for (int i = 0; i < managers->size(); i++)
    {
        delete managers->at(i);
    }
}
void Team::addManager(int groupNo, int groupSize) {
    int mID = groupNo * 10;
    std::string name = "Manager # " + std::to_string(mID);
    managers->push_back(new Manager(mID, name, groupSize));
}

Manager* Team::getFreeGroup() {
    for (int i = 0; i < managers->size(); i++)
    {
        if (!managers->at(i)->isBusy())
            return managers->at(i);
    }
    std::cout << "All managers busy" << std::endl;
    return nullptr;
}

bool Team::setTask(int taskNo) {
    Manager* m = getFreeGroup();
    if (m != nullptr) {
        m->giveTask(taskNo);
        return true;
    }
    return false;
}
void Team::printTeamTasks() {
    std::cout << "Team tasks list: " << std::endl;
    for (int i = 0; i < managers->size(); i++)
        managers->at(i)->printTaks();

}
