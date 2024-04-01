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

std::string Track::getSinger() { return singer; }

std::string Track::getAlbum() { return album; }

std::tm* Track::getYear() { return releaseDate; }

std::string Track::getTitle() { return title; }

int Track::getDuration() { return duration; }

// void printTrack() {
//     std::cout << getSinger() << " "
//         << getTitle() << " "
//         << getDuration() << " "
//         << std::endl;
// }


void Track::printTrack() {
    std::cout << "Singer: " << singer << "\n\""
        << "Track: " << title << "\"\n"
        << "Duration: " << duration << " sec"
        << std::endl;
}

