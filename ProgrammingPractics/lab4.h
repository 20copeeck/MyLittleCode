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

void LauncherLab4();
void CopyString(char* string1, const char* string2);
Person* MakeRandomPerson();
void AddLast(List* list, Person person);
void Show(List* list);
int GetLength(List* list);
Node* GetAddress(List* list);
int CheckingRange(int value1, int value2);
void Insert(List* list, Person person);
void Clear(List* list);