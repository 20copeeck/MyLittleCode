#include "lab2.h"
#include "stdafx.h"

using namespace std;

int globalVariable = 7;

void PrintHelloWorld()
{
	cout << "Hello, World!\n";
}

int СheckingСorrectness()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
			cout << "Ошибка!!! Некорректное значение" << "\n" << "Попробуйте снова: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);

	return value;
}

double MakeCalculation(int value1, int value2, char operationKey)
{
	if (operationKey == '+')
	{
		return (value1 + value2);
	}
	else if (operationKey == '-')
	{
		return (value1 - value2);
	}
	else if (operationKey == '*')
	{
		return (value1 * value2);
	}
	else if (operationKey == '/')
	{
		return ((double)value1 / value2);
	}
	else if (operationKey == '%')
	{
		return (value1 % value2);
	}
}

int Divide(int dividend, int divisor)
{
	int result;
	result = dividend / divisor;
	return result;
}

int GetRootsPointers(int a, int b, int c, double* x1, double* x2)
{
	double discriminant;
	
	if ((a == 0) & (b == 0))
	{
		return 0;
	}
	else if (a == 0)
	{
		*x1 = -c / b;
		return 1;
	}
	else
	{
		discriminant = b * b - 4 * a * c;

		if (discriminant < 0)
		{
			return 0;
		}
		else if (discriminant == 0)
		{
			*x1 = (-b + sqrt(discriminant)) / (2 * a);
			return 1;
		}
		else
		{
			*x1 = (-b + sqrt(discriminant)) / (2 * a);
			*x2 = (-b - sqrt(discriminant)) / (2 * a);
			return 2;
		}
	}
}
int GetRootsLinks(int a, int b, int c, double& x1, double& x2)
{
	double discriminant;

	if ((a == 0) & (b == 0))
	{
		return 0;
	}
	else if (a == 0)
	{
		x1 = -c / b;
		return 1;
	}
	else
	{
		discriminant = b * b - 4 * a * c;

		if (discriminant < 0)
		{
			return 0;
		}
		else if (discriminant == 0)
		{
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			return 1;
		}
		else
		{
			x1 = (-b + sqrt(discriminant)) / (2 * a);
			x2 = (-b - sqrt(discriminant)) / (2 * a);
			return 2;
		}
	}
	return 0;
}

void SummNumbers(int value1, int value2)
{
	cout << "Сумма целых чисел = " << value1 + value2 << endl;
}
void SummNumbers(double value1, double value2)
{
	cout << "Сумма double'ов = " << value1 + value2 << endl;
}
void SummNumbers(int value1, double value2)
{
	cout << "Сумма целого и double-числа = " << value1 + value2 << endl;
}

void GlobalPlusTwo()
{
	globalVariable += 2;
}
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}
void GlobalEqualsOne()
{
	globalVariable = 1;
}

double GetPower(int base, int power)
{
	if (power == 0)
		return 1;
	else if (power < 0)
		return 1 / GetPower(base, -power);
	else
		return base * GetPower(base, power - 1);
}

void PlayGame()
{
	srand(time(NULL)); // для задания случайного начального числа
	cout << "\n---Игра: Угадай число---\n";
	int guessNumber = rand() % 10; // генерация угадываемого числа
	int enteredNumber; // вводимое пользователем число
	int shots = 1; // количество попыток

	cout << "Введите цифру от 0 до 9: ";
	enteredNumber = СheckingСorrectness();

	while (guessNumber != enteredNumber)
	{
		shots++;
		if (enteredNumber < guessNumber)
		{
			cout << "Не угадали!!! Загаданное число больше)\nВведите цифру от 0 до 9: ";
		}
		else if (enteredNumber > guessNumber)
		{
			cout << "Не угадали!!! Загаданное число меньше)\nВведите цифру от 0 до 9: ";
		}
		cin >> enteredNumber;
	}
	cout << "\nПравильно!!! Вы выйграли с " << shots << " попытки!" << endl;
}

void BubbleSortArrayOne(int integerArray[5]) // сортировка пузырьком
{
	int temp = 0; // временная переменная для хранения элемента массива
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

	while (!exit) // пока массив не отсортирован
	{
		exit = true;
		for (int int_counter = 0; int_counter < (5 - 1); int_counter++) // внутренний цикл
																				   //сортировка пузырьком по возрастанию - знак >
			if (integerArray[int_counter] > integerArray[int_counter + 1]) // сравниваем два соседних элемента
			{
				// выполняем перестановку элементов массива
				temp = integerArray[int_counter];
				integerArray[int_counter] = integerArray[int_counter + 1];
				integerArray[int_counter + 1] = temp;
				exit = false; // на очередной итерации была произведена перестановка элементов
			}
	}
}
void BubbleSortArrayTwo(int integerArray[], int length_array) // сортировка пузырьком
{
	int temp = 0; // временная переменная для хранения элемента массива
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

	while (!exit) // пока массив не отсортирован
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // внутренний цикл
																				   //сортировка пузырьком по возрастанию - знак >
			if (integerArray[int_counter] > integerArray[int_counter + 1]) // сравниваем два соседних элемента
			{
				// выполняем перестановку элементов массива
				temp = integerArray[int_counter];
				integerArray[int_counter] = integerArray[int_counter + 1];
				integerArray[int_counter + 1] = temp;
				exit = false; // на очередной итерации была произведена перестановка элементов
			}
	}
}
void BubbleSortArrayThree(int* arrayPtr, int length_array) // сортировка пузырьком
{
	int temp = 0; // временная переменная для хранения элемента массива
	bool exit = false; // болевая переменная для выхода из цикла, если массив отсортирован

	while (!exit) // пока массив не отсортирован
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // внутренний цикл
																				   //сортировка пузырьком по возрастанию - знак >
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) // сравниваем два соседних элемента
			{
				// выполняем перестановку элементов массива
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false; // на очередной итерации была произведена перестановка элементов
			}
	}
}

void MultiplyMatrices(int** matrixA, int rowsA, int columnsA, int** matrixB, int rowsB, int columnsB, int** matrixResult)
{
	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnsB; j++)
		{
			matrixResult[i][j] = 0;
			for (int k = 0; k < columnsA; k++)
			{
				matrixResult[i][j] += (matrixA[i][k] * matrixB[k][j]);
			}
		}
	}
}
void PrintMatrix(int** matrix, int columns, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout.width(8);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void LauncherLab2()
{
	setlocale(0, "");

	int ascii = 0;
	char key;

	while (ascii != 27)
	{
		system("cls");
		cout << "Нажмите... \n";
		cout << "'0' - Вывести на экран 'Hello World'; \n";
		cout << "'1' - Запустить калькулятор; \n";
		cout << "'2' - Деление целочисленных чисел; \n";
		cout << "'3' - Нахождение корней квадратного уравнения (с помощью указателей); \n";
		cout << "'4' - Нахождение корней квадратного уравнения (с помощью ссылок); \n";
		cout << "'5' - Расчитать сумму двух переменных; \n";
		cout << "'6' - Демонстрация использования глобальных переменных; \n";
		cout << "'7' - Вычисление указанной степени любого целого числа; \n";
		cout << "'8' - Игра 'Угадай число'; \n";
		cout << "'9' - Массивы;\n";
		cout << "'-' - Произведение матриц;\n";
		cout << "Нажмите Esc для выхода. \n\n";

		key = _getch();
		ascii = key;

		switch (ascii)
		{
		case '0':
			PrintHelloWorld();
			system("pause");
			break;
		case '1':
		{
			int value2, value1;

			cout << "Введите 1-ое целочисленное значение: ";
			value1 = СheckingСorrectness();

			cout << "Введите 2-ое целочисленное значение: ";
			value2 = СheckingСorrectness();

			char key;
			cout << "Введите один из операторов (+, -, *, /, %): ";
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\nНЕВЕРНЫЙ СИМВОЛ!!!\nПожалуйста, введите (+, -, *, /, %): ";
				key = _getch();
				fflush(stdin); 
			}
			cout << "\n" << value1 << " " << key << " " << value2 << " = " << MakeCalculation((int)value1, value2, key) << endl;

			system("pause");
			break;
		}
		case '2':
		{
			int a = 0;
			int b = 0;

			cout << "Введите делимое: ";
			a = СheckingСorrectness();
			cout << "Введите делитель: ";
			b = СheckingСorrectness();
			int result = Divide(a, b);
			cout << "\nРезультат деления: " << result;

			system("pause");
			break;
		}
		case '3':
		{
			int a, b, c;
			double x1, x2;
			double* pointerX1 = &x1;
			double* pointerX2 = &x2;

			cout << "Введите переменную а: ";
			a = СheckingСorrectness();
			cout << "Введите переменную b: ";
			b = СheckingСorrectness();
			cout << "Введите переменную c: ";
			c = СheckingСorrectness();

			int countRoots = GetRootsPointers(a, b, c, pointerX1, pointerX2);

			if (countRoots == 0)
			{
				cout << "\nКорней нет!" << endl;
			}
			else if (countRoots == 1)
			{
				cout << "\nОдин корень: " << x1 << endl;
			}
			else
			{
				cout << "\nДва корня:" << "\n";
				cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << endl;
			}

			system("pause");
			break;
		}
		case '4':
		{
			int a, b, c;
			double x1, x2;
			double& referenceX1 = x1;
			double& referenceX2 = x2;

			cout << "Введите переменную а: ";
			a = СheckingСorrectness();
			cout << "Введите переменную b: ";
			b = СheckingСorrectness();
			cout << "Введите переменную c: ";
			c = СheckingСorrectness();

			int countRoots = GetRootsLinks(a, b, c, referenceX1, referenceX2);

			if (countRoots == 0)
			{
				cout << "\nКорней нет!" << endl;
			}
			else if (countRoots == 1)
			{
				cout << "\nОдин корень: " << x1 << endl;
			}
			else
			{
				cout << "\nДва корня:" << "\n";
				cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << endl;
			}

			system("pause");
			break;
		}
		case '5':
		{
			int a = 1;
			int b = 2;
			SummNumbers(a, b);

			double x = 3.0;
			double y = 4.0;
			SummNumbers(x, y);
			SummNumbers(a, y);

			float m = 5.0;
			float n = 6.0;
			SummNumbers(m, n);

			system("pause");
			break;
		}
		case '6':
			cout << "Глобальная переменная = " << globalVariable << "\n";
			GlobalPlusTwo();
			cout << "Глобальная переменная = " << globalVariable << "\n";
			GlobalMultiplyThree();
			cout << "Глобальная переменная = " << globalVariable << "\n";
			GlobalEqualsOne();
			cout << "Глобальная переменная = " << globalVariable << "\n";
			globalVariable = 5;
			cout << "Глобальная переменная = " << globalVariable << endl;

			system("pause");
			break;
		case '7':
		{
			int base, power;
			double result;

			cout << "Введите основание степени: ";
			base = СheckingСorrectness();
			cout << "Введите показатель степени: ";
			power = СheckingСorrectness();

			result = GetPower(base, power);
			cout << "Результат: " << result << endl;

			system("pause");
			break;
		}
		case '8':
			PlayGame();
			system("pause");
			break;
		case '9':
		{
			const int arraySize = 5;
			int integerArray[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				integerArray[i] = rand() % 50;
			}

			cout << "Массив: " << "\n";
			for (int i = 0; i < arraySize; i++)
			{
				cout << integerArray[i] << " ";
			}
			cout << endl;

			//BubbleSortArrayOne(integerArray);
			//BubbleSortArrayTwo(integerArray, arraySize);
			BubbleSortArrayThree(integerArray, arraySize);

			cout << "Отсортированный массив: " << "\n";
			for (int i = 0; i < arraySize; i++)
			{
				cout << integerArray[i] << " ";
			}
			cout << endl;

			system("pause");
			break;
		}
		case '-':
		{
			cout << "Введите количество строк матрицы А: ";
			int rowsA = СheckingСorrectness();
			cout << "Введите количество столбцов матрицы А: ";
			int columnsA = СheckingСorrectness();
			cout << "\nВведите количество строк матрицы В: ";
			int rowsB = СheckingСorrectness();
			cout << "Введите количество столбцов матрицы В: ";
			int columnsB = СheckingСorrectness();

			while (rowsA < 0 || rowsB < 0 || columnsA < 0 || columnsB < 0)
			{
				cout << "\nКоличество строк и столбцов не может быть отрицательным или нулевым!";

				cout << "\nВведите количество строк матрицы А: ";
				rowsA = СheckingСorrectness();
				cout << "Введите количество столбцов матрицы А: ";
				columnsA = СheckingСorrectness();
				cout << "\nВведите количество строк матрицы В: ";
				rowsB = СheckingСorrectness();
				cout << "Введите количество столбцов матрицы В: ";
				columnsB = СheckingСorrectness();
			}

			if (columnsA == rowsB)
			{
				int rowsResult = rowsA;
				int columnsResult = columnsB;

				int** matrixA = new int*[rowsA];
				for (int i = 0; i < rowsA; i++)
					matrixA[i] = new int[columnsA];

				int** matrixB = new int*[rowsB];
				for (int i = 0; i < rowsB; i++)
					matrixB[i] = new int[columnsB];

				int** matrixResult = new int*[rowsResult];
				for (int i = 0; i < rowsResult; i++)
					matrixResult[i] = new int[columnsResult];

				//--------------------------------------------------

				for (int i = 0; i < rowsA; i++)
					for (int j = 0; j < columnsA; j++)
						matrixA[i][j] = rand() % 100;

				for (int i = 0; i < rowsB; i++)
					for (int j = 0; j < columnsB; j++)
						matrixB[i][j] = rand() % 100;

				MultiplyMatrices(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixResult);

				cout << "\nМатрица А:" << endl;
				PrintMatrix(matrixA, columnsA, rowsA);
				cout << "____________________________" << endl;
				cout << "Матрица В:" << endl;
				PrintMatrix(matrixB, columnsB, rowsB);
				cout << "____________________________" << endl;
				cout << "Результирующая матрица:" << endl;
				PrintMatrix(matrixResult, columnsResult, rowsResult);

				for (int i = 0; i < rowsA; i++)
					delete[] matrixA[i];
				for (int i = 0; i < rowsB; i++)
					delete[] matrixB[i];
				for (int i = 0; i < rowsResult; i++)
					delete[] matrixResult[i];
				delete[] matrixA, matrixB, matrixResult;
			}
			else
				cout << "\nКоличество столбцов матрицы А должно быть равно количеству строк матрицы В!" << endl;

			system("pause");
			break;
		}
		}
	}
}