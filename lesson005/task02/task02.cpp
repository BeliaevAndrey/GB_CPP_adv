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

/*
При обёртывании __всей__ функции main(), в случае неопределённой директивы
CURRENT возникает ошибка компиляции:

```
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/10/../../../x86_64-linux-gnu/Scrt1.o: в функции «_start»:
(.text+0x20): неопределённая ссылка на «main»
collect2: error: ld returned 1 exit status
```

*/

// #if CURRENT  // Error
int main()
{
#if CURRENT     // В данном случае ошибка не возникает

    switch (CURRENT)
    {
    case WINTER: WINTER_F(); break;
    case SPRING: SPRING_F(); break;
    case SUMMER: SUMMER_F(); break;
    case AUTUMN: AUTUMN_F(); break;
    default: break;
    }

    return 0;
#endif
}
// #endif
