/*
Задание 1. Реализация продвинутого ввода и вывода дней недели
Что нужно сделать
Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу
этого дня недели в текстовом виде в консоль. В начале программы пользователь
вводит день недели в виде его порядкового номера. В результате в консоли
появляется буквенное отображение этого дня недели. В этом упражнении
запрещается использовать классические переменные, кроме как для хранения ввода
пользователя. Использовать строковые литералы напрямую тоже нельзя. Всё должно
быть реализовано исключительно на макросах.

Советы и рекомендации
Конкатенация двух фрагментов может породить токен, который в свою очередь
является именем макроса, и этот макрос тоже раскроется. Используйте это
свойство для перевода константы дня недели в строковый литерал. Обязательно
просмотрите итоговый код после препроцессинга из CLion с помощью Shift-Shift →
Preprocess current TU.
*/

#include <iostream>

using namespace std;

#define SUNDAY 7 
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#define READ_DAY(a)  { cout << "Input day number: "; cin >> a;}
#define PRINT_DAY(b) { cout << NAME_##b << endl; }
#define WRONG_DAY    { cout << "Wrong day number." << endl; }

#define NAME_SUNDAY ("Sunday")
#define NAME_MONDAY ("Monday")
#define NAME_TUESDAY ("Tueday")
#define NAME_WEDNESDAY ("Wednesday")
#define NAME_THURSDAY ("Thursday")
#define NAME_FRIDAY ("Friday")
#define NAME_SATURDAY ("Saturday")

int main()
{
    int dayNum;
    READ_DAY(dayNum);

    switch (dayNum)
    {
    case SUNDAY:    PRINT_DAY(SUNDAY);      break;
    case MONDAY:    PRINT_DAY(MONDAY);      break;
    case TUESDAY:   PRINT_DAY(TUESDAY);     break;
    case WEDNESDAY: PRINT_DAY(WEDNESDAY);   break;
    case THURSDAY:  PRINT_DAY(THURSDAY);    break;
    case FRIDAY:    PRINT_DAY(FRIDAY);      break;
    case SATURDAY:  PRINT_DAY(SATURDAY);    break;
    default: WRONG_DAY; break;
    }
    return 0;
}