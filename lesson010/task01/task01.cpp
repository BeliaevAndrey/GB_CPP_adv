/*
Задание 1. Заплыв на 100 метров

Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров. Всего шесть дорожек и
шесть пловцов. Имена пловцов указываются в начале из стандартного ввода. Каждый
из них плывёт с разной скоростью, которая также задаётся пользователем при
старте, через стандартный ввод в метрах в секунду. Каждую секунду в стандартный
вывод выдаётся информация о том, сколько проплыл тот или иной пловец. Как
только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и
выводится таблица с итоговыми результатами, отсортированная по возрастанию
итогового времени заплыва.

Советы и рекомендации
Используйте нити для реализации движения каждого пловца в отдельности.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <thread>
#include <ctime>
#include <mutex>

const int POOL_PATHS_AMT = 6;
const double SWIM_DISTANCE = 100.0;

std::vector<std::string> finished;

std::mutex poolLock;
std::mutex printLock;

void readSwimmers(std::vector<std::string>& swimmers) {


    for (int i = 0; i < POOL_PATHS_AMT; i++)
    {
        std::string name = "swimmer # " + std::to_string(i + 1);
        swimmers.push_back(name);
    }
}

void swim(std::string name, double speed) {
    double metersDone = 0;
    int count = 0;
    poolLock.lock();
    std::cout << name << " starts speed: " << speed << std::endl;
    poolLock.unlock();

    while (SWIM_DISTANCE - metersDone > 0.1) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count++;
        metersDone += speed;
        printLock.lock();
        std::cout << name << " has swimmed " << metersDone << std::endl;
        printLock.unlock();

    }
    poolLock.lock();
    finished.push_back(name + " " + std::to_string(count) + " sec");
    poolLock.unlock();
}

int main()
{
    std::vector<std::string> swimmers;
    std::thread* poolPaths[POOL_PATHS_AMT];
    std::srand(std::time(nullptr));


    readSwimmers(swimmers);

    for (int i = 0; i < POOL_PATHS_AMT; i++)
    {
        double speed = 10 + std::rand() % 10;
        poolPaths[i] = new std::thread(swim, swimmers[i], speed);
    }

    for (int i = 0; i < POOL_PATHS_AMT; i++)
    {
        if (poolPaths[i]->joinable()) poolPaths[i]->join();
    }

    std::cout << "Finished: " << std::endl;
    for (int i = 0; i < finished.size(); i++)
        std::cout << finished[i] << std::endl;


    return 0;
}