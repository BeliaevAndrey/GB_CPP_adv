#pragma once
#include "display.h"
#include <iostream>

class Position
{
private:
    int x = 0;
    int y = 0;
    bool fine = false;
    Display* d;
public:
    bool isOk = true;

    Position(Display*);
    ~Position();

    void setPosition(int, int, bool);
    int getX();
    int getY();
    bool isFine();

};
