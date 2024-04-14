/*
Задание 4. Среднее арифметическое число в массиве

Что нужно сделать
Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве
скалярных чисел произвольного типа. Это может быть int, double, float и так
далее. Ввод данных массива и вывод результата производится через стандартную
консоль.

Рекомендации
Для простоты можете реализовать подсчёт в массиве фиксированной длины. Функцию
ввода данных массива тоже рекомендуется реализовать как шаблонную. Обе функции
имеют похожую сигнатуру вида:
template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
    //ввод отдельных элементов
    }
}
*/

#include <iostream>
#include <string>
#include <exception>

const int arrLen = 8;

template<typename T>
double calcMeanValue(T* array) {
    T total = 0;
    for (int i = 0; i < arrLen; i++)
    {
        total += array[i];
    }

    return total / arrLen;
}

template<typename T>
void readArray(T* array) {

    std::cout << "Fill the array (" << arrLen << "):\n";
    for (int i = 0; i < arrLen; i++)
    {
        std::cin >> array[i];
    }

    std::cout << std::endl;
}

template<typename T>
void printArray(T* array) {
    for (int i = 0; i < arrLen; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}

int main()
{
    /* test float */
    float fltArr[arrLen];

    readArray(fltArr);

    printArray(fltArr);

    std::cout << "Mean value: " << calcMeanValue(fltArr) << std::endl;

    /* test int */
    int intArr[arrLen];

    readArray(intArr);

    printArray(intArr);

    std::cout << "Mean value: " << calcMeanValue(fltArr) << std::endl;

    return 0;
}
