#pragma once

#include <vector>
#include <iostream>
#include <string>

#include "group.h"


class Team {

    int tSize = 0;
    std::vector<Group*> groups;


public:
    void addGroup(Group*);
    
    Team();

    Group* getGroup(int gID);

    void gatherTeam();

    void printTeam();

};