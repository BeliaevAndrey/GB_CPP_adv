#include "circle.h"

void Circle::setRadius(double& inRadius)
{
    radius = inRadius;
}

double Circle::getRadius() {return radius; }

Circle::Circle(double inRadius)
{
    setRadius(inRadius);
    setShapeType("Circle");
}

BoundingBoxDimensions Circle::dimensions()
{
    BoundingBoxDimensions bBox;
    bBox.bbLengthA = radius * 2 + 1;
    bBox.bbLengthB = bBox.bbLengthA;
    return bBox;

}

std::string Circle::type()
{
    return getShapeType();
}
double Circle::square() {
    return std::atan(1) * getRadius() * 4;
}
