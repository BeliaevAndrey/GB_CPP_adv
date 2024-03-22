/*
Задание 5. Реализация игры «Что? Где? Когда?»

Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?». Как
происходит игра В начале каждого хода игроки вращают волчок, то есть выбирают
сектор на столе, который сейчас играет. Всего таких секторов 13. Сектор
выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего
сектора на барабане. Исходя из этого офсета вычисляется новый активный сектор,
который и будет играть в этом ходе. Если выпавший сектор уже играл, выбирает
следующий не игравший за ним. В начале всей игры стрелка установлена на первом
секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то
есть считывается из файла данного сектора. Вопрос показывается на экране. После
того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот
ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом,
который хранится во втором файле, ассоциированном с активным сектором. Данный
файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если
неверен, то балл уходит телезрителям. Игра продолжается до тех пор, пока или
игрок, или зрители не наберут шесть баллов. После этого называется победитель и
программа заканчивает работу.
*/

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream letter;

    std::string path = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson001/task05/letters/";
    int sectors = 13; // sectors amt
    int curSect = 1;  // current sector
    int secOffs = 0;  // sector offset
    std::string question;
    std::string answer;

    std::cout << "Input offset (int): ";
    std::cin >> secOffs;

    curSect = (curSect + secOffs) % 13;
    std::cout << curSect << std::endl;

    if (curSect < 10)
    {
        std::cout << "LESSER"
                  << std::endl
                  << "q00" + std::to_string(curSect) + ".txt"
                  << std::endl;
        path += "q00" + std::to_string(curSect) + ".txt";
    }
    else
    {
        std::cout << "LARGER"
                  << std::endl
                  << "q0" + std::to_string((curSect) % 13) + ".txt";
        path += "q0" + std::to_string(curSect) + ".txt";
    }
    std::cout << path << std::endl;
    letter.open(path);
    std::cout << "Opened: " << letter.is_open() << std::endl;
    letter >> question;

    std::cout << std::endl
              << "Question "
              << curSect
              << " "
              << question
              << std::endl;

    letter.close();

    return 0;
}