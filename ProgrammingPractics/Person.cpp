#include "stdafx.h"
#include "Person.h"
#include "StringFunctions.h"

Person::Person(char* name, char* surname, unsigned int age, enum Sex gender)
{
	SetName(name);
	SetSurname(surname);
	SetAge(age);
	SetSex(gender);
};

void Person::SetName(char* name)
{
	_name = name;
}
void Person::SetSurname(char* surname)
{
	_surname = surname;
}
void Person::SetAge(unsigned int age)
{
	if (age > 0)
	{
		_age = age;
	}
	else
	{
		_age = 1;
	}
}
void Person::SetSex(enum Sex gender)
{
	_gender = gender;
}

char* Person::GetName()
{
	return _name;
}
char* Person::GetSurname()
{
	return _surname;
}
int Person::GetAge()
{
	return _age;
}
Sex Person::GetSex()
{
	return _gender;
}

char* Person::GetDescription()
{
	char* description = new char[200];
	*description = '\0';

	Concatenate(description, _name);
	Concatenate(description, " ");
	Concatenate(description, _surname);
	Concatenate(description, ", ");

	char* stringAge = new char[10];
	_itoa_s(_age, stringAge, 10, 10);
	Concatenate(description, stringAge);
	delete stringAge;

	Concatenate(description, " years old, ");
	if (_gender)
	{
		Concatenate(description, " male.");
	}
	else
	{
		Concatenate(description, " female.");
	}

	return description;
}

Person::~Person()
{
	delete _name;
	delete _surname;
};