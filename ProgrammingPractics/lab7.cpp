#include "stdafx.h"
#include "List.h"
#include "lab7.h"

using namespace std;

void LauncherLab7()
{
	char key;
	int ascii = 0;

	while (ascii != 27)
	{
		system("cls");

		cout << "Нажмите... \n";
		cout << "'1' - double;\n";
		cout << "'2' - Person*;\n";
		cout << "'3' - double[5];\n";
		cout << "'4' - List<double>;\n";
		cout << "'Esc' - Выйти из программы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			List<double> list;

			cout << "\n1) Добавим 6 элементов:\n";

			list.Add(3.8);
			list.Add(10.1);
			list.Add(0.2);
			list.Add(-5.07);
			list.Add(8.8);
			list.Add(-7.08);

			list.Show();

			cout << "2) Удалим третий элемент:\n";

			list.RemoveAt(2);
			list.Show();

			cout << "3) Добавим элемент по четвертому индексу:\n";

			list.InsertByIndex(-25.9, 3);
			list.Show();

			system("pause");
			break;
		}

		case '2':
		{
			List<Person*> list;

			cout << "\n1) Добавим 6 элементов:\n";

			list.Add(PersonTools::MakeRandomPerson());
			list.Add(PersonTools::MakeRandomPerson());
			list.Add(PersonTools::MakeRandomPerson());
			list.Add(PersonTools::MakeRandomPerson());
			list.Add(PersonTools::MakeRandomPerson());
			list.Add(PersonTools::MakeRandomPerson());

			list.Show();

			cout << "\n2) Удалим третий элемент:\n";

			list.RemoveAt(2);
			list.Show();

			cout << "\n3) Добавим элемент по четвертому индексу:\n";

			list.InsertByIndex(PersonTools::MakeRandomPerson(), 3);
			list.Show();

			system("pause");
			break;
		}

		case '3':
		{
			List<double*> list;

			double array1[] = { 11.6, 5.9, -11.08, -1.0, 22.8 };
			double array2[] = { 3.7, -101.98, -5.5, 9.01, 0.16 };
			double array3[] = { 39.2, 8.97, -1.2, 55.8, -505.1 };
			double array4[] = { 1.321, 9.4, -6.555, 0.1, -20.7 };
			double array5[] = { 1.4, -44.3, 6.222, -9.1, 1.76 };
			double array6[] = { 29.84, -12.69, 123.8, -5.1, 41.76 };
			double array7[] = { -50.04, 10.3, -1.123, 6.28, -0.76 };

			cout << "\n1) Добавим 6 элементов:\n";

			list.Add(array1);
			list.Add(array2);
			list.Add(array3);
			list.Add(array4);
			list.Add(array5);
			list.Add(array6);

			list.Show();

			cout << "\n2) Удалим третий элемент:\n";

			list.RemoveAt(2);
			list.Show();

			cout << "\n2) Добавим элемент по четвертому индексу:\n";

			list.InsertByIndex(array7, 3);
			list.Show();

			system("pause");
			break;
		}

		case '4':
		{
			List<List<double>*> list;

			List<double> list1;
			list1.Add(100.8);
			list1.Add(98.89);
			list1.Add(-500.1);
			list1.Add(-22.07);
			list1.Add(11.8);

			List<double> list2;
			list2.Add(53.4);
			list2.Add(9.9);
			list2.Add(15.16);
			list2.Add(-11.07);
			list2.Add(2.048);

			List<double> list3;
			list3.Add(3.1471);
			list3.Add(1.289);
			list3.Add(-17.0);
			list3.Add(47.91);
			list3.Add(-11.24);

			List<double> list4;
			list4.Add(-12.8);
			list4.Add(-77.0);
			list4.Add(22.2);
			list4.Add(19.7);
			list4.Add(-15.31);

			List<double> list5;
			list5.Add(-33.2);
			list5.Add(-10.85);
			list5.Add(51.12);
			list5.Add(49.88);
			list5.Add(0.18);

			List<double> list6;
			list6.Add(-3.4);
			list6.Add(9.8);
			list6.Add(-4.2);
			list6.Add(15.07);
			list6.Add(-4.65);

			List<double> list7;
			list6.Add(3.4);
			list6.Add(9.8);
			list6.Add(-9.2);
			list6.Add(5.07);
			list6.Add(-111.6);

			cout << "\n1) Добавим 6 элементов:\n";

			list.Add(&list1);
			list.Add(&list2);
			list.Add(&list3);
			list.Add(&list4);
			list.Add(&list5);
			list.Add(&list6);

			list.Show();

			cout << "\n2) Удалим третий элемент:\n";

			list.RemoveAt(2);
			list.Show();

			cout << "\n3) Добавим элемент по четвертому индексу:\n";

			list.InsertByIndex(&list6, 3);
			list.Show();

			system("pause");
			break;
		}
		}
	}
}