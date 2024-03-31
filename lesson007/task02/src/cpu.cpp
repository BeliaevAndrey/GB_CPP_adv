#include "cpu.h"


void compute() 
{
    int total = 0;
    for (int i=0; i < BUFFER_LEN; i++)
    {
        total+=ramBuf[i];
    }
}

