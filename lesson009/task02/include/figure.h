#pragma once

#include "colors.h"

class Figure
{
    
public:
    double centerX;
    double centerY;
    figColor color;
    std::string figureType;

    std::string getColor();
    std::string getFigureType();
};
