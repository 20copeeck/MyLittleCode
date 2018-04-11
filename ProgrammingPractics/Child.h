#pragma once
#include "Person.h"

class Child : public Person
{
private:
	Person* _mother; 
	Person* _father;
	char* _school;
public:
	Child(char* name, char* surname, unsigned int age, Sex gender, Person* mother, Person* father, char* school);
	
	void SetMother(Person* mother);
	void SetFather(Person* father);
	void SetSchool(char* school);
	void SetAge(int age);

	Person* GetMother();
	Person* GetFather();
	char* GetSchool();
	char* GetDescription();

	static Child* MakeRandom();
};