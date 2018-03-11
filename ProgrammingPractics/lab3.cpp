#include "lab3.h"
#include "stdafx.h"

using namespace std;

int GetLength(char* string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

void LauncherLab3()
{
	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");
		cout << "Нажмите... \n";
		cout << "'0' - Подсчет количества символов в введенной строке;\n";
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
		{
			char str[50] = "";
			cout << "Введите строку:\n";
			cin.getline(str, 50); 

			cout << "Количество символов в строке равно " << GetLength(str) << endl;
			system("pause");
			break;
		}
		}
	}
}