#pragma once
#include "display.h"
#include <iostream>

class Position
{
private:
    int x = 0;
    int y = 0;
    Display* d;
public:

    // Position();
    Position(int, int);
    ~Position();

    int getX();
    int getY();

};

// static Position* readData();
