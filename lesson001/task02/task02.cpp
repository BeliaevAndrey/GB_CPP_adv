/*
Задание 2. Разработка просмотрщика текстовых файлов
Что нужно сделать
Разработайте простейший просмотрщик текстовых файлов. В начале программы
пользователь вводит путь к текстовому файлу, который требуется открыть и
просмотреть. Внутренности файла необходимо вывести в стандартный вывод.
Программа должна работать для любых текстовых файлов в формате TXT, но вы
можете создать и свой отдельный файл для теста. Главное, чтобы файл был
англоязычным, дабы избежать проблем с кодировками.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::string path;
    std::ifstream source;
    char buffer[80];
    int position = 0;

    std::cout << "Input filename with path: ";
    std::cin >> path;
    // path = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson001/task02/words.txt";

    source.open(path, std::ios::binary);
    if (source.is_open())
    {
        while (!source.eof())
        {
            char symbol;

            source.seekg(position);

            source >> symbol;
            source.read(buffer, sizeof(buffer));

            position += source.gcount();

            for (int i = 0; i < sizeof(buffer); i++)
            {
                std::cout << buffer[i];
                buffer[i] = 0;
            }
        }
        std::cout << std::endl
                  << std::endl;

        source.close();
    }
    else
        std::cout << "Something went wrong, please check path/filename."
                  << std::endl;

    return 0;
}
