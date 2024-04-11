#pragma once


#include "task.h"
#include "employee.h"

class Team
{
private:
    std::vector<Manager*>* managers = nullptr;
public:
    Team();
    ~Team();
    void addManager(int groupNo, int groupSize);

    Manager* getFreeGroup();

    bool setTask(int taskNo);

    void printTeamTasks();

};
