#include <task.h>

Task::Task() {}

Task::Task(char tType, int tID) {
    this->tType = tType;
    this->tID = tID;
}