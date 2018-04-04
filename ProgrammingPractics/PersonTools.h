#pragma once
#include "PersonList.h"

class PersonTools
{
	public:
		static Person* ReadPerson();
		static void ShowPerson(Person* person);
		static Person* MakeRandomPerson();
};

static bool CheckChar(char* name);