# pragma once

#include "shape.h"

class Rectangle : virtual public Shape
{

    double lengthA;
    double lengthB;

public:

    double getLengthA();
    double getLengthB();
    Rectangle(double inLengthA, double inLengthB);
    virtual BoundingBoxDimensions dimensions() override;
    virtual std::string type()override;
    virtual double square() override;

};
