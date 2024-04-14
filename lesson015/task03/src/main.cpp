/*
Задание 3. Реестр данных на шаблонах

Что нужно сделать
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы
значений по ключам произвольного типа. Ключи при этом могут повторяться. Реестр
должен поддерживать следующие операции: добавление элемента с ключом, удаление
элементов с заданным ключом, вывод всех значений с ключами в консоль, поиск
элементов по ключу.

Для тестирования программы предусмотрите ввод данных и команд из стандартной
консоли:

* add -- добавить элемент с ключом;
* remove -- удалить все элементы с заданным ключом;
* print -- напечатать на экране все элементы с их ключами;
* find -- найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int,
double, std::string.

Рекомендации
Для реализации можете использовать стандартный шаблон std::vector, который в
свою очередь уже будет хранить ваши пары ключей и значений.
Сама пара ключа и значения как раз и будет классом (или струкурой),
шаблонизированным двумя типами: типом значения и типом ключа.
При желании вы можете создать отдельную шаблонизированную функцию с вводом
команд и их данных.
*/

#include <string>
#include "registry.h"

void testNumbers()
{
    Registry<int, float>* rTest = new Registry<int, float>();

    /* Test add */
    for (int i = 0; i < 200; i += 10)
    {
        rTest->add(i + 1, i + (1 + rand() % 1000) / 1000.0);
    }

    rTest->add(100, 900.153);
    rTest->add(10, 890.193);
    rTest->add(100, 890.193);
    rTest->add(10, 980.183);
    rTest->add(100, 980.183);
    rTest->add(10, 150.163);
    rTest->add(100, 150.193);
    rTest->add(10, 150.11233);
    rTest->add(100, 150.163);

    /* Test print */
    rTest->print();
    std::cout << std::endl;

    /* Test find */
    std::vector<float>* findResult = rTest->find(100);

    for (int i = 0; i < findResult->size(); i++)
    {
        std::cout << findResult->at(i) << " ";

    }
    std::cout << std::endl;

    /* Test remove */
    rTest->remove(10);


    /* Test find absent */
    findResult = rTest->find(10);
    if (findResult->size() > 0) {

        for (int i = 0; i < findResult->size(); i++)
            std::cout << findResult->at(i) << " ";

        std::cout << std::endl;
    }

    else
        std::cout << "Not found" << std::endl;


    rTest->print();
    std::cout << std::endl;

    /* Test remove absent*/
    rTest->remove(10);

    delete rTest;
}

void testSymbols()
{
    Registry<std::string, float>* rTest = new Registry<std::string, float>();

    /* Test add */
    for (int i = 0; i < 200; i += 10)
    {
        rTest->add(
            ((std::to_string(i + 1)).c_str()),
            i + (1 + rand() % 1000) / 1000.0);
    }

    rTest->add("100", 900.153);
    rTest->add("10", 890.193);
    rTest->add("100", 890.193);
    rTest->add("10", 980.183);
    rTest->add("100", 980.183);
    rTest->add("10", 150.163);
    rTest->add("100", 150.193);
    rTest->add("10", 150.11233);
    rTest->add("100", 150.163);

    /* Test print */
    rTest->print();
    std::cout << std::endl;

    /* Test find */
    std::vector<float>* findResult = rTest->find("100");

    for (int i = 0; i < findResult->size(); i++)
    {
        std::cout << findResult->at(i) << " ";

    }
    std::cout << std::endl;

    /* Test remove */
    rTest->remove("10");


    /* Test find absent */
    findResult = rTest->find("10");
    if (findResult->size() > 0) {

        for (int i = 0; i < findResult->size(); i++)
            std::cout << findResult->at(i) << " ";

        std::cout << std::endl;
    }

    else
        std::cout << "Not found" << std::endl;


    rTest->print();
    std::cout << std::endl;

    /* Test remove absent*/
    rTest->remove("10");

    delete rTest;

}

int main()
{
    std::cout << "---------------"
        << " Registry<int, float>    test "
        << "---------------"
        << std::endl;

    testNumbers();

    std::cout << "\n\n---------------"
        << " Registry<string, float> test "
        << "---------------"
        << std::endl;
        
    testSymbols();

    return 0;
}

