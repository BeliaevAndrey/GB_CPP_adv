#include "figure.h"

std::string Figure::getColor() {
    switch (color)
    {
    case red:
        return "purple";
        break;
    case green:
        return "purple";
        break;
    case blue:
        return "purple";
        break;
    case purple:
        return "purple";
        break;

    default:
        return "None";
        break;
    }
}
