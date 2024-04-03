#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle(
    double inlengthA, double inlengthB,
    double incenterX, double incenterY,
    figColor inColor)
{
    lengthA = inlengthA;
    lengthB = inlengthB;
    centerX = incenterX;
    centerY = incenterY;
    color = inColor;
    figureType = (lengthA == lengthB) ? "Square" : "Rectangle";

}

double Rectangle::area() { return lengthA * lengthB; }

Rectangle* Rectangle::tangentQuad() {
    return new Rectangle(lengthA + 0.5, lengthB + 0.5, centerX, centerY, None);
}

double Rectangle::getLengthA() { return lengthA; }

double Rectangle::getLengthB() { return lengthB; }

std::string Rectangle::printSelf() {
    std::string params = "\nThe figure: " + getFigureType() + "\n";
    params += "Center: (" +
        std::to_string(centerX) + ", " +
        std::to_string(centerY) + ")\n";
    params += "length A: " + std::to_string(lengthA) + "\n"
        "length B: " + std::to_string(lengthB) + "\n";
    params += "Color: " + getColor() + "\n";
    params += "Area: " + std::to_string(area()) + "\n\n";
    params += printTangent();
    return params;
}

std::string Rectangle::printTangent() {

    Rectangle* tQ = tangentQuad();

    std::string tngParams = "Tangential rectangle:\n\tCenter: (";
    tngParams += std::to_string(tQ->centerX) + ", ";
    tngParams += std::to_string(tQ->centerY) + ")\n";
    tngParams += "\tLength A " + std::to_string(tQ->lengthA) + "\n ";
    tngParams += "\tLength B " + std::to_string(tQ->lengthB) + "\n ";
    tngParams += "\tColor " + tQ->getColor();

    return tngParams;
}