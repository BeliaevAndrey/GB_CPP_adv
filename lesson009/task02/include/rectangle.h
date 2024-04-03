#pragma once

#include "figure.h"


class Rectangle : public Figure
{
    double lengthA, lengthB;
    std::string figureType;

public:
    Rectangle(double, double, double,
        double, figColor);

    double area();
    double getLengthA();
    double getLengthB();
    Rectangle* tangentQuad();
    std::string printSelf();
    std::string printTangent();
};