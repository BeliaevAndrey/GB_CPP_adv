/*
Задача 1. Суперпёс

Возьмём решение из видео. Все наши животные могут мяукать и гавкать, то есть
издавать звуки в соответствии со своим классом. Но что, если нужно добавить им
новое поведение, например, научить плавать или стоять на задних лапах.
Рассмотрим класс Dog: все собаки умеют лаять и бегать, а некоторые собаки умеют
хорошо плавать. Чтобы добавить эти качества классу Dog, мы можем создать ещё
один класс «плавающих» животных и наследовать от него наш класс. Но что, если
не все собаки умеют хорошо плавать, а некоторые из них совсем не умеют плавать.
Наша задача - построить класс Dog таким образом, чтобы к его объектам можно
было выборочно добавлять новые умения, но при этом не менять поведение
основного класса. Список умений будет вызываться с помощью метода
show_talents().

Что нужно сделать
Создайте класс Dog, к которому можно добавлять новые способности.
Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться
все добавляемые способности. Пока таких способностей три: умение плавать
(Swimming), умение танцевать (Dancing), умение считать (Counting), но можете
добавить и другие.
Создайте у класса Dog метод show_talents() для показа всех способностей,
которыми обладает собака.
Требования к реализации Класс Talent должен быть абстрактным. Это значит, что
объекты такого класса мы создать не сможем, так как одна из его функций
объявлена как «чисто» виртуальная (pure virtual). Каждая способность,
наследуемая от абстрактного класса Talent, должна быть представлена в виде
отдельного класса. Пример выполнения Создаём собаку с именем Steve: Dog dog1
("Steve") Добавляем ей умение танцевать и плавать. Если мы сделаем запрос
умений show_talents(), то на экран будет выведено:

This is Steve and it has some talents:
It can “Dance”
It can “Swim”

Советы и рекомендации
* Для хранения способностей можно использовать вектор.
* Для создания абстрактного класса рекомендуем пересмотреть видео,
    где функция voice в классе Animal была объявлена «чисто» виртуальной.
*/

#include <iostream>
#include <vector>
#include <string>

#include "dog.h"
#include "cat.h"


void checkAnimal(Animal* animal) {
    animal->jump();
    animal->run();
    animal->voice();
    std::cout << "This is " << animal->introduceSelf() << std::endl;
    animal->show_talents();
    std::cout << "\nTraining\n" << std::endl;
    animal->setTalent(new Dance());
    animal->show_talents();

    Talent* t = animal->getTalent("Swim");
    if (t)
        std::cout << animal->getTalent("Swim")->report() << std::endl;
    else
        std::cout << "No such talent" << std::endl;
}

int main()
{
    // Talent* test = new Talent();
    // error: invalid new-expression of abstract class type ‘Talent’
    //    51 |     Talent* test = new Talent();

    Dog* dog = new Dog("Steve", new Swim());
    checkAnimal(dog);
    // dog->jump();
    // dog->run();
    // dog->voice();
    // std::cout << "This is " << dog->introduceSelf() << std::endl;
    // dog->show_talents();
    // std::cout << "\nTraining\n" << std::endl;
    // dog->setTalent(new Dance());
    // dog->show_talents();

    // Talent* t = dog->getTalent("Swim");
    // if (t)
    //     std::cout << dog->getTalent("Swim")->report() << std::endl;
    // else
    //     std::cout << "No such talent" << std::endl;

    Cat* cat = new Cat("Felix", new Dance());
    checkAnimal(cat);
    // cat->run();
    // cat->jump();
    // cat->voice();
    // std::cout << "This is " << cat->introduceSelf() << std::endl;
    // cat->show_talents();
    // std::cout << "\nTraining\n" << std::endl;
    // cat->setTalent(new Sing());
    // cat->show_talents();

    // t = cat->getTalent("Sing");
    // if (t)
    //     std::cout << t->report() << std::endl;
    // else
    //     std::cout << "No such talent" << std::endl;


    delete dog;
    dog = nullptr;
    delete cat;
    cat = nullptr;

    return 0;
}