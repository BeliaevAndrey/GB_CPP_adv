#pragma once
#include <string>

const double eps = 0.01;
struct Point
{
    double x;
    double y;
};

Point addPoint(double& x, double& y)
{
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

bool eqPoint(Point& l, Point& r)
{
    return abs(l.x - r.x) <= eps && abs(l.y - r.y) <= eps;
}

std::string outPoint(Point p)
{

    return "(" + std::to_string(p.x) +
        ", " + std::to_string(p.y) + ")";
}