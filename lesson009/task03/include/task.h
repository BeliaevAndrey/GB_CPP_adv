#pragma once

class Task
{
private:
    int tID;
    char type;
public:
    Task(int tID, char type) {
        this->tID = tID;
        this->type = type;
    }
    int getTID() { return tID; }
    int getType() { return type; }
};
