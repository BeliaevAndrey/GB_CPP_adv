#include "player.h"

std::string menu = "1. play\n"
"2. pause\n"
"3. next\n"
"4. stop\n"
"5. exit\n"
"6. load playlist\n"
"7. print playlist";


Track* playlist;
int trackCount = 0;
int nowPlay = -1;
bool isPaused = false;


bool checkAlbumLoaded() {
    if (!trackCount) {
        std::cout << "First, load an album." << std::endl;
        return false;
    }
    return true;
}

Player::Player() {
    std::cout << "Player is active." << std::endl;
    std::cout << menu << std::endl;
}
void play(int num) {
    if (isPaused) {
        isPaused = false;
        std::cout << "Continue playing" << std::endl;
        playlist[nowPlay].printTrack();
    }
    if (!checkAlbumLoaded()) return;
    if (num < trackCount) {
        std::cout << "Playing:\n"
            << std::endl;
        playlist[num].printTrack();
        nowPlay = num;
    }
    else std::cout << "Wrong track number" << std::endl;
}

void pause() {
    if (isPaused) {
        isPaused = false;
        std::cout << "Continue playing" << std::endl;
        playlist[nowPlay].printTrack();
    }
    if (!checkAlbumLoaded()) return;
    if (trackCount && nowPlay > -1) {
        isPaused = true;
    }
    else play(0);
}

void next() {
    if (!checkAlbumLoaded()) return;
    if (nowPlay > -1) {
        play(nowPlay + 1);
    }
    else play(0);
}

void stop() {
    if (!checkAlbumLoaded()) return;
    if (isPaused) isPaused = false;

    if (nowPlay > -1) {
        nowPlay = -1;
        std::cout << "Stopped." << std::endl;
        playlist[nowPlay].printTrack();
    }
    else return;
}
void exit(bool& activeFlag) {
    if (checkAlbumLoaded()) {
        delete playlist;
        playlist = nullptr;
    }
    activeFlag = false;
}

void printPlaylist() {
    for (int i = 0; i < trackCount; i++)
    {
        std::cout << i << ". "
            << playlist[i].getSinger() << " "
            << playlist[i].getTitle() << " "
            << playlist[i].getDuration() << " "
            << playlist[i].getAlbum() << " "
            << std::endl;
    }
}

void loadPlaylist() {
    if (checkAlbumLoaded()) {
        delete playlist;
        playlist = nullptr;
    }
    playlist = loadAlbum();
}

