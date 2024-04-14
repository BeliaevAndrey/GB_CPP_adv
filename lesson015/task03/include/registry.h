#pragma once

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
    void add(T1 k, T2 v);

    void remove(T1 k);

    void print();

    std::vector<T2>* find(T1 k);
};


template<typename T1, typename T2>
void Registry<T1, T2>::add(T1 k, T2 v)
{
    storage.push_back(RePair<T1, T2>(k, v));
}

template<typename T1, typename T2>
void Registry<T1, T2>::remove(T1 k)
{
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i].key == k)
        {
            storage.erase(storage.begin() + i);
        }
    }
}

template<typename T1, typename T2>
void Registry<T1, T2>::print()
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

template<typename T1, typename T2>
std::vector<T2>* Registry<T1, T2>::find(T1 k)
{
    std::vector<T2>* tmp = new std::vector<T2>;
    for (int i = 0; i < storage.size(); i++)
        if (k == storage.at(i).key)
            tmp->push_back(storage.at(i).val);

    return tmp;
}
