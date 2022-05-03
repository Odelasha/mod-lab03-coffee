#include "Automata.h"
#include <iostream>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "rus");
	Automata coffee{};
	cout << coffee.getMenu();
	cout << coffee.work("Latte", 17, true);
	system("pause");
	return 0;
}
