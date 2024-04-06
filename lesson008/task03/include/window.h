#pragma once

#include "display.h"
#include "position.h"

class Window
{
private:
    int sizeX = 10;
    int sizeY = 10;
    int posX = 10;
    int posY = 10;
    Display* displayPtr;

public:
    Window(Display*);
    ~Window();

    int getPosX();
    int getPosY();
    int getSizeX();
    int getSizeY();

    int move(int, int);
    int resize(int, int);

    int move(Position*);
    int resize(Position*);

    void display();
    std::string close();

};
