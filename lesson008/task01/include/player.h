#pragma once

#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "track.h"
#include "album.h"

class Player {

    std::string menu = "1. play\n"
        "2. pause\n"
        "3. next\n"
        "4. stop\n"
        "5. load playlist\n"
        "6. print playlist\n"
        "7. exit";
    std::vector<Track*> playlist;
    int trackCount;
    int nowPlay;
    bool isPaused = false;
    bool checkAlbumLoaded();

public:
    Player();

    void play(int);                 // 1
    void pause();                   // 2
    void next();                    // 3
    void stop();                    // 4
    void exit(bool&);               // 5
    void printPlaylist();           // 6
    void loadPlaylist();            // 7

};