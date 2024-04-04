/*
Задание 2. Симуляция работы вокзала
Что нужно сделать
С помощью многопоточности реализуйте простую модель железнодорожного вокзала. С
трёх точек отправления в разное время отбывают три разных поезда с условными
обозначениями A, B, C. Все они идут на один и тот же вокзал и могут дойти до
него в разное время. На этом целевом вокзале единовременно может находиться
только один поезд. Остальные поезда должны ждать, пока уже занятое место
освободится. В начале программы пользователь последовательно вводит для
каждого поезда время в пути до вокзала (в секундах). После этого поезда
начинают своё движение за заданное количество времени. Как только поезд прибыл
на вокзал, он ожидает от пользователя команды depart, которая сигнализирует о
его отбытии с вокзала. По всем событиям (прибытие на вокзал, ожидание
свободного места, отбытие с вокзала) вместе с условным обозначением поезда
выводятся сообщения в консоль. Программа завершается, когда на вокзале
побывают все три поезда.

Советы и рекомендации
Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <ctime>
#include <mutex>

std::mutex trainLock;
std::mutex flagLock;
int TRAINS_AMT = 3;
bool occupied = false;

void station(char* train) {
    std::cout << "Train " << train << " arrived" << std::endl;
    std::string command = "";
    flagLock.lock();
    occupied = true;
    while (occupied) {
        std::cout << "Waiting for 'depart' command: ";
        std::cin >> command;
        if (command == "depart")
        {
            flagLock.unlock();
            occupied = false;
        }
    }
    trainLock.unlock();
}

void trainMove(char train, int distance) {
    std::cout << "Train " << train << " started" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(distance));
    if (occupied) std::cout << "\nTrain " << train << " waits" << std::endl;
    trainLock.lock();
    station(&train);
}

int main()
{
    char trainIDs[]{ 'A', 'B','C' };
    int distance[3];
    std::thread* trains[TRAINS_AMT];

    for (int i = 0; i < TRAINS_AMT; i++)
    {
        std::cout << "Input train distance: ";
        std::cin >> distance[i];
    }

    for (int i = 0; i < TRAINS_AMT; i++)
    {
        trains[i] = new std::thread(trainMove, trainIDs[i], distance[i]);
    }

    for (int i = 0; i < TRAINS_AMT; i++)
    {
        trains[i]->join();
    }
    return 0;
}