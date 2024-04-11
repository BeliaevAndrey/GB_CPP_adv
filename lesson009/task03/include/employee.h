#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "task.h"

class Employee
{
private:
    int eID;
    std::string name;
    bool busy = false;
public:
    Employee(int eID, std::string& name);
    int getEID();
    std::string getName();
    bool isBusy();
    void setBusy();
};

class Worker : public Employee
{
private:
    Task* task = nullptr;
public:
    Worker(int, std::string);
    ~Worker();

    Task* getTask();
    void setTask(Task*);
};


class Manager : public Employee
{
private:
    std::vector<Worker*> workers;
    char taskTypes[3]{ 'A', 'B', 'C' };
    int groupSize = 0;
    std::map<Worker*, Task*>* tasks;
public:
    Manager(int eID, std::string name, int groupSize);
    ~Manager();

    Worker* getFree();
    
    void gatherGroup();
    void giveTask(int taskNo);
    void printTaks();
};
