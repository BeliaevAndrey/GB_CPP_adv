#pragma once

#include <cmath>

#include "shape.h"

class Circle : virtual public Shape
{

    double radius;
    void setRadius(double& inRadius);
    double getRadius();

public:
    Circle(double inRadius);
    virtual BoundingBoxDimensions dimensions() override;
    virtual std::string type() override;
    virtual double square() override;
  
};
