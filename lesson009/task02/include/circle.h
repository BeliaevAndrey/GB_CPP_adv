#pragma once

#include "figure.h"
#include "rectangle.h"


class Circle : public Figure
{
    std::string figureType = "Circle";
    double radius;

public:
    Circle();

    // double area();
    // Rectangle* tangentQuad();
    // std::string printSelf();
    // std::string printTangent();
};
