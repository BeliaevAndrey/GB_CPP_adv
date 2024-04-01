#include "album.h"



void loadAlbum(std::vector<Track*>& playlist, int& trackCount)
{
    time_t t = time(nullptr);
    tm* releaseDate = localtime(&t);
    releaseDate->tm_year = 1991;
    std::string albumTitle = "Innuendo";
    std::string singer = "Queen";

    std::string tracks[12] = {
        "Innuendo", "I'm Going Slightly Mad", "Headlong",
        "I Can't Live with You", "Don't Try So Hard", "Ride the Wild Wind",
        "All God's People", "These Are the Days of Our Lives",
        "Delilah", "The Hitman", "Bijou", "The Show Must Go On" };
    int durations[12] = { 369, 242, 249, 245, 189, 241,
                        249, 242, 182, 242, 186, 244 };

    trackCount = sizeof(tracks) / sizeof(tracks[0]);

    for (int i = 0; i < trackCount; i++)
    {
        playlist.push_back(new Track(singer, albumTitle, tracks[i],
            releaseDate, durations[i]));
    }
}
