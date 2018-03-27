#pragma once

struct Stack 
{
	int* array;
	int length;
	int bufsize;
};

Stack* CreateStack(); //�������� �����
void Resize(Stack* st); //������������� ������
void DelStack(Stack* st); //�������� �����
void Push(Stack* stack, int value); //�������� ������� 
int Pop(Stack* stack); //������� �������
int Top(Stack* stack); //������ �������� ��������
void Show(Stack* stack); //����� ���������� � �����

void LauncherLab4Stack(); //������� �������