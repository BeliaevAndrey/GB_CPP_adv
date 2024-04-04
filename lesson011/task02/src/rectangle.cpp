#include "rectangle.h"

double Rectangle::getLengthA() { return lengthA; }
double Rectangle::getLengthB() { return lengthB; }


Rectangle::Rectangle(double inLengthA, double inLengthB) :
    lengthA(inLengthA), lengthB(inLengthB)
{
    setShapeType("Rectangle");
}

BoundingBoxDimensions Rectangle::dimensions()
{
    BoundingBoxDimensions bBox;
    bBox.bbLengthA = lengthA + 1;
    bBox.bbLengthB = lengthB + 1;
    return bBox;

}

std::string Rectangle::type()
{
    return getShapeType();
}

double Rectangle::square() {
    return lengthA * lengthB;
}
