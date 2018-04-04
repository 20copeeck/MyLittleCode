#pragma once
#include "person.h"

class PersonList
{
	private:
		class PersonListItem
		{
			private:
				Person* _value;
			public:
				PersonListItem(Person* person)
				{
					_value = person;
				}
				Person* GetValue()
				{
					return _value;
				}
				PersonListItem* Next = nullptr;
				PersonListItem* Prev = nullptr;
		};
		PersonListItem* _head = nullptr;
		PersonListItem* _tail = nullptr;
		int _count = 0;
	public:
		PersonList() {}; //конструктор класса
		void Add(Person* person); //добавить человека в список
		Person* Find(int index); //найти человека по указанному индексу
		int IndexOf(Person* person); //вернуть индекс человека, если он есть в списке
		int GetCount(); //получить количество элементов

		void Remove(Person* person); //удалить человека из списка
		void RemoveAt(int index); //удалить человека из списка по индексу

		void Show();
		void Clear(); //очистить список
};
