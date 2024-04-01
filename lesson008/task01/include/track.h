#include <string>
#include <ctime>

struct track {
    std::string singer = "";
    std::string album = "";
    std::string name = "";
    std::tm* year;
    int duration = 0;
};