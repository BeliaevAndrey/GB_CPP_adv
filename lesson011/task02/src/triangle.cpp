#include "triangle.h"


double Triangle::getPerimeter()
{
    return lengthA + lengthB + lengthC;
}

double Triangle::getHeight()
{
    return  2 * square() / lengthA;
}

Triangle::Triangle(double inLengthA, double inLengthB, double inLengthC) :
    lengthA(inLengthA), lengthB(inLengthB), lengthC(inLengthC)
{
    Shape::setShapeType("Rectangle");
}

BoundingBoxDimensions Triangle::dimensions()
{
    BoundingBoxDimensions bBox;
    bBox.bbLengthA = lengthA + 1;
    bBox.bbLengthB = getHeight() + 1;
    return bBox;

}

std::string Triangle::type()
{
    return getShapeType();
}

double Triangle::square() {
    double p = Triangle::getPerimeter() / 2;
    
    return std::sqrt((p * (p - lengthA) * (p - lengthB) * (p - lengthC)));
}

