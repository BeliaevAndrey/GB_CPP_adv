#include "circle.h"
#include <math.h>

Circle::Circle()
{
    centerX = 10; //  inCenterX;
    centerY = 10; //  inCenterY;
    color = blue; //  inColor;
    radius = 10; //  inRadius;
}

// double Circle::area() { return atan(1) * 4 * radius; }

// /* Tangential quadrilateral*/
// Rectangle* Circle::tangentQuad() {
//     return new Rectangle(
//         radius * 2 + 1, radius * 2 + 1,
//         centerX, centerY, None);
// }

// std::string Circle::printSelf() {
//     std::string params = "Center: (" +
//         std::to_string(centerX) + ", " +
//         std::to_string(centerY) + ")\n";
//     params += "radius: " + std::to_string(radius) + "\n";
//     params += "Color: " + std::to_string(color) + "\n";
//     params += "area: " + std::to_string(area()) + "\n\n";
//     params += "Tangential rectangle:\n" + tangentQuad()->printSelf();

//     return params;
// }

// std::string Circle::printTangent() {

//     Rectangle* tQ = tangentQuad();

//     std::string tngParams = "Tangent Rectangle:\n\tCenter: (";
//     tngParams += std::to_string(tQ->centerX) + ", ";
//     tngParams += std::to_string(tQ->centerY) + ")\n";
//     tngParams += "\tLength A " + std::to_string(tQ->getLengthA()) + "\n ";
//     tngParams += "\tLength B " + std::to_string(tQ->getLengthB()) + "\n ";
//     tngParams += "\tColor " + std::to_string(tQ->color);

//     return tngParams;
// }