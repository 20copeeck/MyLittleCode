#include "lab2.h"
#include "stdafx.h"

using namespace std;

int ÑheckingÑorrectness()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
			cout << "Îøèáêà!!!" << "\n" << "ÂÂÅÄÈÒÅ ÖÅËÎÅ ×ÈÑËÎ: " << endl;
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
		cout << "Íàæìèòå... \n";
		cout << "'0' - Âûâåñòè íà ýêðàí 'Hello World'; \n";
		cout << "'1' - Çàïóñòèòü êàëüêóëÿòîð; \n";
		cout << "Íàæìèòå Esc äëÿ âûõîäà. \n\n";

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

			cout << "Ââåäèòå 1-îå öåëî÷èñëåííîå çíà÷åíèå: ";
			value1 = ÑheckingÑorrectness();

			cout << "Ââåäèòå 2-îå öåëî÷èñëåííîå çíà÷åíèå: ";
			value2 = ÑheckingÑorrectness();

			char key;
			cout << "Ââåäèòå îäèí èç îïåðàòîðîâ (+, -, *, /, %): ";
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\nÍÅÂÅÐÍÛÉ ÑÈÌÂÎË!!!\nÏîæàëóéñòà, ââåäèòå (+, -, *, /, %): ";
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