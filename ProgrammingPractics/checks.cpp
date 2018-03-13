#include "stdafx.h"

using namespace std;

int ÑheckingÑorrectness()
{
	int value;
	bool isGood = true;
	do
	{
		cin >> value;
		if (!(isGood = cin.good()))
			cout << "Îøèáêà. Íåêîððåêòíûé ñèìâîë!" << "\n" << "Ïîâòîðèòå ââîä: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!isGood);

	return value;
}