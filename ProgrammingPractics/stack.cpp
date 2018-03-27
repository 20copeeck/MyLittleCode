#include "stdafx.h"
#include "stack.h"

using namespace std;

Stack* CreateStack()
{
	Stack* stack = new Stack;
	stack->bufsize = 2;
	stack->length = 0;
	stack->array = new int[stack->bufsize];
	return stack;
}

void Resize(Stack* stack)
{
	stack->bufsize *= 2;
	int* pdarr = new int[stack->bufsize];

	for (int i = 0; i < stack->length; i++)
	{
		pdarr[i] = stack->array[i];
	}
	delete[] stack->array;
	stack->array = pdarr;
}

void DelStack(Stack* stack)
{
	delete[] stack->array;
	delete stack;
}

void Push(Stack* stack, int value)
{
	if (stack->length == stack->bufsize)
	{
		Resize(stack);
	}
	stack->array[stack->length] = value;
	stack->length++;
}

int Pop(Stack* stack)
{
	stack->length--;
	return stack->array[stack->length];
}

int Top(Stack* stack)
{
	return stack->array[stack->length - 1];
}

void Show(Stack* stack)
{
	cout << "Стек: ";
	for (int i = 0; i < stack->length; i++)
	{
		cout << stack->array[i] << " ";
	}
	cout << endl;
	cout << "Длина Стека: " << stack->length << endl;
	cout << "Длина буфера: " << stack->bufsize << endl;
}

void LauncherLab4Stack()
{
	Stack* stack = CreateStack();
	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");

		Show(stack);

		cout << "\nНажмите... \n";
		cout << "'1' - Добавить элемент;\n";
		cout << "'2' - Удалить элемент;\n";
		cout << "'3' - Получить верхний элемент;\n";
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '1':
		{
			int value;
			cout << "Введите добавляемый элемент\n";
			value = СheckingСorrectness();
			Push(stack, value);

			break;
		}
		case '2':
		{
			try
			{
				if (stack->length <= 0)
				{
					throw 1;
				}
				Pop(stack);
			}
			catch (int i)
			{
				cout << "Ошибка №" << i << " - Стек пуст!" << endl;
				system("pause");
			}

			break;
		}
		case '3':
		{
			try
			{
				if (stack->length <= 0)
				{
					throw 1;
				}
				cout << "Полученный элемент: " << Top(stack) << endl;
			}
			catch (int i)
			{
				cout << "Ошибка №" << i << " - Стек пуст!" << endl;
			}

			system("pause");
			break;
		}
		}
	}
	DelStack(stack);
}