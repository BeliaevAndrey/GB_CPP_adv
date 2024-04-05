#include "group.h"

void Group::setGID(int num) {
    gID = groupSize + num;
}


Group::Group(int inSize, int num) {
    groupSize = inSize;
    gID = num;
}

int Group::getGID() { return gID; }

int Group::getSize() { return groupSize; }

std::vector<Employee*>& Group::getEmployees() { return employees; }

void Group::addEmployee(Employee* e) {
    employees.push_back(e);
}

std::string Group::toString() {
    std::string group = "Group: " + std::to_string(gID) += "\n";
    group += "Manager: " + employees[0]->toString() + "\n";
    for (int i = 0; i < employees.size(); i++)
    {
        group += employees[i]->toString() + "\n";
    }

    return group;
}