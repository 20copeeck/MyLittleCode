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

int FindSubstring(char* string, char* substring); //����� ��������� � ������
void SplitFilename(char* source, char* path, char* name, char* extension); //��������� ������� �� ����, ��� � ����������
char* ReplaceTabsOnSpaces(char* string); //������ �������� ��������� �� �������
char* ReplaceSpacesOnTabs(char* string); //������ �������� �� ������� ���������
bool isNeedTab(char* string, int i, int tab); //��������� ���� �� ������ � ���������(����� �� ������� ���������)
Person ReadPerson(); //��������� ������ � ���������
void PrintPerson(Person person); //����� ������ �� ��������� �� �����

void LauncherLab3(); //������� ��� ������� ���� ���� �3