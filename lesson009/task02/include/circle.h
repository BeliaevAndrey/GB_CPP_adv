#pragma once

#include "figure.h"
#include "rectangle.h"


class Circle : public Figure
{
    double radius;

public:

    Circle(double, double, double, figColor);

    double area();
    Rectangle* tangentQuad();
    std::string printSelf();
    std::string printTangent();
};
