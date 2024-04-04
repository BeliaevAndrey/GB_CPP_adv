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
const int ORDER_LO_LIM = 5;
const int ORDER_UP_LIM = 10;
const int COURIER_WAIT = 30;
const int ORDERS_AIM = 11;
std::mutex orderLock;
std::mutex kitchenLock;

std::vector<std::string> menu{ "Pizza", "Soup", "Steak", "Salad", "Sushi" };
std::vector<std::string> ordersWait;
std::vector<std::string> readyDishes;
int ordersComplete = 0;

void kitchen() {
    int waitTime = (KITCHEN_LO_LIM + rand()) % KITCHEN_UP_LIM;
    kitchenLock.lock();
    std::string dish = ordersWait.front();
    std::cout << "kitchen got order: " << dish << std::endl;
    ordersWait.erase(ordersWait.begin());
    std::this_thread::sleep_for(std::chrono::seconds(waitTime));
    readyDishes.push_back(dish);
    kitchenLock.unlock();
    std::cout << "Ready: " << dish
        << "Oders complete: "
        << ordersComplete << std::endl;
}

void order() {
    int orderDelay = (ORDER_UP_LIM + rand()) % ORDER_UP_LIM;
    std::this_thread::sleep_for(std::chrono::seconds(orderDelay));
    int menuIndex = std::rand() % menu.size();
    orderLock.lock();
    ordersWait.push_back(menu[menuIndex]);
    orderLock.unlock();
}

void courier() {
    std::this_thread::sleep_for(std::chrono::seconds(COURIER_WAIT));
    if (!readyDishes.empty()) {
        orderLock.lock();
        std::string dish = readyDishes.front();
        readyDishes.erase(readyDishes.begin());
        ordersComplete++;
        std::cout << dish << " taken." << std::endl;
    }
    orderLock.unlock();
}

int main()
{
    std::srand(std::time(nullptr));

    while (ordersComplete < ORDERS_AIM) {
        std::thread threadOrder(order);
        std::thread threadCourier(courier);

        threadCourier.join();

        threadOrder.detach();
        if (threadOrder.joinable()) threadOrder.join();

        if (!ordersWait.empty())
        {
            std::thread threadKitchen(kitchen);
            threadKitchen.detach();
            if (threadKitchen.joinable()) threadKitchen.join();
        }
    }

    std::cout << "All done" << std::endl;
    return 0;
}