#include "cpu.h"

void compute()
{
    int total = 0;
    int cache[BUFFER_LEN];
    read(cache);

    for (int i = 0; i < BUFFER_LEN; i++)
        total += cache[i];
    displaySum(total);
}