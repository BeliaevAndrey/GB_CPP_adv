#include "position.h"

// Position::Position(){};
Position::Position(int x, int y)
{
    if (x < 0 || x > d->getWidth() ||
        y < 0 || y > d->getHeight())
        return;

    this->x = x;
    this->y = y;
}

Position::~Position()
{
    delete d;
    d = nullptr;
}

int Position::getX() { return x; };
int Position::getY() { return y; };

// static Position* readData() {
//     Position* p = nullptr;
//     int x, y;
//     std::cout << "Input coordinates (x y): ";
//     std::cin >> x >> y;
//     p = new Position(x, y);
//     while (!p)
//     {
//         std::cout << "Wrong coordinates. Try again (x y): ";
//         std::cin >> x >> y;
//     };
//     return p;
// }
