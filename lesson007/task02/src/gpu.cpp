#include <iostream>

#include "gpu.h"
#include "commands.h"

void display()
{
    int dBuf[BUFFER_LEN]{};
    read(dBuf);
    for (int i = 0; i < BUFFER_LEN; i++)
    {
        std::cout << dBuf[i] << " ";
    }
    std::cout << std::endl;
}

void displaySum(int& total)
{
    std::cout << total << std::endl;
}

void menu()
{
    std::cout << "Commands:\n"
        << SUM << "\n"
        << SAVE << "\n"
        << LOAD << "\n"
        << INPUT << "\n"
        << DISPLAY << "\n"
        << EXIT << "\n"
        << std::endl;
}