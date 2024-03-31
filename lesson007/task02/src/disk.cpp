#include "disk.h"
#include "ram.h"
#include <fstream>

void save()
{
    std::ofstream file_out(PATH);

    for (int i = 0; i < BUFFER_LEN; i++)
        file_out << ramBuf[i];

}

void load()
{
    std::ifstream file_in(PATH);

    for (int i = 0; i < BUFFER_LEN; i++)
        file_in >> ramBuf[i];

}
