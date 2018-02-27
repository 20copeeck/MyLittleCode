#include "lab2.h"
#include "stdafx.h"

using namespace std;

int �hecking�orrectness()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
			cout << "������!!!" << "\n" << "������� ����� �����: " << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);

	return value;
}

void PrintHelloWorld()
{
	cout << "Hello, World!\n";
}

double MakeCalculation(int value1, int value2, char operationKey)
{
	if (operationKey == '+')
	{
		return (value1 + value2);
	}
	else if (operationKey == '-')
	{
		return (value1 - value2);
	}
	else if (operationKey == '*')
	{
		return (value1 * value2);
	}
	else if (operationKey == '/')
	{
		return ((double)value1 / value2);
	}
	else if (operationKey == '%')
	{
		return (value1 % value2);
	}
}

void LauncherLab2()
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");
		cout << "�������... \n";
		cout << "'0' - ������� �� ����� 'Hello World'; \n";
		cout << "'1' - ��������� �����������; \n";
		cout << "������� Esc ��� ������. \n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
			PrintHelloWorld();
			system("pause");
			break;
		case '1':
		{
			int value2, value1;

			cout << "������� 1-�� ������������� ��������: ";
			value1 = �hecking�orrectness();

			cout << "������� 2-�� ������������� ��������: ";
			value2 = �hecking�orrectness();

			char key;
			cout << "������� ���� �� ���������� (+, -, *, /, %): ";
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\n�������� ������!!!\n����������, ������� (+, -, *, /, %): ";
				key = _getch();
				fflush(stdin); 
			}
			cout << "\n" << value1 << " " << key << " " << value2 << " = " << MakeCalculation((int)value1, value2, key) << endl;

			system("pause");
			break;
		}
		}
	}
}