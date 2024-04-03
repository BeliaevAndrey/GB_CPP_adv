#pragma once

enum fColor {
    None, red, green, blue, purple
};

class Figure {
public:
    double square;
    fColor color;
    double centerX;
    double centerY;

    double square(){};
};
