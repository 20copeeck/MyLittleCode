#include "stdafx.h"
#include "PersonTools.h"
#include "CopyString.h"

using namespace std;

bool CheckChar(char* name)
{
	bool isTrueName = true;
	for (int i = 0; i < strlen(name); i++)
	{
		if (isdigit(name[i]) || isspace(name[i]))
		{
			isTrueName = false;
			break;
		}

		if (name[i] == '-')
		{
			if (islower(name[i + 1]))
			{
				name[i + 1] = toupper(name[i + 1]);
			}
			else
			{
				isTrueName = false;
				break;
			}
		}
	}
	return isTrueName;
}

ostream& operator << (ostream &ostream, Person* person)
{
	ostream << '{' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << '}';
	return ostream;
}

istream& operator >> (istream& is, Person* person)
{
	char* tempName = new char[20];
	char* tempSurname = new char[20];
	int tempAge;
	int tempSex;

	bool key = true;

	while (key)
	{
		cout << endl << "Введите имя(только латиница): ";
		cin >> tempName;
		key = !CheckChar(tempName);
	}

	person->SetName(tempName);
	key = true;

	while (key)
	{
		cout << endl << "Введите фамилию(только латиница): ";
		cin >> tempSurname;
		key = !CheckChar(tempSurname);
	}

	person->SetSurname(tempSurname);

	cout << endl << "Введите пол (0 - женщина, 1 - мужчина): ";
	do
	{
		tempSex = СheckingСorrectness();
	} while (tempSex != 0 && tempSex != 1);

	person->SetSex((Sex)tempSex);

	cout << endl << "Введите возраст: ";
	tempAge = СheckingСorrectness();
	person->SetAge(tempAge);

	return is;
}

Person* PersonTools::ReadPerson()
{
	Person* person = new Person();
	cin >> person;

	return person;
}

void PersonTools::ShowPerson(Person* person)
{
	cout << "\nИтог: " << person << endl;
}

Person* PersonTools::MakeRandomPerson()
{
	const char* nameMale[] = { "Игорь", "Олег", "Максим", "Павел", "Андрей", "Семен", "Дмитрий", "Сергей", "Федор", "Алексей", "Егор", "Владимир", "Иван", "Петр", "Владислав" };
	const char* nameFemale[] = { "Жанна", "Анна", "Юлия", "Виктория", "Ольга", "Наталья", "Галина", "Анастасия", "Кристина", "Алина", "Карина", "Дарья", "Анджела", "Диана", "Маргарита" };
	const char* surnameMale[] = { "Иванов", "Петров", "Павлецкий", "Максимов", "Жабин", "Богомолов", "Волков", "Попов", "Мишин", "Явлецкий", "Анреев", "Антропов", "Бегунов", "Винин", "Динисов" };
	const char* surnamesFemale[] = { "Иванова", "Петрова", "Павлецкая", "Максимова", "Жабина", "Богомолова", "Волкова", "Попова", "Мишина", "Явлецкая", "Андреевская", "Антропова", "Бегунова", "Винина", "Динисова" };

	char* tempName = new char[30];
	char* tempSurname = new char[30];
	int tempAge = 1 + rand() % 95;
	enum Sex tempSex = enum Sex(rand() % 2);

	if (tempSex)
	{
		CopyString(tempName, nameMale[rand() % 15]);
		CopyString(tempSurname, surnameMale[rand() % 15]);
	}
	else
	{
		CopyString(tempName, nameFemale[rand() % 15]);
		CopyString(tempSurname, surnamesFemale[rand() % 15]);
	}
	return new Person(tempName, tempSurname, tempAge, tempSex);
}