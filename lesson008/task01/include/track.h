#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

class Track
{

    time_t t = time(nullptr);
    std::string singer = "";
    std::string title = "";
    std::string album = "";
    std::tm* releaseDate = localtime(&t);
    int duration = 0;

public:
    Track(
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

    void printTrack() {
        std::cout << getSinger() << " "
            << getTitle() << " "
            << getDuration() << " "
            << std::endl;
    }
    
    // void setSinger(std::string  value) { singer = value; }
    // void setAlbum(std::string  value) { album = value; }
    // void setYear(std::tm* value) { releaseDate = value; }
    // void setTitle(std::string  value) { title = value; }
    // void setDuration(int value) { duration = value; }
};