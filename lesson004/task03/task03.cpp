/*
Задание 3. Анаграммы
Что нужно сделать
Напишите функцию, которая принимает две строки и возвращает true,
если первая строка является анаграммой второй (то есть можно получить 
первую строку из второй путём перестановки букв местами), и false иначе. 
Для достижения хорошей асимптотики решения рекомендуется использовать 
std::map. Пример анаграммы:
лекарство — стекловар
*/

#include <iostream>
#include <string>
#include <map>

bool isAnagram(std::string &left, std::string &right)
{   
    if (left.length() != right.length())
        return false;

    std::map<char, int> letters;

    for (int i = 0; i < left.length(); i++)
    {
        if (letters.count(left[i]) > 0)
            letters[left[i]] += 1;
        else
            letters[left[i]] = 1;
    }

    for (int i = 0; i < right.length(); i++)
    {
        if (letters.count(right[i]) > 0)
        {
            letters.find(right[i])->second += 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string left, right;
    std::cout << "Enter first string: ";
    std::cin >> left;
    std::cout << "Enter second string: ";
    std::cin >> right;
    std::cout << std::boolalpha << isAnagram(left, right) << std::endl;

    return 0;
}