#include <employee.h>

void Employee::setEID(int eID) { this->eID = eID; }
void Employee::setName(std::string* name) { this->name = *name; }
void Employee::setBusy() { busy = true; }

Employee::Employee() {}

Employee::Employee(int gID)
{
    this->eID = gID * 100 + eID;
    this->gID = gID;
    this->name += " - " + eID;
}

int Employee::putTask(Task* task) {
    this->task = *task;
    busy = true;
    return eID;
}

int Employee::getGID() { return gID; }

bool Employee::isBusy() { return busy; }

std::string Employee::toString() {
    std::string introduce = "id: " + eID;
    introduce += " Name: " + name;
    return introduce;
}
