#include "player.h"


Player::Player() {
    std::vector< Track*> playlist;
    int trackCount = 0;
    int nowPlay = -1;
    bool isPaused = false;

    std::cout << "Player is active." << std::endl;
    std::cout << menu << std::endl;

    std::cout << std::boolalpha << "isPaused: " << isPaused
        << std::endl; //todo RMS
}



bool Player::checkAlbumLoaded() {
    if (!trackCount) {
        std::cout << "First, load an album." << std::endl;
        return false;
    }
    return true;
}
void Player::play(int num) {
    std::cout << "\nTrackNo: " << num << std::endl << std::endl;
    if (isPaused) {
        isPaused = false;
        std::cout << "Continue playing" << std::endl;
        playlist[nowPlay]->printTrack();
        return;
    }
    if (!checkAlbumLoaded()) return;
    if (num < 1 || num <= trackCount) {
        std::cout << "\nPlaying:" << std::endl;
        playlist[num - 1]->printTrack();
        nowPlay = num - 1;
    }
    else std::cout << "Wrong track number" << std::endl;
}

void Player::pause() {
    if (isPaused) {
        isPaused = false;
        std::cout << "Continue playing" << std::endl;
        playlist[nowPlay]->printTrack();
    }
    if (!checkAlbumLoaded()) return;
    if (trackCount && nowPlay > -1) {
        isPaused = true;
    }
    else return;
}

void Player::next() {
    if (!checkAlbumLoaded()) return;
    if (nowPlay > -1) {
        std::srand(time(nullptr));
        int newNo = trackCount + (std::rand() % trackCount) - trackCount;
        std::cout << newNo << std::endl;
        play(newNo);
    }
    else play(1);
}

void Player::stop() {
    if (!checkAlbumLoaded()) return;
    if (isPaused) isPaused = false;

    if (nowPlay > -1) {
        nowPlay = -1;
        std::cout << "Stopped." << std::endl;
        playlist[nowPlay]->printTrack();
    }
    else return;
}
void Player::exit(bool& activeFlag) {
    if (trackCount > 0) {
        for (int i = 0; i < playlist.size(); i++)
        {
            delete playlist[i];
            playlist[i] = nullptr;
        }
    }
    std::cout << "Exiting..." << std::endl;
    activeFlag = false;
}

void Player::printPlaylist() {
    for (int i = 0; i < trackCount; i++)
    {
        std::cout << (i + 1) << ". "
            << playlist[i]->getSinger() << " "
            << playlist[i]->getTitle() << " "
            << playlist[i]->getDuration() << " "
            << playlist[i]->getAlbum() << " "
            << std::endl;
    }
}

void Player::loadPlaylist() {
    if (nowPlay > -1) nowPlay = -1;
    if (trackCount > 0) {
        for (int i = 0; i < playlist.size(); i++)
        {
            delete playlist[i];
            playlist[i] = nullptr;
        }
    }
    playlist.clear();
    loadAlbum(playlist, trackCount);
    printPlaylist();
}

