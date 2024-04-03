#include "circle.h"
#include <math.h>

Circle::Circle(double inCenterX, double inCenterY,
    double inRadius, figColor inColor)
{
    centerX = inCenterX;
    centerY = inCenterY;
    color = inColor;
    radius = inRadius;
    figureType = "Circle";
}

double Circle::area() { return atan(1) * 4 * radius; }

/* Tangential quadrilateral*/
Rectangle* Circle::tangentQuad() {
    return new Rectangle(
        radius * 2, radius * 2,
        centerX, centerY, None);
}

std::string Circle::printSelf() {
    std::string params = "\nThe figure: " + getFigureType() + "\n";
    params += "Center: (" +
        std::to_string(centerX) + ", " +
        std::to_string(centerY) + ")\n";
    params += "radius: " + std::to_string(radius) + "\n";
    params += "Color: " + getColor() + "\n";
    params += "area: " + std::to_string(area()) + "\n\n";
    params += printTangent();

    return params;
}

std::string Circle::printTangent() {

    Rectangle* tQ = tangentQuad();

    std::string tngParams = "Tangential rectangle:\n\tCenter: (";
    tngParams += std::to_string(tQ->centerX) + ", ";
    tngParams += std::to_string(tQ->centerY) + ")\n";
    tngParams += "\tLength A " + std::to_string(tQ->getLengthA()) + "\n ";
    tngParams += "\tLength B " + std::to_string(tQ->getLengthB()) + "\n ";
    tngParams += "\tColor " + std::to_string(tQ->color);

    return tngParams;
}