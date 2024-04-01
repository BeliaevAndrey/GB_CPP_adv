#include "track.h"


time_t t = time(nullptr);
std::string singer = "";
std::string title = "";
std::string album = "";
std::tm* releaseDate = localtime(&t);
int duration = 0;

Track::Track(
    std::string singerIn, std::string albumIn,
    std::string titleIn, tm* releaseDateIn, int durationIn) {
    singer = singerIn;
    album = albumIn;
    title = titleIn;
    releaseDate = releaseDateIn;
    duration = durationIn;

}

std::string getSinger() { return singer; }

std::string getAlbum() { return album; }

std::tm* getYear() { return releaseDate; }

std::string getTitle() { return title; }

int getDuration() { return duration; }

// void printTrack() {
//     std::cout << getSinger() << " "
//         << getTitle() << " "
//         << getDuration() << " "
//         << std::endl;
// }


void printTrack() {
    std::cout << singer << " "
        << title << " "
        << duration << " "
        << std::endl;
}

