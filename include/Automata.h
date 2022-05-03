#pragma once
#include <string>
#include <vector>
using namespace std;

enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	int cash = 0;     // текущая сумма
	vector<string> menu; // названия напитков 
	vector<int> prices;  // стоимости напитков
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