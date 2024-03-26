/* 3. Математический вектор
Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над
ним. Обе координаты вектора (x и y) должны быть вещественными числами. Начиная
работу с программой, пользователь вводит команду. Затем в зависимости от
команды пользователь вводит аргументы. Это могут быть как векторы, так и
обычные скалярные значения. Результат помещается в стандартный вывод. Это тоже
может быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:

    * сложение двух векторов - команда add;
    * вычитание двух векторов - команда subtract;
    * умножение вектора на скаляр - команда scale;
    * нахождение длины вектора - команда length;
    * нормализация вектора - команда normalize.

Советы и рекомендации
Для выбора команды используйте конструкцию вида if (operation == "add"). Тут так и напрашиваются отдельные функции для каждой операции.
*/

/*
Проверялось с помощью сайта:
https://ru.onlinemschool.com/math/assistance/vector/
*/

#include <iostream>
#include <string>
#include <cmath>

struct mVec
{
    std::string name = "empty";
    float x = 0.0F;
    float y = 0.0F;
};

void printVec(mVec &vec)
{
    std::cout << vec.name
              << "\nX: " << vec.x << " Y: " << vec.y
              << std::endl;
}

mVec add(mVec &vec1, mVec &vec2)
{
    mVec rVec;
    rVec.name = "Resulting vector";
    rVec.x = vec1.x + vec2.x;
    rVec.y = vec1.y + vec2.y;
    return rVec;
}

mVec subtract(mVec &vec1, mVec &vec2)
{
    mVec rVec;
    rVec.name = "Resulting vector";
    rVec.x = vec1.x - vec2.x;
    rVec.y = vec1.y - vec2.y;
    return rVec;
}

mVec scale(mVec &vec, float &scalar)
{
    return mVec{"Resulting vector", vec.x * scalar, vec.y * scalar};
}

float length(mVec &vec)
{
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

mVec normalize(mVec &vec)
{
    float lenVec = length(vec);
    return mVec{"Resulting vectro", vec.x / lenVec, vec.y / lenVec};
}

void getVec(mVec &vec)
{
    std::cout << "Input vector name: ";
    std::cin >> vec.name;
    std::cout << "Input vector X (real): ";
    std::cin >> vec.x;
    std::cout << "Input vector Y (real): ";
    std::cin >> vec.y;
}

int main()
{
    std::string command = "-";

    while (command != "exit")
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "add")
        {
            mVec vec1, vec2, rVec;
            std::cout << "Enter vector 1: " << std::endl;
            getVec(vec1);
            std::cout << "Enter vector 2: " << std::endl;
            getVec(vec2);
            std::cout << "Sum of vectors: " << vec1.name
                      << " and " << vec2.name << " :" << std::endl;
            rVec = add(vec1, vec2);
            printVec(rVec);
        }

        else if (command == "subtract")
        {
            mVec vec1, vec2, rVec;
            std::cout << "Enter vector 1: " << std::endl;
            getVec(vec1);
            std::cout << "Enter vector 2: " << std::endl;
            getVec(vec2);
            std::cout << "Subtract of vectors: " << vec1.name
                      << " and " << vec2.name << " :" << std::endl;
            rVec = subtract(vec1, vec2);
            printVec(rVec);
        }

        else if (command == "scale")
        {
            mVec vec, rVec;
            float sclar;
            std::cout << "Enter vector: " << std::endl;
            getVec(vec);
            std::cout << "Enter scalar value (real): ";
            std::cin >> sclar;

            rVec = scale(vec, sclar);
            std::cout << "Result of vector " << vec.name
                      << ": " << std::endl;
            printVec(rVec);
        }

        else if (command == "length")
        {
            mVec vec;
            std::cout << "Enter vector 1: " << std::endl;
            getVec(vec);
            std::cout << "Length of vector " << vec.name
                      << ": " << length(vec) << std::endl;
        }

        else if (command == "normalize")
        {
            mVec vec, rVec;
            std::cout << "Enter vector 1: " << std::endl;
            getVec(vec);
            rVec = normalize(vec);
            std::cout << "Normalized vector " << vec.name
                      << ": " << std::endl;
            printVec(rVec);
        }

        else if (command == "exit")
        {
            std::cout << "Exiting" << std::endl;
            return 0;
        }
        else
            std::cout << "Command not recognized." << std::endl;
    }
}