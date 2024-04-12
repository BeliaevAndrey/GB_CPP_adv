/*
Задача 2. Анализ данных о фильмах

Используя модель данных из задачи №1, создайте JSON-документ, но теперь уже для
пяти различных кинолент. Ключи в этой JSON-базе данных должны быть названиями
фильмов, а значениями служить уже словари с информацией о картинах. Загрузите
базу данных в C++-программу для последующего анализа. Предусмотрите следующий
функционал: поиск актёра по имени (или фамилии) и вывод в консоль названий
кинолент, в которых снимался актёр, и роль, которую он исполнял.

Что оценивается
Валидность созданного JSON-документа с базой данных о фильмах. Корректность
работы программы поиска актёра.
*/

#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"

void readFile(std::string& filename, nlohmann::json& dict) {
    std::ifstream srcFile(filename);

    if (!srcFile.is_open())
    {
        std::cout << "File " << filename
            << " not found. Exiting..."
            << std::endl;
        exit(0);
    }

    srcFile >> dict;

    srcFile.close();
}


void searchActor(std::string& name, nlohmann::json& dict)
{
    for (auto it = dict.begin(); it != dict.end(); ++it) {
        nlohmann::json inner = it.value()["Cast"];
        for (auto inIt = inner.begin(); inIt != inner.end(); ++inIt)
        {
            if (inIt.key().find(name) < inIt.key().length())
            {
                std::cout << it.value()["Common"]["Title"] << std::endl;
                std::cout << inIt.key() << "\t\t";
                std::cout << inIt.value() << std::endl << std::endl;
            }
        }
    }
}



int main()
{
    nlohmann::json dict;
    std::string filename = "films_manual.json";
    readFile(filename, dict);

    std::string name = "Rutger";
    std::cout << "Input name and/or surname of the actor: ";
    std::getline(std::cin, name);

    searchActor(name, dict);

    return 0;
}