#include <iostream>

#include "gpu.h"
#include "ram.h"

void display()
{

    for (int i = 0; i < BUFFER_LEN; i++)
    {
        std::cout << ramBuf[i] << " ";
    }

    std::cout << std::endl;
}
