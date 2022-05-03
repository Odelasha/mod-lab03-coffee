// Copyright 2020 GHA Test Team
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <string>
#include <vector>
using std::string;
using std::vector;

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
private:
    int cash = 0;     // текущая сумма
    vector<string> menu { "Latte", "Cappuccino", "Espresso" }; // названия напитков 
    vector<int> prices { 10, 12, 15 };  // стоимости напитков
    STATES state = STATES::OFF; // текущие состояние автомата

public:
    Automata();
    void on(); // включение автомата;
    void off(); // выключение автомата;
    void coin(int coins); // занесение денег на счёт пользователем;
    string getMenu(); // считывание меню с напитками и ценами для пользователя;
    STATES getState(); // считывание текущего состояния для пользователя;
    void choice(); // выбор напитка пользователем;
    bool check(string name); // проверка наличия необходимой суммы;
    void cancel(); // отмена сеанса обслуживания пользователем;
    void cook(); // имитация процесса приготовления напитка;
    void finish(); // завершение обслуживания пользователя.

    int getRest(); // остаток на счету
    void printState(STATES s); // вывод на экран состояний
    int work(string name, int coins, bool output = false); // рабочий процесс автомата
};

#endif  // INCLUDE_AUTOMATA_H_
