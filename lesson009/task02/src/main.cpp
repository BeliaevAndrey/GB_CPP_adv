/*
Задание 2. Иерархия геометрических фигур

Что нужно сделать
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний
треугольник, прямоугольник. Для всех этих фигур есть общие поля-данные - это
координаты их центра и условный цвет фигуры: красный, синий или зелёный. Для
отдельных фигур есть и уникальные параметры: радиус для круга, длина ребра для
квадрата и равностороннего треугольника, ширина и высота для прямоугольника.
Все данные - это вещественные числа с удвоенной точностью. Для каждой из фигур
требуется определить метод нахождения площади фигуры, а также метод нахождения
прямоугольника, описывающего фигуру полностью (он может быть больше зоны
фигуры, но не меньше).
Для теста предусмотрите ввод пользователем команд: circle, square, triangle,
rectangle, соответствующих фигурам. Команды должны получать параметры фигур и
выводить их цвет, площадь и описывающий прямоугольник с координатами.

Для цвета фигуры: enum, константа отсутствия цвета - None.
Площадь треугольника: length * length * std::sqrt(3) / 4; где length - сторона.
Площадь круга - как atan(1) * 4 * radius;
*/

#include <iostream>
#include <string>

#include "figure.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

void requestCenter(double& X, double& Y) {
    std::cout << "Input center coordinates X Y: ";
    std::cin >> X;
    std::cin >> Y;
}

double requestLength(const char* prompt) {
    double length;
    std::cout << "Input " << prompt << ": ";
    std::cin >> length;
    return length;
}

figColor requestColor() {
    std::cout << "Input color "
        << "(red (1), green (2), blue (3), purple (4) ): ";
    int color;
    std::cin >> color;
    return figColor(color);
}

int main()
{
    std::string command = "";
    std::string menu = "rectangle\ncircle\ntriangle\nsquare\nexit";

    std::cout << "commans are:" << menu << std::endl;

    while (command != "exit")
    {
        double centerX, centerY;
        figColor color;

        std::cout << "Input command: ";
        std::cin >> command;
        if (command == "circle") {
            requestCenter(centerX, centerY);
            Circle* circle = new Circle(
                centerX, centerY,
                requestLength("radius"),
                requestColor());

            std::cout << circle->printSelf() << std::endl;
            
            delete circle;
            circle = nullptr;
        }
        else if (command == "rectangle") {
            requestCenter(centerX, centerY);
            Rectangle* rectangle = new Rectangle(
                requestLength("side 1 length"),
                requestLength("side 2 length"),
                centerX,
                centerY,
                requestColor());

            std::cout << rectangle->printSelf() << std::endl;

            delete rectangle;
            rectangle = nullptr;
        }
        else if (command == "square") {
            double side = requestLength("side length");
            requestCenter(centerX, centerY);
            Rectangle* square = new Rectangle(
                side, side,
                centerX, centerY,
                requestColor());
            
            std::cout << square->printSelf() << std::endl;

            delete square;
            square = nullptr;
        }
        else if (command == "triangle") {
            requestCenter(centerX, centerY);
            Triangle* triangle = new Triangle(centerX, centerY,
                requestLength("side length"),
                requestColor());
            
            std::cout << triangle->printSelf() << std::endl;

            delete triangle;
            triangle = nullptr;

        }
        else if (command == "exit") std::cout << "Exiting..." << std::endl;
        else std::cout << "Command not  recognized." << std::endl;
    }

    return 0;
}
