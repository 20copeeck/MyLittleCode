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

		cout << "�������... \n";
		cout << "'1' - �������� ���������;\n";
		cout << "'2' - �������� �������;\n";
		cout << "'3' - �������� ������;\n";
		cout << "'Esc' - ��������� � ������ ������������ ������...\n\n";

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