/*
Задание 2. Реализация рисования случайных картин
Что нужно сделать
С помощью генератора случайных чисел рисуется картинка из нулей и единиц. На
вход от пользователя принимается размер картины: высота и ширина в пикселях. На
выходе нужно создать файл pic.txt, содержимое которого будет наполнено
случайными нулями и единицами в рамках размера картины. Это ещё не всё. Если вы
запустите программу несколько раз на одних и тех же исходных данных (ширина и
высота картины), вы очень скоро обнаружите, что всё время выводится одна и та
же картинка. Дело в том, что у генератора случайных чисел есть ещё и «зерно»,
от которого он отталкивается. Если это зерно не меняется, то и серия из rand()
всегда будет возвращать одни и те же случайные числа. Чтобы разнообразить
вывод, вы можете использовать вызов std::srand(std::time(nullptr)); в самом
начале программы. Эта операция задаёт начальное зерно случайных чисел в
зависимости от текущего времени. Для её корректной работы не забудьте также
включить заголовочный файл <ctime>.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(nullptr));

    int width, height;
    std::string filename;

    std::cout << "Input width and height: ";
    std::cin >> width >> height;

    std::cout << "Input filename: ";
    std::cin >> filename;

    std::ofstream picture("lesson002/task02/" + filename + ".txt");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            picture << std::rand() % 2;
        }
        picture << std::endl;
    }

    picture.close();

    return 0;
}