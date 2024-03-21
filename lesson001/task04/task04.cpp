/*
Задание 4. Разработка детектора PNG-файла

Что нужно сделать
Разработайте программу, которая получает на вход, в стандартный ввод, путь к
файлу. На выходе программа должна определить, является ли данный файл
PNG-изображением. Данная процедура не просто должна смотреть на расширение
файла, но и произвести минимальный анализ его внутренностей, в бинарном режиме.
Внутренности валидного бинарного файла начинаются со специального 8-байтового
заголовка. Нас будут интересовать первые четыре байта. Первый байт всегда имеет
значение −119 (число со знаком минус), а следующие — это просто символы ‘P’,
‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в
верхнем регистре. По результатам проверки пути и внутренностей требуется
сообщить пользователю о результате проверки в стандартный вывод.

Советы и рекомендации
Чтобы определить расширение файла, используйте функцию substr, которая получает
офсет и длину подстроки и возвращает её.
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filepath;

    std::ifstream pngFile;

    std::cout << "Input filename with path: ";
    std::cin >> filepath;
    char buffer[4];
    int check = 0;

    if (filepath.substr(filepath.size() - 3) != "png" &&
        filepath.substr(filepath.size() - 3) != "PNG")
    {
        std::cout << "Wrong extension. Must be 'png'. "
                  << std::endl;
    }
    else
    {
        pngFile.open(filepath, std::ios::binary);

        if (!pngFile.is_open())
        {
            std::cout << "Something went wrong. Please check file path/name"
                      << std::endl;
            return 1;
        }
        else
        {
            pngFile.read(buffer, sizeof(buffer));
            buffer[4] = 0;

            check += (buffer[0] == (char)-119);
            check += (buffer[1] == 'P');
            check += (buffer[2] == 'N');
            check += (buffer[3] == 'G');

            if (check == 4)
                std::cout << "Yes, it's a png-file"
                          << std::endl;
            else
                std::cout << "Header check has not passed."
                          << std::endl;

            pngFile.close();
        }
    }

    return 0;
}