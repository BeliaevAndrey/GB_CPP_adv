/*
Задание 3. Анализ заполненности вагонов в поезде* (дополнительное Задание)

Что нужно сделать
В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20
пассажиров - это их оптимальное количество. Проанализируйте количество людей в
каждом вагоне и сначала сообщите об излишне заполненных вагонах, далее о
вагонах с пустыми пассажирскими местами. В заключение выведите общее количество
пассажиров во всех вагонах. При старте программы пользователь вводит количество
пассажиров в каждом вагоне. Замечания о вагонах должны выводиться в стандартную
консоль. При выполнении задания пользоваться нельзя напрямую пользоваться
for-циклами, только опосредованно, через макросы.
*/

#include <iostream>
#include <vector>


#define CALL(func, argA, argB, argC) { func(argA, argB, argC); }


using namespace std;

const int carsAmt = 10;
const int passLim = 20;

void addPassengers(vector<int>& train, int carsLeft, int stub) {

    if (carsLeft == 0) return;

    cout << "Car # "
        << (carsAmt - carsLeft + 1)
        << ". Input number of passengers:\t";
    int passAmt;
    cin >> passAmt;
    train.push_back(passAmt);

    CALL(addPassengers, train, carsLeft - 1, 0);


}

void print(string line, int amt, int num)
{
    std::cout << line << num << " " << amt << endl;
}


void analyze(vector<int>& train, int count, int total) {
    if (count == 0)
    {
        cout << "Totally pasengers: " << total << endl;
        return;
    }
    total += train[10 - count];

    if (train[carsAmt - count] < passLim)
    {
        CALL(print, "Underload car\t# ", train[carsAmt - count],
            carsAmt - count);
    }

    else if (train[carsAmt - count] > passLim)
    {
        CALL(print, "Overload  car\t# ", train[carsAmt - count],
            carsAmt - count);
    }
    else
        CALL(print, "Optimal   car\t# ", train[carsAmt - count],
            carsAmt - count);

    CALL(analyze, train, count - 1, total);


}

int main() {
    vector<int> train;

    CALL(addPassengers, train, carsAmt, 0);
    CALL(analyze, train, train.size(), 0);


    return 0;
}