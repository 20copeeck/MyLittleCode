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

int CheckingRange(int value1, int value2); //�������� �� ���������� �������� ��������
void CopyString(char* string1, const char* string2); //������� ������������ ������ �� ����� ������ � ������
int GetLength(List* list); //���������� ����� ������ 
Person* MakeRandomPerson(); //���������� ���������� ���� Person, ������������������ ���������� �������
void AddLast(List* list, Person person); //��������� � �����
void Show(List* list); //����� ������ �� �����
Node* GetAddress(List* list); //������ ������ ���������� �������� ������
void Remove(List* list); //�������� ���������� ��������
void Insert(List* list, Person person); //��������� �������� �� ���������� �������
void Clear(List* list); //������� ���������� ������
void LauncherLab4(); //������� ��� ������� ������������ �4