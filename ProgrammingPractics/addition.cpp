#include "stdafx.h"

using namespace std;

int �hecking�orrectness()
{
	int value;
	bool isGood = true;
	do
	{
		cin >> value;
		if (!(isGood = cin.good()))
			cout << "������. ������������ ������!" << "\n" << "��������� ����: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!isGood);

	return value;
}