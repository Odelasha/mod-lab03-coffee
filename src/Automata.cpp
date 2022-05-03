#include "Automata.h"
#include <fstream>
#include <iostream>

Automata::Automata()
{
	ifstream fin{ "coffee.txt" };
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string str;
			fin >> str;
			this->menu.push_back(str);
			fin >> str;
			this->prices.push_back(stoi(str));
		}
	}
	fin.close();
}

void Automata::on()
{
	this->state = STATES::WAIT;
}

void Automata::off()
{
	this->state = STATES::OFF;
}

void Automata::coin(int coins)
{
	this->cash += coins;
	this->state = STATES::ACCEPT;
}

string Automata::getMenu()
{
	string str = "";
	for (size_t i = 0; i < size(this->menu); ++i)
		str += this->menu[i] + ": " + to_string(this->prices[i]) + "\n";
	return str;
}

STATES Automata::getState()
{
	return this->state;
}

void Automata::choice()
{
	this->state = STATES::CHECK;
}

bool Automata::check(string name)
{
	auto it = find(this->menu.begin(), this->menu.end(), name);
	auto ind = distance(this->menu.begin(), it);
	if (this->cash >= this->prices[ind])
	{
		this->cash -= this->prices[ind];
		return true;
	}
	return false;
}

void Automata::cancel()
{
	this->state = STATES::WAIT;
}

void Automata::cook()
{
	this->state = STATES::COOK;
}

void Automata::finish()
{
	this->state = STATES::WAIT;
}

int Automata::getRest()
{
	return this->cash;
}

void Automata::printState(STATES s)
{
	switch (s)
	{
	case STATES::WAIT:
		cout << "Машина ожидает заказа..." << endl;
		break;
	case STATES::ACCEPT:
		cout << "Приём денег..." << endl;
		break;
	case STATES::CHECK:
		cout << "Проверка наличности..." << endl;
		break;
	case STATES::COOK:
		cout << "Приготовление напитка..." << endl;
		break;
	case STATES::OFF:
		cout << "Аппарат выключен." << endl;
		break;
	default:
		break;
	}
}

int Automata::work(string name, int coins, bool output)
{
	if(output)
		printState(this->getState());
	on(); 
	if (output)
		printState(this->getState());
	
	coin(coins); 
	if (output)
		printState(this->getState());

	choice(); 
	if (output)
		printState(this->getState());
	if (!check(name))
	{
		finish(); 
		if (output)
			printState(this->getState());
		return getRest();
	}
	else
	{
		cook(); 
		if (output)
			printState(this->getState());
	}
	finish(); 
	if (output)
		printState(this->getState());
	off(); 
	if (output)
		printState(this->getState());
	return getRest();
}