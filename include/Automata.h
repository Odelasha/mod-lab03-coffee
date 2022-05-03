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
	int cash = 0;     // ������� �����
	vector<string> menu; // �������� �������� 
	vector<int> prices;  // ��������� ��������
	STATES state = STATES::OFF; // ������� ��������� ��������

public:
	Automata();
	void on(); // ��������� ��������;
	void off(); // ���������� ��������;
	void coin(int coins); // ��������� ����� �� ���� �������������;
	string getMenu(); // ���������� ���� � ��������� � ������ ��� ������������;
	STATES getState(); // ���������� �������� ��������� ��� ������������;
	void choice(); // ����� ������� �������������;
	bool check(string name); // �������� ������� ����������� �����;
	void cancel(); // ������ ������ ������������ �������������;
	void cook(); // �������� �������� ������������� �������;
	void finish(); // ���������� ������������ ������������.

	int getRest(); // ������� �� �����
	void printState(STATES s); // ����� �� ����� ���������
	int work(string name, int coins, bool output = false); // ������� ������� ��������
};