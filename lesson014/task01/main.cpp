/*
Задача 1. Информация о фильме с кинопортала
Задача
Запишите подробную информацию о киноленте в виде JSON-файла. Выберите 
понравившуюся вам картину на любимом портале, проанализируйте информацию о ней 
и составьте JSON-словарь. В информации должны присутствовать: страна и дата 
создания киноленты, студия, которая вела съёмки, автор сценария, режиссёр и 
продюсер киноленты. Обязательно добавьте информацию обо всех главных 
действующих лицах и тех актёрах, которые их сыграли.

Что оценивается
Валидность созданного JSON-документа.

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


#include "nlohmann/json.hpp"

nlohmann::json dict;

void putData(std::string key, std::string line, std::string section)
{
    if (key.length() > 0)
        dict[section][key] = line.substr(0, line.length() - 1);
}


void readFile(std::string& filename)
{

    std::ifstream srcFile(filename);
    std::string line;
    std::string section;
    char ch;

    if (!srcFile.is_open())
    {
        std::cout << "File \"" << filename << "\" not found! Exiting..."
            << std::endl;
        exit(0);
    }

    std::string key;
    std::string words;
    while (srcFile.get(ch))
    {
        line += ch;
        char prev = '\0';
        while (ch != '\n' && !srcFile.eof())
        {
            srcFile.get(ch);
            if (ch != ' ')
                line += ch;
            else if (prev != ' ')
                line += ' ';
            prev = ch;
            if (line.length() > 3 && line.substr(line.length() - 2) == ": ")
            {
                key = line.substr(0, line.length() - 2);
                line = "";
            }
            if (line.length() > 3 && line.substr(line.length() - 1) == ":")
            {
                if (line == "Common:" ||
                    line == "Crew:" ||
                    line == "Cast:")
                {
                    line.pop_back();
                    section = line;
                    line = "";
                    key = "";
                }
            }
            if (line.length() > 3 && line.substr(line.length() - 3) == " - ") {
                key = line.substr(0, line.length() - 3);
                line = "";
            }
        }
        putData(key, line, section);
        line = "";
    }
}

int main()
{
    std::ofstream fileOut("film_auto.json");

    std::string filename("draft_film.txt");
    readFile(filename);


    fileOut << dict;



    return 0;
}

