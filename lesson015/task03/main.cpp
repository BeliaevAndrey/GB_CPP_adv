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

#include <iostream>
#include <string>
#include <vector>

template<typename T1, typename T2>
struct RePair {
    T1 key;
    T2 val;

    RePair(T1 k, T2 v) {
        key = k;
        val = v;
    }
};

template<typename T1, typename T2>
class Registry {
private:
    std::vector<RePair<T1, T2>> storage;

public:
    void add(T1 k, T2 v)
    {
        storage.push_back(RePair<T1, T2>(k, v));
    }

    void remove(T1 k)
    {
        for (int i = 0; i < storage.size(); i++)
        {
            if (storage[i].key == k)
            {
                storage.erase(storage.begin() + i);
            }
        }
    }

    void print()
    {
        std::cout << "{";

        for (int i = 0; i < storage.size(); i++)
        {
            std::cout << storage.at(i).key << ": " << storage.at(i).val;
            if (i < storage.size() - 1)
                std::cout << ", ";

        }

        std::cout << "}" << std::endl;
    }

    std::vector<T2>* find(T1 k)
    {
        std::vector<T2>* tmp = new std::vector<T2>;
        for (int i = 0; i < storage.size(); i++)
            if (k == storage.at(i).key)
                tmp->push_back(storage.at(i).val);

        return tmp;
    }
};

int main()
{
    Registry<int, float>* rTest = new Registry<int, float>();

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

    rTest->print();
    std::cout << std::endl;

    std::vector<float>* findResult = rTest->find(100);

    for (int i = 0; i < findResult->size(); i++)
    {
        std::cout << findResult->at(i) << " ";

    }
    std::cout << std::endl;

    rTest->remove(10);

    findResult = rTest->find(10);
    if (findResult->size() > 0) {
        for (int i = 0; i < findResult->size(); i++)
        {
            std::cout << findResult->at(i) << " ";

        }
        std::cout << std::endl;
    }
    else std::cout << "not found" << std::endl;

    rTest->print();
    std::cout << std::endl;

    

    delete rTest;
    return 0;
}
