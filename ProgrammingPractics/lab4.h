#pragma once

struct Node
{
	Person person;
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

int CheckingRange(int value1, int value2); //Проверка на допустимый диапазон значений
void CopyString(char* string1, const char* string2); //Функция переписывает данные из одной строки в другую
int GetLength(List* list); //Вычисление длины списка 
Person* MakeRandomPerson(); //Возвращает переменную типа Person, инициализированную случайными данными
void AddLast(List* list, Person person); //Добаление в конец
void Show(List* list); //Вывод списка на экран
Node* GetAddress(List* list); //Взятие адреса указанного элемента списка
void Remove(List* list); //Удаление указанного элемента
void Insert(List* list, Person person); //Помещение элемента по указанному индексу
void Clear(List* list); //Очищает содержимое списка
void LauncherLab4(); //Функция для запуска лабораторной №4