#pragma once

#include <map>
#include <string>

#include "team.h"
#include "employee.h"
#include "group.h"
#include "task.h"

class Manager : public Employee
{
    char taskTypes[3] = { 'A', 'B', 'C' };
    std::map<int, Task*> groupTasks;
    Group* group;
    Team* team;

public:

    Manager(int gID, Team* t, Group* g);

    int generateTask(int tID);

    int giveTask(Task* task);
};
