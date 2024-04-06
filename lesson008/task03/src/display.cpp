#include <iostream>

#include "display.h"
#include "window.h"


Display::Display() {

};
Display::~Display() {};

int Display::getWidth() { return width; };
int Display::getHeight() { return height; };

void Display::draw(Window& w) {
    std::cout << "\n\n";
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if (w.getPosY() > row ||
                w.getPosX() > col ||
                row > w.getPosY() + w.getSizeY() - 1 ||
                col > w.getPosX() + w.getSizeX() - 1)
                std::cout << '0';
            else std::cout << '1';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}