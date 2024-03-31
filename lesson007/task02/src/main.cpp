/*
Задание 2. Проект симулятора работы компьютера

Что нужно сделать
Реализуйте простую модель работы персонального компьютера в качестве
многомодульного проекта. В компьютере несколько основных, условных компонент.

Центральный процессор (cpu) — должен иметь функцию
    * compute, которая складывает 8 чисел из буфера оперативной памяти
    (см. далее) и выводит результат в консоль.

Оперативная память (ram) — содержит буфер на 8 целых чисел,
    * которые можно заполнить функцией write
    * и считать функцией read

* Жёсткий диск (disk) — имеет в себе две функции, save и load.
    * save должна сохранить состояние 8 чисел из оперативной памяти на
    постоянный носитель в файл data.txt.
    * load — загрузить их с носителя в оперативную память.

* Графическая карта (gpu) — выводит в консоль 8 чисел из оперативной памяти.

* Клавиатура (kbd) — позволяет
    ввести 8  чисел и разместить их в оперативной памяти.

* Каждая компонента должна располагаться в отдельном модуле, с отдельным
заголовочным файлом. Основной модуль программы (main.cpp) должен считывать
пользовательский ввод команды, которая соответствует отдельным функциям
устройств:
   - sum      (вычисление суммы),
   - save     (сохранить в файл),
   - load     (загрузить из файла),
   - input    (ввести с клавиатуры),
   - display  (вывести на экран).
   - exit     (выход из программы).

Советы и рекомендации
Тщательно продумайте зависимости между модулями и теми файлами, которые должны
быть включены в исходные файлы. Не забывайте про #pragma once в заголовочных
файлах. В заголовочных файлах модулей располагайте только объявления функций.
Их определения должны быть уже в исходных файлах (CPP).

* Обращение к буферу оперативной памяти делается только через модуль ram,
    напрямую доступ к буферу не осуществляется.
* Программа и составленные CMake-файлы конфигурации проекта работают корректно.
* Для программы создано два файла CMakeLists.txt, один в основной директории,
    второй в директории src.
* В файлах CPP в поле всех #include-директив используется только название
    файла, не должно быть #include-директив с указанием папки. Не допускается:
```
../include/.. .h
D:/.../include/.. .h
```
*/

#include <iostream>

int main()
{

    return 0;
}