/*
Задание 2. Игра по ловле рыбы
Что нужно сделать
Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой
девять секторов условного пруда. В начале игры в одном из этих секторов с
помощью генератора случайных чисел оказывается рыба. Точно так же, случайным
образом, по секторам пруда распределяются и три сапога. Сапог и рыба при этом
не могут находиться в одном и том же секторе одновременно, как и несколько
сапог сразу в одном из секторов.

Игрок закидывает удочку с приманкой в один из секторов, номер которого вводится
стандартным способом через консоль. Задача игрока -- угадать сектор, в котором
находится рыба и, таким образом, поймать её. Если игрок попал на пустой сектор,
то удочку надо забросить повторно. Если игрок поймал сапог, то игра завершается
с отрицательным результатом.

Реализовать задачу нужно с помощью исключений: когда успешный заброс удочки
генерирует специальное пользовательское исключение, после чего программа должна
завершиться и оповестить пользователя об успешной рыбалке и количестве попыток,
которое ему для этого потребовалось. Если же был пойман сапог, то должно
выводиться сообщение о неудачной ловле.

Рекомендации
Вспомните, что вы можете выбросить в качестве исключения произвольный тип
данных. Это может быть и сапог, и рыба.

В функции main потребуется расположить рыбу случайным образом. Для этого
сделайте std::srand(std::time(nullptr)); а затем само расположение: field
[std::rand() % 9].fish = new Fish(); Благодаря оператору % вы не выйдете за
пределы массива.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <exception>
class win_ecxeption : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You have caught a FISH!";
    }
};

class lose_ecxeption : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You have caught a BOOT!";
    }
};


class Fish {};
class Boot {};
class Field {
public:
    Fish* fish;
    Boot* boot;
};

class Pond
{
private:
    Field* field[9];
    int attempts = 0;

    void placeFish() {
        int bootCount = 3;
        std::srand(std::time(nullptr));

        for (int i = 0; i < 9; i++)
            field[i] = new Field();


        field[std::rand() % 9]->fish = new Fish();

        while (bootCount > 0)
        {
            int i = std::rand() % 9;
            if (!field[i]->fish && !field[i]->boot)
            {
                field[i]->boot = new Boot();
                --bootCount;
            }
        }
    }

public:
    Pond() {
        placeFish();
    }

    void printPond() {
        std::cout << "---------" << std::endl;

        for (int i = 0; i < 9; i++)
        {
            if (field[i]->fish)
                std::cout << " F ";
            else if (field[i]->boot)
                std::cout << " b ";
            else std::cout << "~^~";

            if (!((i + 1) % 3)) std::cout << std::endl;
        }

        std::cout << "---------" << std::endl;
    }

    int getAttempts() { return attempts; }

    void castRod(int i) {
        attempts++;
        if (field[i]->fish) throw win_ecxeption();
        else if (field[i]->boot)throw lose_ecxeption();
    }
};

int main()
{
    Pond pond;
    int field;

    while (true) {
        std::cout << "input sector (1-9): ";
        std::cin >> field;
        try {

            pond.castRod(field - 1);
        }
        catch (win_ecxeption& exc) {
            std::cerr << exc.what() << std::endl;
            break;
        }
        catch (lose_ecxeption& exc) {
            std::cerr << exc.what() << std::endl;
            break;
        }
    }

    std::cout << "Attempts amount: " << pond.getAttempts() << std::endl;
    pond.printPond();

    return 0;
}
