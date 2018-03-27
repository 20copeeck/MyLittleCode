#pragma once
#include "lab3.h"

struct Node
{
	Person* person; // TODO ���������� �� ��������� !����������!
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

int CheckingRange(int value1, int value2); //�������� �� ���������� �������� ��������
int GetLength(List* list); //���������� ����� ������ 
Person* MakeRandomPerson(); //���������� ���������� ���� Person, ������������������ ���������� �������
void AddLast(List* list, Person* person); //��������� � �����
void Show(List* list); //����� ������ �� �����
Node* GetAddress(Node* node, List* list, int index); //������ ������ ���������� �������� ������
void Remove(Node* node, List* list, int index); //�������� ���������� ��������
void Insert(Node* node, List* list, Person* person, int index); //��������� �������� �� ���������� �������
void Clear(Node* node, List* list); //������� ���������� ������

void LauncherLab4(); //������� ��� ������� ������������ �4