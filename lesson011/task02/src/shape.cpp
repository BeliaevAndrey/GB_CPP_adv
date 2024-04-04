#include "shape.h"

void Shape::setShapeType(std::string inShapeType)
{
    shapeType = inShapeType;
}

std::string Shape::getShapeType() {
    return shapeType;
}

