#include "track.h"

class Track
{
private:
    std::string singer = "Queen";
    std::string album = "Innuendo";
    int year = 1991;
    std::string totalDuration = "53:45";

    std::string tracks[12]{
        "Innuendo", "I'm Going Slightly Mad", "Headlong",
        "I Can't Live with You", "Don't Try So Hard", "Ride the Wild Wind",
        "All God's People", "These Are the Days of Our Lives",
        "Delilah", "The Hitman", "Bijou", "The Show Must Go On" };
    std::string durations[12]{
        "6:29","4:22", "4:39", "4:35", "3:39", "4:41",
        "4:19", "4:12", "3:32", "4:52", "3:36","4:24" };
        
public:
    std::string getSinger() { return singer; }
    std::string getAlbum() { return album; }
    std::string getTotalDuration() { return totalDuration; }
    int getYear() { return year; }

    std::string getTrack(int num) {
        return tracks[num];
    }

    std::string getDuration(int num) {
        return durations[num];
    }
};
