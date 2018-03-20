#pragma once

enum Sex
{
	Women,
	Men
};

struct Person
{
	char Surname[40];
	char Name[20];
	int Age;
	Sex Sex;
};

int СheckingСorrectness();  //Проверка на введение целочисленных значений