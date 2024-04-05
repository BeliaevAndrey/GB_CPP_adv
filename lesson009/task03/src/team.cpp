#include "team.h"
#include "employee.h"
#include "manager.h"


Team::Team() {

}

Group* Team::getGroup(int gID) {
    for (int i = 0; i < groups.size(); i++)
    {
        if (groups[i]->getGID() == gID) return groups[i];
    }
    return nullptr;
}

void Team::addGroup(Group* g) {
    groups.push_back(g);
}

void Team::gatherTeam() {
    int groupsAmount, groupSize;
    std::cout << "Input amount of groups: ";
    std::cin >> groupsAmount;
    std::cout << "Input group size: ";
    std::cin >> groupSize;
    for (int i = 0; i < groupsAmount; i++)
    {
        int groupID = groupSize % groupsAmount * 100 + i + 1;
        Group* g = new Group(groupSize, groupID);
        g->addEmployee(new Manager(groupID, this, g));
        for (int j = 1; j < groupSize; i++)
        {
            g->addEmployee(new Employee(groupID));
        }

    }
}

void Team::printTeam() {
    for (int i=0; i < this->groups.size(); i++)
    {
        
        std::cout << groups[i]->toString();
    }
}
