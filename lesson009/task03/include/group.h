#pragma once

#include "employee.h"

class Group
{
    int groupSize = 0;
    int gID = 0;
    std::vector <Employee*> employees;

protected:

    void setGID(int num);

public:
    Group(int inSize, int num);
    
    void addEmployee(Employee*);


    int getGID();

    int getSize();

    std::vector<Employee*>& getEmployees();

    std::string toString();

};
