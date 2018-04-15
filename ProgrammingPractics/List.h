#pragma once
#include "Person.h"
#include "PersonTools.h"

using namespace std;

template <typename TList>
class List
{
	private:
		template <typename TNode>
		class ListItem
		{
			private:
				TNode _value;
			public:
				ListItem()
				{};
				ListItem(TNode temp)
				{
					_value = temp;
				}
				TNode GetValue()
				{
					return _value;
				}
				ListItem<TNode>* Next = nullptr;
				ListItem<TNode>* Prev = nullptr;
		};
		ListItem<TList>* _head = nullptr;
		ListItem<TList>* _tail = nullptr;
		int _count = 0;
	public:
		List() {}; //конструктор класса

		void Add(TList data) //добавление в конец списка
		{
			ListItem<TList>* temp = new ListItem<TList>(data);
			if (_head == nullptr)
			{
				_head = _tail = temp;
			}
			else
			{
				temp->Prev = _tail;
				_tail->Next = temp;
				_tail = temp;
			}
			_count++;
		}; 

		void InsertByIndex(TList data, int index) // добавление по индексу
		{
			if (_head == nullptr || index < 0)
			{
				return;
			}

			ListItem<TList>* temp = _head;
			int i = 0;
			while (i < index)
			{
				temp = temp->Next;
				i++;
				if (temp == nullptr)
				{
					Add(data);
					return;
				}
			};


			if (temp == _head)
			{
				ListItem<TList>* newNode = new ListItem<TList>();
				_head->Prev = newNode;
				newNode->Next = _head;

				_head = newNode;
				return;
			}

			if (temp == _tail)
			{
				ListItem<TList>* newNode = new ListItem<TList>(data);
				_tail->Prev->Next = newNode;
				newNode->Prev = _tail->Prev;
				newNode->Next = _tail;
				_tail->Prev = newNode;
				_tail->Next = nullptr;
				return;
			}


			if (temp != nullptr)
			{
				ListItem<TList>* newNode = new ListItem<TList>(data);
				temp->Prev->Next = newNode;
				newNode->Prev = temp->Prev;
				newNode->Next = temp;
				temp->Prev = newNode;
			}
			return;
		}

		TList Find(int index) //поиск по указанному индексу
		{
			if (index < 0)
			{
				return nullptr;
			}

			ListItem<TList>* searchedItem = _head;

			for (int i = 0; i < index; i++)
			{
				if (searchedItem->Next != nullptr)
				{
					searchedItem = searchedItem->Next;
				}
			}

			return searchedItem->GetValue();
		}; 

		int IndexOf(TList data) //вернуть индекс человека, если он есть в списке
		{
			ListItem<TList>* searchedPerson = _head;
			int index = 0;
			while (searchedPerson != nullptr)
			{
				if (searchedPerson->GetValue() == data)
				{
					return index;
				}
				index++;
				searchedPerson = searchedPerson->Next;
			}
			return -1;
		}; 

		int GetCount() //получить количество элементов
		{
			return _count;
		}; 

		void Remove(TList data) //удалить из списка
		{
			PersonListItem* deletedItem = _head;

			if (data)
			{
				while (deletedItem->GetValue() != data)
				{
					if (deletedItem->Next == nullptr)
					{
						return;
					}
					deletedItem = deletedItem->Next;
				}
			}
			else
			{
				return;
			}

			if (deletedItem->Prev)
			{
				deletedItem->Prev->Next = deletedItem->Next;
			}
			else
			{
				_head = deletedItem->Next;
			}
			if (deletedItem->Next)
			{
				deletedItem->Next->Prev = deletedItem->Prev;
			}
			else
			{
				_tail = deletedItem->Prev;
			}
			delete deletedItem;
		};

		void RemoveAt(int index) //удалить из списка по индексу
		{
			ListItem<TList>* deletedItem = _head;

			if (index >= 0)
			{
				for (int i = 0; i < index; i++)
				{
					if (deletedItem->Next == nullptr)
					{
						return;
					}
					deletedItem = deletedItem->Next;
				}
			}
			else
			{
				return;
			}

			if (deletedItem->Prev)
			{
				deletedItem->Prev->Next = deletedItem->Next;
			}
			else
			{
				_head = deletedItem->Next;
			}
			if (deletedItem->Next)
			{
				deletedItem->Next->Prev = deletedItem->Prev;
			}
			else
			{
				_tail = deletedItem->Prev;
			}

			delete deletedItem;
		}; 

		void Show()
		{
			ListItem<TList>* temp = _head;

			if (temp)
			{
				cout << "\n\t—писок:\n";
				cout << "---------------------------------------\n";
				cout << "»ндекс";
				cout.width(18); 
				cout << "ƒанные\n\n";

				int index = 0;

				while (temp)
				{
					cout << index++;
					cout << "\t\t" << temp->GetValue() << endl;
					temp = temp->Next;
				}
				cout << "---------------------------------------\n";
			}
			else
			{
				cout << "—писок пуст\n";
			}
			cout << endl;
		};

		void Clear() //очистить список
		{
			ListItem<TList>* temp = _head;
			ListItem<TList>* tempNext;

			while (temp != nullptr)
			{
				tempNext = temp->Next;
				delete temp;
				temp = tempNext;
			}
			_head = nullptr;
			_tail = nullptr;
			_count = 0;
		}; 

		~List() //деструктор
		{
			Clear();
		};

		friend std::ostream & operator<<(std::ostream &ostream, List<TList>* list)
		{
			ListItem<TList>* temp = list->_head;
			while (temp)
			{
				ostream << temp->GetValue() << ' ';
				temp = temp->Next;
			}
			return ostream;
		}
};

ostream& operator << (ostream &ostream, Person* person)
{
	ostream << '{' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << '}';
	return ostream;
}

ostream & operator<<(ostream &ostream, double* doubl)
{
	for (int i = 0; i < 5; i++)
	{
		ostream << doubl[i] << ' ';
	}
	return ostream;
}
