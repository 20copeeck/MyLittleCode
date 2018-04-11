#include "stdafx.h"
#include "Child.h"
#include "PersonTools.h"
#include "StringFunctions.h"

Child::Child(char* name, char* surname, unsigned int age, Sex gender, Person* mother, Person* father, char* school)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(gender);
	SetMother(mother);
	SetFather(father);
	SetSchool(school);
}

void Child::SetAge(int age)
{
	if (age < 18)
	{
		_age = age;
	}
	else
	{
		_age = 17;
	}
}

void Child::SetMother(Person* mother)
{
	_mother = mother;
}
void Child::SetFather(Person* father)
{
	_father = father;
}
void Child::SetSchool(char* school)
{
	_school = school;
}

Person* Child::GetMother()
{
	return _mother;
}
Person* Child::GetFather()
{
	return _father;
}
char* Child::GetSchool()
{
	return _school;
}

char* Child::GetDescription()
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

	Concatenate(description, ",");
	if (_gender)
	{
		Concatenate(description, " мальчик,");
	}
	else
	{
		Concatenate(description, " девочка,");
	}

	if (_mother && _father)
	{
		Concatenate(description, " родители: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, " и ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ",");
	}
	else if (_mother)
	{
		Concatenate(description, " мама: ");
		Concatenate(description, _mother->GetName());
		Concatenate(description, " ");
		Concatenate(description, _mother->GetSurname());
		Concatenate(description, ",");
	}
	else if (_father)
	{
		Concatenate(description, " папа: ");
		Concatenate(description, _father->GetName());
		Concatenate(description, " ");
		Concatenate(description, _father->GetSurname());
		Concatenate(description, ",");
	}
	else
	{
		Concatenate(description, " родители не указаны,");
	}

	Concatenate(description, " место учебы: ");
	Concatenate(description, _school);
	Concatenate(description, ".");

	return description;
}

Child* Child::MakeRandom()
{
	const char* nameMale[] = { "Игорь", "Олег", "Максим", "Павел", "Андрей", "Семен", "Дмитрий", "Сергей", "Федор", "Алексей", "Егор", "Владимир", "Иван", "Петр", "Владислав" };
	const char* nameFemale[] = { "Жанна", "Анна", "Юлия", "Виктория", "Ольга", "Наталья", "Галина", "Анастасия", "Кристина", "Алина", "Карина", "Дарья", "Анджела", "Диана", "Маргарита" };
	const char* surnameMale[] = { "Иванов", "Петров", "Павлецкий", "Максимов", "Жабин", "Богомолов", "Волков", "Попов", "Мишин", "Явлецкий", "Анреев", "Антропов", "Бегунов", "Винин", "Динисов" };
	const char* surnamesFemale[] = { "Иванова", "Петрова", "Павлецкая", "Максимова", "Жабина", "Богомолова", "Волкова", "Попова", "Мишина", "Явлецкая", "Андреевская", "Антропова", "Бегунова", "Винина", "Динисова" };
	const char* school[] = { "Эрудит", "Знайка", "Умник", "Эврикум", "Гениус", "Логос", "Ителлект", "Эйнштейн", "Вираж", "Гений", "Атом", "Парадигма", "Энигма", "Средняя образовательная школа №321", "Высшая школа знаний" };
	
	char* tempName = new char[30];
	char* tempSurname = new char[30];
	char* tempSchool = new char[30];
	Person* tempMother;
	Person* tempFather;
	int value1 = rand() % 2;
	int value2 = rand() % 2;

	int tempAge = 1 + rand() % 17;
	enum Sex tempSex = enum Sex(rand() % 2);

	if (value1 == 0)
	{
		tempMother = nullptr;
	}
	else
	{
		tempMother = PersonTools::MakeRandomPerson(Women);
	}

	if (value2 == 0)
	{
		tempFather = nullptr;
	}
	else
	{
		tempFather = PersonTools::MakeRandomPerson(Men);
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

	CopyString(tempSchool, school[rand() % 15]);

	return new Child(tempName, tempSurname, tempAge, tempSex, tempMother, tempFather, tempSchool);
}
