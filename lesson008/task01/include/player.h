#pragma once

#include <string>
#include "track.h"
#include "album.h"

class Player {
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
