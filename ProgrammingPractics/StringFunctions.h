#pragma once

void CopyString(char* string1, const char* string2); //������� �������� ������� �� ����� ������ � ������
void CopyString(char* string1, char* string2); 
int GetLength(const char* string); //������� ��� �������� ���-�� �������� � ��������� ������
int GetLength(char* string); 
char* Concatenate(char* string1, const char* string2); //�������, ������������ ��� ������ � ����
char* Concatenate(char* string1, char* string2);
char* GetSubstring(char* string, int startIndex, int charCount); //����� ���������
char* Uppercase(char* string); //��������� ������ � ������� �������
char* Lowercase(char* string); //��������� ������ � ������ �������