#include <iostream>

#include "display.h"
#include "window.h"


Display::Display() {
    
};
Display::~Display() {};

int Display::getWidth() { return width; };
int Display::getHeight() { return height; };

void Display::draw(Window& w) {
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (w.getPosY() > row ||
                w.getPosX() > col ||
                row > w.getPosY() + w.getSizeY() ||
                col > w.getPosX() + w.getSizeX())
                std::cout << '0';
            else std::cout << '1';
        }
        std::cout << std::endl;
    }
}