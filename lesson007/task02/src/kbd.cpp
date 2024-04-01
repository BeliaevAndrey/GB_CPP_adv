#include <string>

#include "kbd.h"

void inputNums()
{
    std::cout << "Input started..." << "\n";
    int kBuf[BUFFER_LEN];
    std::cout << "Input numbers" << std::endl;

    for (int i = 0; i < BUFFER_LEN; i++)
        std::cin >> kBuf[i];


    write(kBuf);
}

std::string readCommand()
{
    std::cout << "Input command: ";
    std::string input;
    std::cin >> input;
    std::cout << "command:" << input << std::endl;
    return input;
}
