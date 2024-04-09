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
#include <string>

#include "shared_ptr_toy.h"




int main()
{


    shared_ptr_toy ball0(nullptr);

    shared_ptr_toy ball1(new Toy("Ball"));

    shared_ptr_toy ball2(ball1);

    shared_ptr_toy ball3 = ball1;


    std::cout << "ball0 use_count   " << ball0.use_count() << std::endl;
    std::cout << "ball0 getName     " << ball0.getToy() << std::endl;

    std::cout << "ball1 use_count   " << ball1.use_count() << std::endl;
    std::cout << "ball1 getName     " << ball1.getToy()->getName() << std::endl;

    ball1.reset();

    std::cout << "ball2 use_count   " << ball2.use_count() << std::endl;
    std::cout << "ball2 getName     " << ball2.getToy()->getName() << std::endl;

    std::cout << "ball3 use_count   " << ball3.use_count() << std::endl;
    std::cout << "ball3 getName     " << ball3.getToy()->getName() << std::endl;



    shared_ptr_toy bone("Bone");
    std::cout << "bone use_count   " << bone.use_count() << std::endl;
    std::cout << "bone getName     " << bone.getToy()->getName() << std::endl;

    std::cout << "reset ball0 " << std::endl;
    ball0.reset();
    std::cout << "reset ball1 " << std::endl;
    ball1.reset();
    std::cout << "reset ball2 " << std::endl;
    ball2.reset();
    std::cout << "reset ball3 " << std::endl;
    ball3.reset();

    std::cout << "reset bone " << std::endl;
    bone.reset();


    return 0;
}