#pragma once

#include <string>
#include "task.h"
#include "team.h"
#include "group.h"


class Employee
{
    int eID = 0;
    int gID = 0;
    std::string name = "Worker #";
    bool busy = false;
    Task task;
protected:

    void setEID(int eID);
    void setName(std::string* name);
    void setBusy();

public:
    Employee();

    Employee(int gID)
    {
        this->eID = gID * 100 + eID;
        this->gID = gID;
        this->name += " - " + eID;
    }

    int putTask(Task* task);

    int getGID();

    bool isBusy();

    std::string toString();

};