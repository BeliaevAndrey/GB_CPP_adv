#pragma once

#include "point.h"
#include <iostream>
#include <map>

std::map<int, std::pair<Point, Point>> cuts;
int countCuts = 0;

void printCuts()
{
    std::cout << "Totally cuts: " << countCuts << std::endl;
    for (std::map<int, std::pair<Point, Point>>::iterator it = cuts.begin();
        it != cuts.end(); it++)
    {
        std::cout << "Cut # " << it->first << ": "
            << outPoint(it->second.first) << " to "
            << outPoint(it->second.second) << " to "
            << std::endl;
    }
}
int searchCut(Point& s, Point& e)
{
    for (std::map<int, std::pair<Point, Point>>::iterator it = cuts.begin();
        it != cuts.end(); it++)
    {
        if (eqPoint(it->second.first, s) && eqPoint(it->second.second, e) ||
            eqPoint(it->second.first, e) && eqPoint(it->second.second, s))
            return it->first;
    }
    return 0;
}

void scalpel(Point start, Point end)
{
    if (searchCut(start, end))
    {
        std::cout << "Such cut is already made" << std::endl;
        return;
    }
    if (eqPoint(start, end))
    {
        std::cout << "Wrong input: points are coincident!" << std::endl;
        return;
    }
    std::cout << "Cut has been made between ("
        << outPoint(start) << " and "
        << outPoint(end) << std::endl;
    cuts[++countCuts] = std::make_pair(start, end);

}

void hemostat(Point place)
{
    std::cout << "Hemostat has been applied to ("
        << place.x << ", "
        << place.y << ") "
        << std::endl;
}

void tweezers(Point place)
{
    std::cout << "Tweezers has been applied to ("
        << place.x << ", "
        << place.y << ") "
        << std::endl;

}

void suture(Point start, Point end)
{
    if (eqPoint(start, end))
    {
        std::cout << "Wrong input: points are coincident!" << std::endl;
        return;
    }
    int cutN = searchCut(start, end);
    if (cutN == 0)
    {
        std::cout << "Wrong input: such cut not found!" << std::endl;
        return;
    }

    std::cout << "Suture has been made between ("
        << outPoint(start) << " and "
        << outPoint(end) << std::endl;
    cuts.erase(cutN);
    countCuts--;
    std::cout << "Cut number " << cutN << " now sutured." << std::endl;
}