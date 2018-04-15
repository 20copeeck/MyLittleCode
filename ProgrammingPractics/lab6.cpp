#include "stdafx.h"
#include "PersonList.h"
#include "lab6.h"

using namespace std;

void LauncherLab6()
{
	char key;						
	int ascii = 0;				
	
	PersonList list;
	
	while (ascii != 27)
	{
		system("cls");

		list.ShowDescription();

		cout << "Нажмите... \n";
		cout << "'1' - Добавить взрослого;\n";
		cout << "'2' - Добавить ребенка;\n";
		cout << "'3' - Очистить список;\n";
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			list.Add(Adult::MakeRandom());
			break;
		}
		case '2':
		{
			list.Add(Child::MakeRandom());
			break;
		}
		case '3':
		{
			list.Clear();
			break;
		}
		}
	}
}