/*
Задача 2. Интерфейс Shape (дополнительное задание)
У вас есть набор классов различных геометрических фигур: круг(Circle), 
прямоугольник(Rectangle) и треугольник(Triangle), которые наследуются от общего 
класса геометрическая фигура (Shape). Каждый из этих классов имеет методы 
подсчёта площади, описывающего прямоугольника и взятия типа. Также есть общая 
функция printParams которая по переданному ей указателю на объект типа 
геометрическая фигура выводит на экран тип фигуры.

Что нужно сделать
Создайте интерфейс Shape (фигуру), который предоставляет следующие методы:

virtual double square() = 0; - возвращает площадь конкретной фигуры;
virtual BoundingBoxDimensions dimensions() = 0; - размеры описывающего 
прямоугольника; BoundingBoxDimensions - простая структура, которая содержит 
ширину и высоту;
virtual std::string type() = 0; - название конкретного типа, например, вернуть 
строку Triangle для класса Triangle; void printParams(Shape *shape) - сюда 
можно будет передавать любые фигуры:

{
std::cout <<"Type: " << shape->type() << std::endl;
}

комбинация virtual … = 0; - создаёт чисто виртуальный метод. Это означает, что 
такой метод обязательно должен быть переопредёлен в классе-наследнике. Если 
программист пронаследует свой класс от такого интерфейса, то компилятор будет 
ругаться на отсутствие методов, описанных как virtual … = 0. То есть 
программист будет вынужден добавить такие методы в свой класс, чтобы создать 
объект такого типа. …. Создайте классы-наследники Shape: Circle, Rectangle и 
Triangle. У каждого из классов будет разный набор полей: у треугольника будут 
три стороны в виде переменных double, у круга - радиус, а у прямоугольника - 
длина и ширина. Так как все они наследуются от Shape, в каждом из классов 
следует реализовать методы нахождения размерности, площади и метод, 
возвращающий название типа. Площадь треугольника при известных длинах сторон 
находится при помощи формулы Герона: sqrt(p * (p - a) * (p - b) * (p - c)), где 
p - полупериметр. Размеры описывающего прямоугольника для треугольника 
находятся по похожей формуле - сначала находим радиус описанной окружности: a * 
b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c))), где р - снова полупериметр. 
Затем умножаем его на два и получаем сторону квадрата, в который помещён 
треугольник. В функции main вызовите printParams со всеми типами, которые вы 
создали. 

Пример:
Triangle t(3,4,5);
printParams(&t);

Вывод
Type: Triangle
Square: 6
Width: 5
Height: 5

* Приложение выводит в консоль сообщения о типе фигуры, которые соответствуют 
    действительности.
* Функция принимает корректные типы данных. Тип возвращаемого значения - void.
* Решение выполнено через создание наследников от интерфейса Shape.
* Сигнатура функции void - printParams (Shape *shape). Любая другая некорректна.
* Желательно каждую фигуру (класс-наследник shape) описывать в отдельном файле.
*/
#include <iostream>
#include <string>
#include <cmath>

struct BoundingBoxDimensions {
    double bbLengthA = 0;
    double bbLengthB = 0;
};

class Shape
{
private:
    std::string shapeType;
protected:
    void setShapeType(std::string inShapeType)
    {
        shapeType = inShapeType;
    }

    std::string getShapeType() {
        return shapeType;
    }
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;

};

class Circle : virtual public Shape
{

    double radius;
    void setRadius(double& inRadius) {
        radius = inRadius;
    }

public:

    Circle(double inRadius)
    {
        setRadius(inRadius);
        setShapeType("Circle");
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions bBox;
        bBox.bbLengthA = radius * 2 + 1;
        bBox.bbLengthB = bBox.bbLengthA;
        return bBox;

    }

    virtual std::string type() override
    {
        return getShapeType();
    }
    virtual double square() override {
        return atan(1) * radius * 4;
    }
};

class Rectangle : virtual public Shape
{

    double lengthA;
    double lengthB;

public:
    Rectangle(double inLengthA, double inLengthB) :
        lengthA(inLengthA), lengthB(inLengthB)
    {
        setShapeType("Rectangle");
    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions bBox;
        bBox.bbLengthA = lengthA + 1;
        bBox.bbLengthB = lengthB + 1;
        return bBox;

    }

    virtual std::string type()override
    {
        return getShapeType();
    }

    virtual double square() override {
        return lengthA * lengthB;
    }
};

class Triangle : virtual public Shape
{
    double lengthA;
    double lengthB;
    double lengthC;

    double getPerimeter() {
        return lengthA + lengthB + lengthC;
    }

    double getHeight() {
        return  2 * square() / lengthA;
    }

public:

    Triangle(double inLengthA, double inLengthB, double inLengthC) :
        lengthA(inLengthA), lengthB(inLengthB), lengthC(inLengthC)
    {
        setShapeType("Rectangle");

    }

    virtual BoundingBoxDimensions dimensions() override
    {
        BoundingBoxDimensions bBox;
        bBox.bbLengthA = lengthA + 1;
        bBox.bbLengthB = getHeight() + 1;
        return bBox;

    }

    virtual std::string type() override
    {
        return getShapeType();
    }

    virtual double square() override {
        double p = getPerimeter() / 2;
        return std::sqrt((p * (p - lengthA) * (p - lengthB) * (p - lengthC)));
    }
};

void printParams(Shape* shape) {
    std::cout << "Type:   " << shape->type() << std::endl;
    std::cout << "Square: " << shape->square() << std::endl;
    std::cout << "Width:  " << shape->dimensions().bbLengthA << std::endl;
    std::cout << "Height: " << shape->dimensions().bbLengthB << std::endl;
}

int main()
{
    std::cout << "Shape interface" << std::endl;
    Triangle t(3, 4, 5);

    printParams(&t);
  

    return 0;
}