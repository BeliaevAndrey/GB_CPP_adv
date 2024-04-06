#pragma once

#include <iostream>

class Window; // предварительное объявление

class Display {
    int width = 80;
    int height = 50;

public:

    Display();
    ~Display();

    int getWidth();
    int getHeight();
    void draw(Window&);
};
