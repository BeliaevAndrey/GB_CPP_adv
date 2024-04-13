/*
Задание 1. Работа корзины с покупками
Что нужно сделать
Реализуйте простую и безопасную модель работы корзины онлайн-магазина.

* В начале программы вы заполняете базу данных самого магазина через
    стандартную консоль. Каждый элемент этой базы данных состоит из двух
    компонентов -- артикула и количества штук.

* Корзина должна поддерживать следующие операции:
    add -- добавление товара с указанным его количеством
    remove -- удаление товара с указанным количеством .
    Обе операции принимают артикул товара в виде строки и количество
    в виде целого числа.

* При вводе аргументов к операциям должна осуществляться их валидация. Артикул
    должен быть в базе данных магазина, количество не должно превышать
    количество доступного продукта на складе (при удалении -- в корзине).

Рекомендации
В качестве контейнера для базы данных и самой корзины можете использовать
std::map. Если пользователь ввёл некорректную информацию, то лучше выбросить
std::invalid_argument, в других случаях -- runtime_error.

*/

#include <iostream>
#include <map>
#include <exception>
#include <ctime>


std::map<int, int> storage;

struct Request {
    int article;
    int amt;

    void read(std::map<int, int>& inMap) {
        std::cout << "Input article: ";
        std::cin >> article;
        if (!inMap.count(article)) {
            throw std::invalid_argument("Product art. " +
                std::to_string(article) + " is not found at store");
        }

        std::cout << "Input amount: ";
        std::cin >> amt;

        if (amt <= 0) {
            throw std::invalid_argument(
                "'" + std::to_string(amt) + "' incorret argument");
        }
        else if (amt > inMap.at(article))
        {
            throw std::invalid_argument(
                "'" + std::to_string(amt) + "' amount too large");
        }
    }
};

struct Basket
{
    std::map<int, int> goods;
    Request r;
    void put() {
        r.read(storage);
        if (goods.count(r.article))
            goods.at(r.article) += r.amt;
        else
            goods.insert(std::make_pair(r.article, r.amt));

        storage.at(r.article) -= r.amt;
    }

    void remove() {
        r.read(goods);
        if (!goods.count(r.article))
        {
            throw std::invalid_argument("No such product in your basket");
        }

        if (goods.at(r.article) < r.amt)
        {
            throw std::invalid_argument("incorect value" +
                std::to_string(r.amt) + " is too much");
        }

        if (r.amt <= 0)
        {
            throw std::invalid_argument("incorect value");
        }

        storage.at(r.article) += r.amt;
        goods.at(r.article) -= r.amt;
        if (goods.at(r.article) == 0)
            goods.erase(r.article);
    }
};


void menu()
{
    std::cout <<
        "Available commands:\n"
        "add    -- add a good to basket\n"
        "remove -- remove a good from basket\n"
        "show   -- print storage\n"
        "look   -- look into basket\n\n"
        "help   -- print this menu\n"
        "exit   -- remove a good from basket"
        << std::endl;
}

void fillStorageAuto()
{
    std::srand(time(nullptr));

    for (int i = 0; i < 10 + rand() % 11; i++)
    {

        int article = (10 + rand()) % 1000;
        int amt = 14 + rand() % 10;

        storage.insert(std::make_pair(article, amt));
    }

}

void printMap(std::map<int, int>& inMap, const std::string& place)
{
    std::string line = "-----------";
    std::cout << line << place << line << std::endl;

    int count = 0;
    for (
        std::map<int, int>::iterator it = inMap.begin();
        it != inMap.end(); ++it
        )
    {
        std::cout << ++count << ".\t";
        std::cout << it->first << "\t\t" << it->second << std::endl;
    }

    std::cout << line << place << line << std::endl;
}

void shopping(Basket& basket)
{

    bool runFlag(true);

    std::string command;

    while (runFlag) {
        std::cout << "Input command: ";
        std::cin >> command;

        if (command == "add")
        {
            try
            {
                basket.put();
            }
            catch (std::invalid_argument& exc)
            {
                std::cerr << exc.what() << std::endl;
            }
        }
        else if (command == "remove")
        {
            try {
                basket.remove();
            }
            catch (std::invalid_argument& exc)
            {
                std::cerr << exc.what() << std::endl;
            }
        }
        else if (command == "print")
        {
            printMap(storage, " Storage ");
        }
        else if (command == "look")
        {
            printMap(basket.goods, "  Basket  ");
        }

        else if (command == "help")
        {
            menu();
        }
        else if (command == "exit") {
            runFlag = false;
            std::cout << "Exiting..." << std::endl;
        }
        else std::cout << "unknown command" << std::endl;
    }

}

int main()
{
    fillStorageAuto();
    printMap(storage, " Storage ");
    menu();
    Basket basket;
    shopping(basket);

    printMap(basket.goods, "  Basket  ");

    return 0;
}