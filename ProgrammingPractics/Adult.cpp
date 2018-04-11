#include "stdafx.h"
#include "Adult.h"
#include "PersonTools.h"
#include "StringFunctions.h"

Adult::Adult(char* name, char* surname, unsigned int age, Sex gender, Person* marriedOn, char* workPlace)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(gender);
	SetMarriedOn(marriedOn);
	SetWorkPlace(workPlace);
}

void Adult::SetAge(int age)
{
	if (age >= 18)
	{
		_age = age;
	}
	else
	{
		_age = 18;
	}
}

void Adult::SetMarriedOn(Person* marriedOn)
{
	_marriedOn = marriedOn;
}
void Adult::SetWorkPlace(char* workPlace)
{
	_workPlace = workPlace;
}

Person* Adult::GetMarriedOn()
{
	return _marriedOn;
}
char* Adult::GetWorkPlace()
{
	return _workPlace;
}

char* Adult::GetDescription()
{
	char* description = new char[200];
	*description = '\0';

	Concatenate(description, _name);
	Concatenate(description, " ");
	Concatenate(description, _surname);
	Concatenate(description, ", ");
	Concatenate(description, "возраст: ");

	char* stringAge = new char[10];
	_itoa_s(_age, stringAge, 10, 10);
	Concatenate(description, stringAge);
	delete stringAge;

	Concatenate(description, ", ");
	if (_gender)
	{
		Concatenate(description, "мужчина,");
	}
	else
	{
		Concatenate(description, " женщина,");
	}

	if (_marriedOn != nullptr)
	{
		Concatenate(description, " супруг(а): ");
		Concatenate(description, _marriedOn->GetName());
		Concatenate(description, " ");
		Concatenate(description, _marriedOn->GetSurname());
		Concatenate(description, ", ");
	}
	else
	{
		Concatenate(description, " одинок(а), ");
	}

	if (_workPlace != nullptr)
	{
		Concatenate(description, "должность: ");
		Concatenate(description, _workPlace);
		Concatenate(description, ".");
	}
	else
	{
		Concatenate(description, " без работы.");
	}

	return description;
}

Adult* Adult::MakeRandom()
{
	const char* nameMale[] = { "Игорь", "Олег", "Максим", "Павел", "Андрей", "Семен", "Дмитрий", "Сергей", "Федор", "Алексей", "Егор", "Владимир", "Иван", "Петр", "Владислав" };
	const char* nameFemale[] = { "Жанна", "Анна", "Юлия", "Виктория", "Ольга", "Наталья", "Галина", "Анастасия", "Кристина", "Алина", "Карина", "Дарья", "Анджела", "Диана", "Маргарита" };
	const char* surnameMale[] = { "Иванов", "Петров", "Павлецкий", "Максимов", "Жабин", "Богомолов", "Волков", "Попов", "Мишин", "Явлецкий", "Анреев", "Антропов", "Бегунов", "Винин", "Динисов" };
	const char* surnamesFemale[] = { "Иванова", "Петрова", "Павлецкая", "Максимова", "Жабина", "Богомолова", "Волкова", "Попова", "Мишина", "Явлецкая", "Андреевская", "Антропова", "Бегунова", "Винина", "Динисова" };
	const char* workPlace[] = { "охранник", "менеджер", "милиционер", "инженер", "консультант", "кассир", "бухгалтер", "врач", "страховой агент", "техник", "механик", "прораб", "воспитатель", "начальник отдела", "администратор" };

	char* tempName = new char[30];
	char* tempSurname = new char[30];
	char* tempWorkPlace;

	int tempAge = 18 + rand() % 72;
	enum Sex tempSex = enum Sex(rand() % 2);
	int genderValue = 0;
	Person* tempMarriedOn;

	if (tempSex == Women)
	{
		genderValue = 1;
	}

	if (rand() % 10)
	{
		tempMarriedOn = PersonTools::MakeRandomPerson((Sex)genderValue);
	}
	else
	{
		tempMarriedOn = nullptr;
	}
	
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

	if (rand() % 10)
	{
		tempWorkPlace = new char[30];
		CopyString(tempWorkPlace, workPlace[rand() % 15]);
	}

	return new Adult(tempName, tempSurname, tempAge, tempSex, tempMarriedOn, tempWorkPlace);
}