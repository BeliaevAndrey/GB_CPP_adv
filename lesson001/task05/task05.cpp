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

const std::string path = "/large/data2/Home/Andrew/Documents/geekbrains/CPP_advanced/lesson001/task05/letters/";

std::ifstream letter;
const int buffSize = 81;

int main()
{
    void printScores(int, int);
    void readAndPrintQuestion(int);
    std::string readAnswer(int);

    int sectors = 13; // sectors amt
    int curSect = 0;  // current sector
    int count = 0;    // count moves
    int expertsScore = 0, tvViewersScore = 0;
    char buffer[buffSize];

    std::string question;
    std::string answer, expertAnswer;

    while (count < sectors)
    {
        int secOffs = 0; // sector offset
        std::cout << "Input offset (int, -2 -- exit): ";
        std::cin >> secOffs;

        if (secOffs == -2)
        {
            std::cout << "Exiting..." << std::endl;
            if (count > 0)
                tvViewersScore++;
            break;
        }

        ++count;

        curSect = (curSect + secOffs) % 13;

        readAndPrintQuestion(curSect);

        answer = readAnswer(curSect);

        std::cout << "Input your answer (-2 -- exit): ";
        std::cin >> expertAnswer;

        if (expertAnswer == "-2")
        {
            std::cout << "Exiting..." << std::endl;
            tvViewersScore++;
            break;
        }

        if (answer == expertAnswer)
            expertsScore++;
        else
            tvViewersScore++;

        printScores(expertsScore, tvViewersScore);
    }

    std::cout << "Final score: " << std::endl;
    std::cout << "Experts score:   " << expertsScore << std::endl;
    std::cout << "TV viewers score: " << tvViewersScore << std::endl;

    return 0;
}

void readAndPrintQuestion(int curSect)
{
    int position = 0;

    std::string fullPath;

    /* Read question */
    if (curSect < 10)
        fullPath = path + "q00" + std::to_string(curSect) + ".txt";
    else
        fullPath = path + "q0" + std::to_string(curSect) + ".txt";

    letter.open(fullPath, std::ios::binary);

    std::cout << "Question " << curSect + 1 << ": " << std::endl;

    while (!letter.eof())
    {
        char buffer[buffSize];

        letter.seekg(position);
        letter.read(buffer, buffSize);

        position += letter.gcount();

        for (int i = 0; i < buffSize; i++)
        {
            std::cout << buffer[i];
            buffer[i] = 0;
        }
    }
    std::cout << std::endl;

    letter.close();
}

std::string readAnswer(int curSect)
{

    std::string fullPath;
    std::string answer;

    /* Read answer */
    if (curSect < 10)
        fullPath = path + "a00" + std::to_string(curSect) + ".txt";
    else
        fullPath = path + "a0" + std::to_string(curSect) + ".txt";

    letter.open(fullPath, std::ios::binary);

    letter >> answer;

    letter.close();

    return answer;
}

void printScores(int expertsScore, int tvViewersScore)
{

    std::cout << "Scores: " << std::endl;
    std::cout << "Experts           |"
              << "TV viewers        " << std::endl;
    std::cout << expertsScore
              << "                 |"
              << tvViewersScore
              << std::endl;
}