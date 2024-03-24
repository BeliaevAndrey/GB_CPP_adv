/*
Задание 3. Реализация симуляции игры «Рыбалка»

Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки
(river.txt) задаётся список из видов рыб, которые можно в ней поймать. Рыбок
может быть сколько угодно, разных видов. Виды при этом могут повторяться. В
начале программы пользователь указывает, какую именно рыбу он сейчас будет
ловить — вид этой рыбы. После этого из первого файла друг за другом
осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах
вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка)
записывается этот вид. В конце программы показывается, сколько было поймано рыб
за текущую ловлю. Программу можно запускать несколько раз, при этом уже
пойманные рыбы должны сохраняться в файле-корзинке.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const std::string basketPath("/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson002/task03/basket.txt");
const std::string riverPath("/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson002/task03/river.txt");

int showBasket()
{
    std::ifstream basket(basketPath);

    int count = 0;

    std::cout << "Fishes in basket: " << std::endl;
    if (!basket.is_open() && !basket.eof())
    {
        std::cout << "Basket is empty" << std::endl;
        return count;
    }

    while (!basket.eof())
    {
        std::string fish;
        basket >> fish;
        std::cout << fish << std::endl;
    }

    basket.close();
    return count;
}

void putToBasket(std::string &fishType)
{
    std::ofstream basket(basketPath, std::ios::app);
    basket << fishType << std::endl;
    basket.close();
}

bool fishing(std::string &fishType)
{
    std::ifstream river(riverPath);

    while (!river.eof())
    {
        std::string fish;
        river >> fish;
        if (fish == fishType)
        {
            river.close();
            return true;
        }
    }

    river.close();
    return false;
}

int main()
{
    std::string fishType;

    int count = showBasket();
    if (count)
    {
        char answer = 'N';
        std::cout << "Empty the basket? (y/N): ";
        std::cin >> answer;
    }

    while (true)
    {
        std::cout << "Input type of fish ('exit' to exit): ";

        std::cin >> fishType;

        if (fishing(fishType))
            putToBasket(fishType);
        else if (fishType == "exit")
            break;
        else
            std::cout << "Fish not found." << std::endl;

        showBasket();
    }
    std::cout << std::endl;
    showBasket();
    return 0;
}
