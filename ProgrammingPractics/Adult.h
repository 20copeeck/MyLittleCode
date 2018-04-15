#pragma once
#include "Person.h"

class Adult : public Person
{
private:
	Person* _marriedOn = nullptr;
	char* _workPlace = nullptr;
public:
	Adult(char* name, char* surname, unsigned int age, Sex gender, Person* marriedOn, char* workPlace);
	
	void SetMarriedOn(Person* marriedOn);
	void SetWorkPlace(char* workPlace);
	void SetAge(unsigned int age) override;
	
	char* GetDescription() override; 
	char* GetWorkPlace();
	Person* GetMarriedOn();

	static Adult* MakeRandom();
};