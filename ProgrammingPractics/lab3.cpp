#include "stdafx.h"
#include "lab3.h"

using namespace std;


int GetLength(char* string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

char* Concatenate(char* string1, char* string2)
{
	char* doubleStr = new char[GetLength(string1) + GetLength(string2) + 1];
	int i = 0, j = 0;

	for (i; string1[i]; i++)
	{
		doubleStr[i] = string1[i];
	}
	for (j; string2[j]; j++)
	{
		doubleStr[i + j] = string2[j];
	}

	doubleStr[i + j] = '\0';
	return doubleStr;
}

char* GetSubstring(char* string, int startIndex, int charCount)
{
	if (startIndex < 0 || charCount < 1 || startIndex + charCount > GetLength(string))
	{
		return NULL;
	}
	else
	{
		char* substring = new char[GetLength(string) + 1];
		int i = 0;

		for (i; i < charCount; i++)
		{
			substring[i] = string[startIndex + i];
		}

		substring[i] = '\0';
		return substring;
	}
}

int FindSubstring(char* string, char* substring)
{
	int j = 0;
	for (int i = 0; string[i]; i++)
	{
		if (string[i] == substring[j])
		{
			while (string[++i] == substring[++j])
			{
				if (!substring[j + 1])
				{
					return i - j;
				}
			}
			i -= j;
			j = 0;
		}
	}
	return -1;
}

char* Uppercase(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		if ((string[i] > 96) && (string[i] < 123))
		{
			string[i] -= 32;
		}
	}
	return string;
}
char* Lowercase(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		if ((string[i] > 64) && (string[i] < 91))
		{
			string[i] += 32;
		}
	}
	return string;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int slash = 0, point = 0, j = 0, length = GetLength(source) + 1;
	for (int i = 0; source[i]; i++)
	{
		if (source[i] == 92)
		{
			slash = i;
		}
		if (source[i] == '.')
		{
			point = i;
		}
	}
	if (slash + 1 != point)
	{
		if (point == 0)
		{
			point = length;
		}
		else if (slash != 0)
		{
			slash++;
		}
		for (j = 0; j < slash; j++)
		{
			path[j] = source[j];
		}
		j = 0;
		for (slash; slash < point; slash++)
		{
			name[j] = source[slash];
			j++;
		}
		j = 0;
		for (point; point < length; point++)
		{
			extension[j] = source[point];
			j++;
		}
	}
	else
	{
		path[0] = 'N'; path[1] = 'U'; path[2] = 'L'; path[3] = 'L';
		name[0] = 'N'; name[1] = 'U'; name[2] = 'L'; name[3] = 'L';
		extension[0] = 'N'; extension[1] = 'U'; extension[2] = 'L'; extension[3] = 'L';
	}
}

bool isNeedTab(char* string, int i, int tab)
{
	while (i % tab != 0)
	{
		if (string[i] != ':')
		{
			return false;
		}
		i++;
	}
	return true;
}
char* ReplaceTabsOnSpaces(char* string)
{
	char* resultString = new char[100];
	int i = 0;
	int j = 0;

	for (i; string[i]; i++)
	{
		if (string[i] == '\t')
		{
			for (j; (i + j + 1) % 8 != 0; j++)
			{
				resultString[i + j] = ':';
			}
			resultString[i + j] = ':';
		}
		else
		{
			resultString[i + j] = string[i];
		}
	}
	resultString[i + j] = '\0';
	return resultString;
}
char* ReplaceSpacesOnTabs(char* string)
{
	char* result = new char[50];
	int tab = 8;
	int i = 0;
	int j = 0;

	for (; string[i + j]; i++)
	{
		if (string[i + j] == ':' && isNeedTab(string, i + j + 1, tab))
		{
			while ((i + j + 1) % 8 != 0)
			{
				j++;
			}
			result[i] = '\t';
		}
		else
		{
			result[i] = string[i + j];
		}
	}
	result[i] = '\0';
	return result;
}

Person ReadPerson()
{
	Person people;
	cout << "Введите фамилию: ";
	cin.getline (people.Surname, 40);
	cout << "Введите имя: ";
	cin.getline (people.Name, 20);
	cout << "Введите возраст: ";
	cin >> people.Age;
	cout << "Выберите пол:\n0 - Женщина\n1 - Мужчина\n";

	int i;
	do
	{
		i = СheckingСorrectness();
	} while (i != 0 && i != 1);
	switch (i)
	{
	case 0:
		people.SexPeople = Женщина;
		break;
	case 1:
		people.SexPeople = Мужчина;
		break;
	default:
		cout << "Ошибка, повторите ввод:" << endl;
		break;
	}
	return people;
}
void PrintPerson(Person person)
{
	cout << "Фамилия: " << person.Surname << "\n";
	cout << "Имя: " << person.Name << "\n";
	cout << "Возраст: " << person.Age << "\n";
	if (person.SexPeople == 0)
	{
		cout << "Пол: Женский" << endl;
	}
	else
	{
		cout << "Пол: Мужской" << endl;
	}
}

void LauncherLab3()
{
	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");
		cout << "Нажмите... \n";
		cout << "'0' - Подсчет количества символов в введенной строке;\n";
		cout << "'1' - Объединение двух строк;\n";
		cout << "'2' - Вывод подстроки;\n";
		cout << "'3' - Поиск подстроки в строке;\n";
		cout << "'4' - Перевести строку в верхний регистр;\n";
		cout << "'5' - Перевести строку в нижний регистр;\n";
		cout << "'6' - Разбиение ресурса на путь, имя и расширение;\n";
		cout << "'7' - Замена символов табуляции на пробелы;\n";
		cout << "'8' - Замена пробелов на символы табуляции;\n";
		cout << "'9' - Записать данные в структуру и вывести на экран;\n";
		cout << "'Esc' - Вернуться к выбору лабораторной работы...\n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
		{
			char str[50] = "";
			cout << "Введите строку:\n";
			cin.getline(str, 50); 
			cout << "Количество символов в строке равно " << GetLength(str) << endl;

			system("pause");
			break;
		}
		case '1':
		{
			char str1[30] = "";
			char str2[30] = "";

			cout << "Введите первую строку:\n";
			cin.getline(str1, 30);
			cout << "Введите вторую строку:\n";
			cin.getline(str2, 30);
			char* doubleStr = Concatenate(str1, str2);
			cout << doubleStr << endl;

			delete[] doubleStr;
			system("pause");
			break;
		}
		case '2':
		{
			char str[50] = "";
			int index = 0, count = 0;

			cout << "Введите строку:\n";
			cin.getline(str, 50);
			cout << "С какой позиции начать вывод? (Допустимый диапазон: от 0 до " << GetLength(str) - 1 << ")\n";
			index = СheckingСorrectness();
			cout << "Сколько символов вывести?\n";
			count = СheckingСorrectness();

			char* substring = GetSubstring(str, index, count);
			if (substring == NULL)
			{
				cout << "NULL" << endl;
			}
			else
			{
				cout << substring << endl;
			}

			delete[] substring;
			system("pause");
			break;
		}
		case '3':
		{
			char str[50] = "";
			char substring[50] = "";
			cout << "Введите строку:\n";
			cin.getline(str, 50);
			cout << "Введите искомую подстроку:\n";
			cin.getline(substring, 50);
			cout << FindSubstring(str, substring) << endl;

			system("pause");
			break;
		}
		case '4':
		{
			char str[100] = "";
			cout << "Введите строку:\n";
			cin.getline(str, 100);
			cout << "Ваша строка в верхнем регистре:\n" << Uppercase(str) << endl;

			system("pause");
			break;
		}
		case '5':
		{
			char str[100] = "";
			cout << "Введите строку:\n";
			cin.getline(str, 100);
			cout << "Ваша строка в нижнем регистре:\n" << Lowercase(str) << endl;

			system("pause");
			break;
		}
		case '6':
		{
			char sourse[100] = "";
			char path[50] = "";
			char name[50] = "";
			char extension[50] = "";
			cout << "Ресурс:\n";
			cin.getline(sourse, 100);
			SplitFilename(sourse, path, name, extension);
			cout << "Путь: " << path << "\nИмя: " << name << "\nРасширение: " << extension << endl;


			system("pause");
			break;
		}
		case '7':
		{
			char str[100] = "Cake\t\tis a lie! ";
			cout << "!\t!\t!\t!\t!\t!\t!\t!\n" << str << "\n";
			char* result = ReplaceTabsOnSpaces(str);
			cout << result << endl;

			delete[] result;
			system("pause");
			break;
		}
		case '8':
		{
			char str[100] = "Cake::::is::::a:lie!";
			cout << "!\t!\t!\t!\t!\t!\t!\t!\n" << str << "\n";
			char* result = ReplaceSpacesOnTabs(str);
			cout << result << endl;

			delete[] result;
			system("pause");
			break;
		}
		case '9':
		{
			Person people = ReadPerson();
			PrintPerson(people);

			system("pause");
			break;
		}
		}
	}
}