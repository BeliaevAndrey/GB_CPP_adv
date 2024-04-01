#pragma once

#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

class Track
{

    time_t t;
    std::string singer;
    std::string title;
    std::string album;
    std::tm* releaseDate;
    int duration;

    bool checkAlbumLoaded();
    
public:
    Track(std::string, std::string, std::string, tm*, int);

    std::string getSinger();
    std::string getAlbum();
    std::tm* getYear();
    std::string getTitle();

    int getDuration();

    void printTrack();

};