#include "triangle.h"
#include <iostream>

Triangle::Triangle(
    double incenterX, double incenterY,
    double inlengthA,
    figColor inColor)
{
    lengthA = inlengthA;
    centerX = incenterX;
    centerY = incenterY;
    color = inColor;

    std::cout << "lengthA " << lengthA
        << "\n cX " << centerX
        << "\n cY " << centerY
        << "\ninlengthA " << inlengthA << ""
        << "\nincenterX " << incenterX << ""
        << "\nincenterY " << incenterY << "\n\n";
    figureType = "Triangle";

}

double Triangle::area() { return lengthA * lengthA * std::sqrt(3) / 4; }

double Triangle::getHeight() {
    return std::sqrt(lengthA * lengthA - lengthA * lengthA / 4);
}

Rectangle* Triangle::tangentQuad() {
    double height = getHeight();
    // Поиск центра через радиус вписанной окружности (r = l * sqrt(3) / 6)
    double tQCenterY2 = centerY - (lengthA * std::sqrt(3) / 6) + height / 2;
    return new Rectangle(lengthA, height, centerX, tQCenterY2, None);
}

double Triangle::getLengthA() { return lengthA; }

std::string Triangle::printSelf() {
    std::string params = "\nThe figure: " + getFigureType() + "\n";
    params += "Center: (" +
        std::to_string(centerX) + ", " +
        std::to_string(centerY) + ")\n";
    params += "Side length: " + std::to_string(lengthA) + "\n";
    params += "Color: " + getColor() + "\n";
    params += "Area: " + std::to_string(area()) + "\n\n";
    params += printTangent();
    return params;
}

std::string Triangle::printTangent() {

    Rectangle* tQ = tangentQuad();

    std::string tngParams = "Tangential rectangle:\n\tCenter: (";
    tngParams += std::to_string(tQ->centerX) + ", ";
    tngParams += std::to_string(tQ->centerY) + ")\n";
    tngParams += "\tLength A " + std::to_string(tQ->getLengthA()) + "\n ";
    tngParams += "\tLength B " + std::to_string(tQ->getLengthB()) + "\n ";
    tngParams += "\tColor " + tQ->getColor();

    return tngParams;
}