#include "position.h"

Position::Position(Display* d)
{
    this->d = d;
}

Position::~Position()
{
    delete d;
    d = nullptr;
}
void Position::setPosition(int x, int y, bool move)
{
   if (!move && (
        x < 0 || x > d->getWidth() ||
        y < 0 || y > d->getHeight()))
    {
        fine = false;
        return;
    }

    this->x = x;
    this->y = y;
    fine = true;
}
int Position::getX() { return x; };
int Position::getY() { return y; };
bool Position::isFine() { return fine; }
