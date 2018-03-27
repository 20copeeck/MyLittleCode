#pragma once

struct Stack 
{
	int* array;
	int length;
	int bufsize;
};

Stack* CreateStack(); //Создание стека
void Resize(Stack* st); //Перевыделение буфера
void DelStack(Stack* st); //Удаление стека
void Push(Stack* stack, int value); //Добавить элемент 
int Pop(Stack* stack); //Удалить элемент
int Top(Stack* stack); //Взятие верхнего элемента
void Show(Stack* stack); //Вывод инофрмации о стеке

void LauncherLab4Stack(); //Функция запуска