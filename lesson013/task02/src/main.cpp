/*
2. Реализация умного указателя

Что нужно сделать
1. Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, реализованного в задании.
    Указатель должен:
       - иметь все стандартные методы класса,
       - быть функциональной заменой использованию shared_ptr.
2. Реализуйте свободную функцию make_shared_toy, которая принимает набор аргументов и конструирует игрушку от названия или при помощи копии другой игрушки.

Советы и рекомендации
Не забудьте уменьшить число ссылок на единицу в деструкторе умного указателя. Когда на счётчике появится значение 0, удалите объект.

Вы можете использовать перегрузки под разные типы. Их количество ограничено.

Чек-лист для проверки задания
    - Класс называется shared_ptr_toy.
    - Реализованы конструктор, конструктор копий, оператор присваивания
    - копированием, деструктор и функция make_shared.
*/
#include <iostream>

#include "dog.h"
#include "shared_ptr_toy.h"

int main()
{

    shared_ptr_toy ball = make_shared_toy("Ball");
    shared_ptr_toy bone = make_shared_toy("Bone");
    shared_ptr_toy horn = make_shared_toy("Horn");

    Dog first("Sheriff", 10);
    Dog second("Lord", 10);
    Dog third("Countess", 10);

    // third.pickupToy(horn);

    // first.dropToy();            // check drop
    // first.pickupToy(ball);      // check pick up
    // second.pickupToy(ball);     // check pick up occupied
    // first.pickupToy(ball);      // check pick up double
    // first.pickupToy(bone);      // check pick up another
    // second.pickupToy(ball);     // check pick up dropped

    return 0;
}