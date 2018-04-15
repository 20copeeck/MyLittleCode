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

int FindSubstring(char* string, char* substring); //Поиск подстроки в строке
void SplitFilename(char* source, char* path, char* name, char* extension); //Разбиение ресурса на путь, имя и расширение
char* ReplaceTabsOnSpaces(char* string); //Замена символов табуляции на пробелы
char* ReplaceSpacesOnTabs(char* string); //Замена пробелов на символы табуляции
bool isNeedTab(char* string, int i, int tab); //Проверяет есть ли сиволы в диапазоне(можно ли сделать табуляцию)
Person ReadPerson(); //Занесение данных в структуру
void PrintPerson(Person person); //Вывод данных из структуры на экран

void LauncherLab3(); //Функция для запуска меню лабы №3