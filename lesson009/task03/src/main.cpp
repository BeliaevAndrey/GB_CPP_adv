#include <iostream>
#include <vector>
#include <map>

class Task
{
    int tID = 0;
    char tType;
public:
    Task() {};
    Task(char tType, int tID) {
        this->tType = tType;
        this->tID = tID;
    }
};

class Employee
{
    int eID = 0;
    int gID = 0;
    std::string name = "Worker #";
    bool busy = false;
    Task task;
protected:

    void setEID(int eID) { this->eID = eID; }
    void setGID(int gID) { this->gID = gID; }
    void setName(std::string name) { this->name = name; }
    void setBusy() { this->busy = true; };

    int getEID() { return this->eID; }
    std::string getName() { return name; }

public:


    int putTask(Task* task) {
        this->task = *task;
        busy = true;
        return eID;
    }

    int getGID() { return gID; }

    bool isBusy() { return busy; }

    std::string toString() {
        std::string introduce = "id: " + std::to_string(eID);
        introduce += " Name: " + name + "\n";
        return introduce;
    }


};

class Worker : public Employee
{
public:
    Worker(int gID, int eID)
    {
        setEID(gID * 100 + eID);
        setGID(gID);
        std::string name = "Worker #" + std::to_string(eID);
        setName(name);
    }

};

class Group
{
    int groupSize = 0;
    int gID = 0;
    std::vector <Employee*> employees;

protected:


    void setGID(int num) {
        gID = groupSize + num;
    }


public:

    Group(int inSize, int num) {
 
        groupSize = inSize;
        gID = num;
    }

    int getGID() { return gID; }

    int getSize() { return groupSize; }

    std::vector<Employee*>& getEmployees() { return employees; }

    void addEmployee(Employee* e) {
 
        employees.push_back(e);
    }

    std::string toString() {
        std::string group = "Group: " + std::to_string(gID) += "\n";
        group += "Manager: " + employees[0]->toString() + "\n";
        for (int i = 0; i < employees.size(); i++)
        {
            group += employees[i]->toString() + "\n";
        }

        return group;
    }
};

class Team {

    int tSize = 0;
    std::vector<Group*> groups;


public:
    Group* getGroup(int gID) {
        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i]->getGID() == gID) return groups[i];
        }
        return nullptr;
    }

    void addGroup(Group* g) {
 
        groups.push_back(g);
    }


    void printTeam() {
        for (int i = 0; i < this->groups.size(); i++)
        {
            std::cout << "The Team are: " << std::endl;
            std::cout << groups[i]->toString();
        }
    }
    void gatherTeam();

};

class Manager : public Employee
{
    char taskTypes[3] = { 'A', 'B', 'C' };
    std::map<int, Task*> groupTasks;
    Group* group;
    Team* team;

public:

    Manager(int gID, Team* t, Group* g)
    {

        this->setEID(gID * 100);
        std::string mName = "Manager #" + std::to_string(gID);
        this->setName(mName);
        this->team = t;
        this->group = g;

    }

    int generateTask(int tID) {
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

    int giveTask(Task* task) {
        for (int i = 0; i < group->getSize(); i++)
        {
            Employee* e = group->getEmployees()[i];
            if (!e->isBusy())
                return e->putTask(task);
        }
        return 0;
    }

};




void Team::gatherTeam() {
 
    int groupsAmount = 0, groupSize = 0;
    while (groupsAmount < 1)
    {
        std::cout << "Input amount of groups: ";
        std::cin >> groupsAmount;
        if (groupsAmount < 1)
            std::cout << "Amount of groups can't be lesser than 1."
            << std::endl;
    }

    while (groupSize < 2)
    {
        std::cout << "Input group size: ";
        std::cin >> groupSize;
        if (groupSize < 2)
            std::cout << "Group size can't be lesser than 2." << std::endl;
    }

    for (int i = 0; i < groupsAmount; i++)
    {
        int groupID = groupSize % groupsAmount * 100 + i + 1;
        Group* g = new Group(groupSize, groupID);
        g->addEmployee(new Manager(groupID, this, g));
        for (int j = 1; j < groupSize; j++)
        {
            g->addEmployee(new Worker(groupID, j));
        }
        std::cout << std::endl;
        addGroup(g);
    }
}



/*=================================== 80 =====================================*/
int main(int argc, char const* argv[])
{
    std::cout << "Start..." << std::endl;

    Team* t = new Team();
    t->gatherTeam();
    t->printTeam();

    return 0;
// for f in team group employee manager task; do touch include/$f.h; done
// for f in team group employee manager task; do touch src/$f.cpp; done
// for f in team group employee manager task; do echo "#pragma once" >> include/$f.h; done
// for f in Team Group Employee Manager Task; do echo "#include <$f.h>" >> src/$f.cpp; done

}
