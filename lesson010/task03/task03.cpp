/*
Задание 3. Симуляция работы кухни онлайн-ресторана

Что нужно сделать
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в
режиме онлайн-доставки. Онлайн-заказ поступает каждые 5–10 секунд. Это
случайное блюдо из пяти: пицца, суп, стейк, салат, суши. Официант, принявший
заказ онлайн, оставляет его у кухни. Если кухня свободна, она принимает заказ и
спустя 5–15 секунд возвращает уже готовое блюдо на выдачу. Время определяется
случайным образом с помощью функции std::rand() в указанных диапазонах. Курьер
приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по
заказчикам. Программа завершается после 10 успешных доставок. На каждом из
этапов, будь то заказ, или готовка, или доставка заказа, выводятся
соответствующие сообщения в консоль.

Советы и рекомендации
Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с вызовом detach для неё.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <thread>
#include <ctime>
#include <mutex>

const int KITCHEN_LO_LIM = 5;
const int KITCHEN_UP_LIM = 15;
std::mutex orderLock;
std::mutex kitchenLock;

std::vector<std::string> dishes{ "Pizza", "Soup", "Steak", "Salad", "Sushi" };
std::vector<std::string> readyDishes;
int ordersFulfilled = 0;

void kitchen(std::string& dish) {
    kitchenLock.lock();
    int waitTime = (KITCHEN_LO_LIM + rand()) % KITCHEN_UP_LIM;
    std::this_thread::sleep_for(std::chrono::seconds(waitTime));
    readyDishes.push_back(dish);
    kitchenLock.unlock();
    std::cout << "Ready: " << dish << std::endl;
}

void order() {
    int dishIndex = std::rand() % dishes.size();
    orderLock.lock();
    std::string dish = dishes[dishIndex];
    orderLock.unlock();
    kitchen(dish);
}

void courier() {
    std::this_thread::sleep_for(std::chrono::seconds(30));
    if (!readyDishes.empty()) {
        orderLock.lock();
        std::string dish = readyDishes.front();
        readyDishes.erase(readyDishes.begin());
        ordersFulfilled++;
        std::cout << dish << " taken" << std::endl;
    }
    orderLock.unlock();
}

int main()
{
    std::srand(std::time(nullptr));

    while (ordersFulfilled < 10) {

        std::thread threadOrder(order);
        std::thread threadCourier(courier);

        threadOrder.detach();
        threadCourier.detach();

        if (threadOrder.joinable()) threadOrder.join();
        if (threadCourier.joinable()) threadCourier.join();
    }

    std::cout << "All done" << std::endl;
    return 0;
}