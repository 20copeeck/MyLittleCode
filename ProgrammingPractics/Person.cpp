#include "stdafx.h"
#include "Person.h"

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
	_age = age;
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