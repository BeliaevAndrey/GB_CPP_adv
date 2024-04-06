#include "window.h"
#include "position.h"

Window::Window(Display* d) {
    displayPtr = d;
};
Window::~Window() {};

int Window::getPosX() { return posX; }
int Window::getPosY() { return posY; }
int Window::getSizeX() { return sizeX; }
int Window::getSizeY() { return sizeY; }

void Window::display() {
    displayPtr->draw(*this);
}

int Window::move(int x, int y) {
    if (posX + x < 0 ||
        posX + x > displayPtr->getWidth() ||
        posY + y > displayPtr->getWidth() ||
        posY + y > displayPtr->getWidth())
    {
        return 1;
    }

    posX += x;
    posY += y;

    return 0;
}

// int Window::move(Position* p) {
//     posX += p->getX();
//     posY += p->getY();

//     return 0;
// }

int Window::resize(int x, int y) {
    if (x < 0 || y < 0) return 1;
    sizeX = x;
    sizeY = y;
    return 0;
}

// int Window::resize(Position* p) {
//     sizeX = p->getX();
//     sizeY = p->getY();
//     return 0;
// }

std::string Window::close() {
    sizeX = 0;
    sizeY = 0;
    return "exit";
}