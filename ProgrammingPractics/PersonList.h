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
		PersonList() {}; //����������� ������
		void Add(Person* person); //�������� �������� � ������
		Person* Find(int index); //����� �������� �� ���������� �������
		int IndexOf(Person* person); //������� ������ ��������, ���� �� ���� � ������
		int GetCount(); //�������� ���������� ���������

		void Remove(Person* person); //������� �������� �� ������
		void RemoveAt(int index); //������� �������� �� ������ �� �������

		void Show();
		void Clear(); //�������� ������
};
