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
		cout << "�������... \n";
		cout << "'0' - ������� ���������� �������� � ��������� ������;\n";
		cout << "'Esc' - ��������� � ������ ������������ ������...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
		{
			char str[50] = "";
			cout << "������� ������:\n";
			cin.getline(str, 50); 

			cout << "���������� �������� � ������ ����� " << GetLength(str) << endl;
			system("pause");
			break;
		}
		}
	}
}