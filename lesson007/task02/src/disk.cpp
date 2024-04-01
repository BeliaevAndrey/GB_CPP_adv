#include "disk.h"
#include <fstream>

void save()
{
    std::ofstream file_out(PATH);
    int diskBuf[BUFFER_LEN];
    read(diskBuf);
    for (int i = 0; i < BUFFER_LEN; i++)
        file_out << diskBuf[i] << std::endl;

}

void load()
{
    std::ifstream file_in(PATH);
    int tmp[BUFFER_LEN]{};
    for (int i = 0; i < BUFFER_LEN; i++)
        file_in >> tmp[i];
    write(tmp);
}
