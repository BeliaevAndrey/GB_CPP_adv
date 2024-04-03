#pragma once

#include <math.h>
// #include "figure.h"

class Circle : public Figure
{
// public:
//     double square;
//     fColor color;
//     double centerX;
//     double centerY;
    double radius = 0;

public:
    double square(){
        return atan(1) / 4 * radius;
    }

    

};
