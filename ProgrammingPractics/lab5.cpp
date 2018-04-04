#include "stdafx.h"
#include "PersonTools.h"

using namespace std;

void LauncherLab5()
{
	int ascii = 0;
	char key;

	PersonList list1;
	list1.Add(PersonTools::MakeRandomPerson());
	list1.Add(PersonTools::MakeRandomPerson());
	list1.Add(PersonTools::MakeRandomPerson());
	list1.Add(PersonTools::MakeRandomPerson());

	PersonList list2;
	list2.Add(PersonTools::MakeRandomPerson());
	list2.Add(PersonTools::MakeRandomPerson());
	list2.Add(PersonTools::MakeRandomPerson());
	list2.Add(PersonTools::MakeRandomPerson());

	while (ascii != 27)
	{
		system("cls");

		cout << "\t\tЛист 1 ";
		list1.Show();
		cout << "\t\tЛист 2 ";
		list2.Show();

		cout << "Нажмите... \n";
		cout << "'0' - Добавить в конец первого списка;\n";
		cout << "'1' - Скопировать второго из первого списка во второй;\n";
		cout << "'2' - Удалить второго из первого списка;\n";
		cout << "'3' - Очистить первый список;\n";
		cout << "'4' - Ввод-вывод персоны;\n";
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
		{
			list1.Add(PersonTools::MakeRandomPerson());
			break;
		}
		case '1':
		{
			list2.Add(list1.Find(1));
			break;
		}
		case '2':
		{
			list1.RemoveAt(1);
			break;
		}
		case '3':
		{
			list1.Clear();
			break;
		}
		case '4':
		{
			Person* person = PersonTools::ReadPerson();
			PersonTools::ShowPerson(person);

			system("pause");
			break;
		}
		}
	}
}