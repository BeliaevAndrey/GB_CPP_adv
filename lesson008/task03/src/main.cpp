/*
Задание 3.
Реализация программы управления окном рабочего стола
Что нужно сделать Реализуйте симуляцию работы окна в визуальном
интерфейсе пользователя. Окно располагается на виртуальном экране
монитора, размером 80 × 50 точек. У окна есть несколько параметров,
которые также задаются в пикселях: двумерные координаты левого
верхнего угла и размеры, ширина и высота. Ширина и высота при этом не
могут быть отрицательными, а координаты не могут выходить за область
экрана.

Пользователь взаимодействует с программой с помощью команд:

* move -- Команда принимает вектор, на который надо сместить окно на
    экране. Сообщение с новыми координатами окна появляется на экране.
* resize -- Команда запрашивает из стандартного ввода новый размер
    окна. После изменения размера сообщение с новым размером
    выводится на экране.
* display -- Команда  выводит текущее изображение монитора в консоль.
    0 - это пиксель вне области окна, 1 - с окном.
* close -- Команда закрывает окно, выход из программы.
Советы и рекомендации
Сам экран монитора вы тоже можете реализовать с помощью класса.
*/

#include <iostream>
#include <string>

#include "window.h"


int main()
{
    Display* d = new Display();
    Window* w = new Window(d);
    Position* p = new Position(0, 0);
    std::string command;

    do {
        std::cin >> command;
        if (command == "resize") {
            int x, y, answer = 1;
            std::cout << "Input new size (x y): ";
            std::cin >> x >> y;
            if (p) std::cout << p;

            while ((answer = w->resize(x, y)))
            // while (!p)
            {
                std::cout << "Wrong size. Try again (x y): ";
                std::cin >> x >> y;
            };
            w->resize(x, y);
        }

        if (command == "move") {
            int x, y, answer = 1;
            std::cout << "Input coordinates (x y): ";
            std::cin >> x >> y;
            while ((answer = w->move(x, y)))
            {
                std::cout << "Wrong coordinates. Try again (x y): ";
                std::cin >> x >> y;
            };
            w->move(x, y);
        }

        if (command == "display") {
            w->display();
        }

        if (command == "close") { command = w->close(); }

    } while (command != "exit");

    return 0;
}
