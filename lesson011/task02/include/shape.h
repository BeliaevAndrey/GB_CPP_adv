#pragma once

#include <string>

#include "boundingboxdimensions.h"

class Shape
{
private:
    std::string shapeType;

protected:
    void setShapeType(std::string inShapeType);
    std::string getShapeType();

public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;

};

