#include "stdafx.h"
#include "lab4.h"
#include <Windows.h>

using namespace std;

int CheckingRange(int value1, int value2)
{
	while (value1 < 0 || value1 >= value2)
	{
		cout << "Выход за пределы допустимых значений!\nПовторите ввод: ";
		value1 = СheckingСorrectness();
	}
	return value1;
}

void CopyString(char* string1, const char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

int GetLength(List* list)
{
	Node* node = list->head;
	int length = 0;

	while (node)
	{
		length++;
		node = node->next;
	}

	return length;
}

Person* MakeRandomPerson()
{
	const char* nameMale[] = { "Игорь", "Олег", "Максим", "Павел", "Андрей", "Семен", "Дмитрий", "Сергей", "Федор", "Алексей", "Егор", "Владимир", "Иван", "Петр", "Владислав" };
	const char* nameFamale[] = { "Жанна", "Анна", "Юлия", "Виктория", "Ольга", "Наталья", "Галина", "Анастасия", "Кристина", "Алина", "Карина", "Дарья", "Анджела", "Диана", "Маргарита" };
	const char* surnameMale[] = { "Иванов", "Петров", "Павлецкий", "Максимов", "Жабин", "Богомолов", "Волков", "Попов", "Мишин", "Явлецкий", "Анреев", "Антропов", "Бегунов", "Винин", "Динисов" };
	const char* surnamesFamale[] = { "Иванова", "Петрова", "Павлецкая", "Максимова", "Жабина", "Богомолова", "Волкова", "Попова", "Мишина", "Явлецкая", "Андреевская", "Антропова", "Бегунова", "Винина", "Динисова" };

	Person person;
	person.Sex = Sex(rand() % 2);
	person.Age = 18 + rand() % 92; 

	if (person.Sex == 1)
	{
		CopyString(person.Name, nameMale[rand() % 15]);
		CopyString(person.Surname, surnameMale[rand() % 15]);
	}
	else
	{
		CopyString(person.Name, nameFamale[rand() % 15]);
		CopyString(person.Surname, surnamesFamale[rand() % 15]);
	}
	return &person;
}

void AddLast(List* list, Person person)
{
	Node* newNode = new Node;
	newNode->person = person;

	if (list->head != NULL)
	{
		list->tail->next = newNode;
		newNode->prev = list->tail;
	}
	else
	{
		list->head = newNode;
	}
	list->tail = newNode;
}

void Show(List* list)
{
	Node* node = list->head;

	if (node)
	{
		cout << "\t\t\t\tСписок:\n\n";
		
		cout.width(12); cout << "Индекс";
		cout.width(12); cout << "Имя";
		cout.width(12); cout << "Фамилия";
		cout.width(12); cout << "Возраст";
		cout.width(12); cout << "Пол\n";

		int index = 0;

		while (node)
		{
			cout.width(12); cout << index++;
			cout.width(12); cout << node->person.Name;
			cout.width(12); cout << node->person.Surname;
			cout.width(12); cout << node->person.Age;
			cout.width(12);
			if (node->person.Sex == 0)
			{
				cout << "Женщина\n";
			}
			else
			{
				cout << "Мужчина\n";
			}
			node = node->next;
		}
	}
	else
	{
		cout << "\t\t\t\tСписок пуст" << endl;
	}
	cout << endl;
}

Node* GetAddress(List* list)
{
	Node* node = list->head;

	if (node)
	{
		int index;
		cout << "Адрес какого элемента необходимо получить? (От 0 до " << GetLength(list) - 1 << ")\n";
		index = СheckingСorrectness();
		index = CheckingRange(index, GetLength(list));

		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}
	}
	else
	{
		cout << "Список пуст!" << endl;
		return 0;
	}
	return node;
}

void Remove(List* list)
{
	Node* node = list->head;
	
	if (node)
	{
		int index;
		cout << "Какой элемент удалить? (От 0 до " << GetLength(list) - 1 << ")\n";
		index = СheckingСorrectness();
		index = CheckingRange(index, GetLength(list));

		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		if (node->prev != NULL)
		{
			node->prev->next = node->next;
		}
		else
		{
			list->head = node->next;
		}
		if (node->next != NULL)
		{
			node->next->prev = node->prev;
		}
		else
		{
			list->tail = node->prev;
		}
		delete node;

	}
	else
	{
		cout << "Список пуст!" << endl;
		system("pause");
	}
}

void Insert(List* list, Person person)
{
	Node* node = list->head;
	Node* newNode = new Node;
	newNode->person = person;
	int index;

	if (node)
	{
		cout << "На какую позицию вставить элемент? (От 0 до " << GetLength(list) - 1 << ")\n";
		index = СheckingСorrectness();
		index = CheckingRange(index, GetLength(list));

		for (int i = 0; i < index; i++)
		{
			node = node->next;
		}

		if (node->prev == NULL)
		{
			list->head = newNode;
		}
		else
		{
			node->prev->next = newNode;
			newNode->prev = node->prev;
		}
		node->prev = newNode;
		newNode->next = node;
	}
	else
	{
		list->head = newNode;
	}
}

void Clear(List* list)
{
	Node* node = list->head;

	if (node)
	{
		while (node->next)
		{
			node = node->next;
			delete node->prev;
		}
		delete node;

		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		cout << "Список и так пуст!" << endl;
		system("pause");
	}
}

void LauncherLab4()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int ascii = 0;
	char key;
	List* list = new List;

	while (ascii != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 13);
		Show(list);

		SetConsoleTextAttribute(hStdOut, 14);
		cout << "Нажмите... \n";
		SetConsoleTextAttribute(hStdOut, 10);
		cout << "'0' - Добавить в конец;\n";
		cout << "'1' - Вывести адрес указанного элемента;\n";
		cout << "'2' - Удалить указанный элемент;\n";
		cout << "'3' - Вставка элемента по указанному индексу;\n";
		cout << "'4' - Очистить содержимое списка;\n";
		SetConsoleTextAttribute(hStdOut, 12);
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		SetConsoleTextAttribute(hStdOut, 15);
		switch (ascii)
		{
		case '0':
		{
			AddLast(list, *MakeRandomPerson());

			break;
		}
		case '1':
		{
			Node* node = GetAddress(list);
			
			if (node != 0)
			{
				cout << "Получен адрес: " << node << endl;
			}
			
			system("pause");
			break;
		}
		case '2':
		{	
			Remove(list);
			break;
		}
		case '3':
		{
			Insert(list, *MakeRandomPerson());
			break;
		}
		case '4':
		{
			Clear(list);
			break;
		}
		}
	}
}