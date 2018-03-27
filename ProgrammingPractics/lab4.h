#pragma once
#include "lab3.h"

struct Node
{
	Person* person; // TODO переписать на указатели !ИСПРАВЛЕНО!
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

int CheckingRange(int value1, int value2); //Проверка на допустимый диапазон значений
int GetLength(List* list); //Вычисление длины списка 
Person* MakeRandomPerson(); //Возвращает переменную типа Person, инициализированную случайными данными
void AddLast(List* list, Person* person); //Добаление в конец
void Show(List* list); //Вывод списка на экран
Node* GetAddress(Node* node, List* list, int index); //Взятие адреса указанного элемента списка
void Remove(Node* node, List* list, int index); //Удаление указанного элемента
void Insert(Node* node, List* list, Person* person, int index); //Помещение элемента по указанному индексу
void Clear(Node* node, List* list); //Очищает содержимое списка

void LauncherLab4(); //Функция для запуска лабораторной №4