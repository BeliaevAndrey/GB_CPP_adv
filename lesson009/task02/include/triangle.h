#pragma once

#include <math.h>

#include "figure.h"
#include "rectangle.h"


class Triangle : public Figure
{
    double lengthA;
    double getHeight();

public:
    Triangle(double, double, double, figColor);

    double area();
    double getLengthA();
    Rectangle* tangentQuad();
    std::string printSelf();
    std::string printTangent();
};