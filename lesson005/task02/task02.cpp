/*
Задание 2. Вывод времени года

Что нужно сделать
Используя макросы вместе с условными директивами прекомпиляции (#if / #endif),
реализуйте простую программу по выводу названия времени года в консоль.
Пользователь программы, который будет иметь дело с вашим кодом, в этом случае
тоже программист. С помощью определения одного из макросов (в самом коде):
SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, название, которое хочет
увидеть на экране. При компиляции и запуске программы на экране должно
появиться название именно этого сезона и только его.
*/

#include <iostream>

using namespace std;

// #define CURRENT WINTER
#define CURRENT SPRING
// #define CURRENT SUMMER
// #define CURRENT AUTUMN

#define WINTER 1
#define SPRING 2
#define SUMMER 3
#define AUTUMN 4

#define WINTER_F() { cout << "Winter" << endl; }
#define SPRING_F() { cout << "Spring" << endl; }
#define SUMMER_F() { cout << "Summer" << endl; }
#define AUTUMN_F() { cout << "Autumn" << endl; }

int main()
{
#if CURRENT
    switch (CURRENT)
    {
    case 1: WINTER_F(); break;
    case 2: AUTUMN_F(); break;
    case 3: SPRING_F(); break;
    case 4: AUTUMN_F();
    default: break;
    }

    return 0;
#endif
}
