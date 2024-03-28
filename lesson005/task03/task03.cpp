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


#define ADD_PASSENGERS(func)(a) { readAmounts(&a, int carsLeft = carsAmt) }

#define CALL(func, sArg, iArg) { func(string sArg, int &iArg); }
  // todo sample for adapt-n



using namespace std;

const int carsAmt = 10;
const int passLim = 20;

void readAmounts(vector<int>& train, int carsLeft = carsAmt) {
    if (carsLeft == 0) return;

    cout << "Car # "
        << carsAmt - carsLeft + 1
        << ". Input number opf PASSENGERS: ";
    int PASSENGERS;
    cin >> PASSENGERS;
    train.push_back(PASSENGERS);

    readAmounts(train, carsLeft - 1);


}

void print(std::string str, int& pAmt, int& cNum) {
    cout << "Car # " << cNum << " "
        << str << " "
        << pAmt << endl;
}


void analyze(vector<int>& train) {
    int total = 0;

    for (int i = 0; i < train.size(); i++)
    {
        total += train[i];
    }

    float optimum = total / carsAmt;

    for (int i = 0; i < train.size(); i++)
    {
        total += train[i];
        (train[i] > passLim) ?
            print("Overload", train[i], i) :
            (train[i] == passLim) ?
            print("Optimal", train[i], i) :
            print("Underload", train[i], i);
    }
    cout << "Totally pasengers: " << total << endl;
}

int main() {
    // CALL(print); // todo sample for adapt-n
    vector<int> train;
    readAmounts(train);
    analyze(train);


    return 0;
}