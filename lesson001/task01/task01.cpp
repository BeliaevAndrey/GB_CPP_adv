/*
Задание 1. Разработка программы поиска слов в файле

Что нужно сделать
Составьте небольшой текстовый файл «words.txt», в котором
последовательно, через пробелы и переносы строк расположены различные
слова. Можете использовать любые англоязычные слова. Разработайте
программу, которая искала бы среди этих слов нужное пользователю и
выводила бы общее количество повторений этого слова. 0 — если слово
вообще не присутствует в файле.
*/
#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::ifstream words;
    words.open("/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson001/task01/words.txt");

    int wordAmt = 0;
    std::string word;
    std::string search;

    std::cout << "Input word: ";
    std::cin >> search;

    while (!words.eof())
    {
        words >> word;
        if (word == search)
        {
            wordAmt++;
            std::cout << word << " " << wordAmt << std::endl;
        }
    }

    std::cout << "Searched word: "
              << search
              << ", amount: "
              << wordAmt
              << std::endl;

    words.close();

    return 0;
}