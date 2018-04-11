#pragma once

enum Sex
{
	Women,
	Men
};

class Person
{
	protected:
		char* _name;
		char* _surname;
		int _age;
		Sex _gender;
	public:
		Person() {};
		Person(char* name, char* surname, unsigned int age, Sex gender);

		void SetName(char* name);
		void SetSurname(char* surname);
		void SetAge(unsigned int age);
		void SetSex(Sex gender);

		char* GetName();
		char* GetSurname();
		int GetAge();
		Sex GetSex();
		char* GetDescription();
		
		~Person();
};