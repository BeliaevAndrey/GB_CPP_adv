#include "ram.h"




void write(int bufferIn[])
{
    for (int i = 0; i < BUFFER_LEN; i++)
    {
        ramBuf[i] = bufferIn[i];
    }

}

void read(int bufferOut[])
{
    for (int i = 0; i < BUFFER_LEN; i++)
    {
        bufferOut[i] = ramBuf[i];
    }
}
