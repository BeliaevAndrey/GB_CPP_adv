#pragma once

#include <cmath>

#include "shape.h"

class Triangle : virtual public Shape
{
    double lengthA;
    double lengthB;
    double lengthC;

    double getPerimeter();
    double getHeight();

public:

    Triangle(double inLengthA, double inLengthB, double inLengthC);
    virtual BoundingBoxDimensions dimensions() override;
    virtual std::string type() override;
    virtual double square() override;

};
