/*
1. Использование умного указателя
Что нужно сделать

1. Реализуйте класс Dog, который использует стандартный умный указатель
shared_ptr для класса Toy.
2. Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает
игрушку.
    - Если у собаки уже есть эта игрушка, необходимо вывести в консоль фразу:
      I already have this toy.
    - Если в данный момент игрушка находится у другой собаки, нужно вывести в
      консоль: Another dog is playing with this toy.
    -Если игрушка свободна, собака подбирает её.
3. Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает
игрушку на пол, после чего другая может подобрать её. — Если у собаки в этот
момент нет игрушки, в консоль необходимо вывести: Nothing to drop.

Советы и рекомендации
Чтобы узнать, у скольких собак в данный момент есть игрушка, можно
использовать метод use_count() у класса shared_ptr. При этом необходимо
учитывать, что
создание shared_ptr от класса Toy тоже увеличивает показатели счётчика.
*/

#include <iostream>
#include "dog.h"

int main()
{
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");
    std::shared_ptr<Toy> horn = std::make_shared<Toy>("Horn");

    Dog first("Sheriff", 10);
    Dog second("Lord", 10);
    Dog third("Countess", 10);

    third.pickupToy(horn);
    
    first.dropToy();            // check drop
    first.pickupToy(ball);      // check pick up
    second.pickupToy(ball);     // check pick up occupied
    first.pickupToy(ball);      // check pick up double
    first.pickupToy(bone);      // check pick up another
    second.pickupToy(ball);     // check pick up dropped

    return 0;
}