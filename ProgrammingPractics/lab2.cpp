#include "lab2.h"
#include "stdafx.h"

using namespace std;

int globalVariable = 7;

void PrintHelloWorld()
{
	cout << "Hello, World!\n";
}

int �hecking�orrectness()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
			cout << "������!!! ������������ ��������" << "\n" << "���������� �����: ";
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
	cout << "����� ����� ����� = " << value1 + value2 << endl;
}
void SummNumbers(double value1, double value2)
{
	cout << "����� double'�� = " << value1 + value2 << endl;
}
void SummNumbers(int value1, double value2)
{
	cout << "����� ������ � double-����� = " << value1 + value2 << endl;
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
	srand(time(NULL)); // ��� ������� ���������� ���������� �����
	cout << "\n---����: ������ �����---\n";
	int guessNumber = rand() % 10; // ��������� ������������ �����
	int enteredNumber; // �������� ������������� �����
	int shots = 1; // ���������� �������

	cout << "������� ����� �� 0 �� 9: ";
	enteredNumber = �hecking�orrectness();

	while (guessNumber != enteredNumber)
	{
		shots++;
		if (enteredNumber < guessNumber)
		{
			cout << "�� �������!!! ���������� ����� ������)\n������� ����� �� 0 �� 9: ";
		}
		else if (enteredNumber > guessNumber)
		{
			cout << "�� �������!!! ���������� ����� ������)\n������� ����� �� 0 �� 9: ";
		}
		cin >> enteredNumber;
	}
	cout << "\n���������!!! �� �������� � " << shots << " �������!" << endl;
}

void BubbleSortArrayOne(int integerArray[5]) // ���������� ���������
{
	int temp = 0; // ��������� ���������� ��� �������� �������� �������
	bool exit = false; // ������� ���������� ��� ������ �� �����, ���� ������ ������������

	while (!exit) // ���� ������ �� ������������
	{
		exit = true;
		for (int int_counter = 0; int_counter < (5 - 1); int_counter++) // ���������� ����
																				   //���������� ��������� �� ����������� - ���� >
			if (integerArray[int_counter] > integerArray[int_counter + 1]) // ���������� ��� �������� ��������
			{
				// ��������� ������������ ��������� �������
				temp = integerArray[int_counter];
				integerArray[int_counter] = integerArray[int_counter + 1];
				integerArray[int_counter + 1] = temp;
				exit = false; // �� ��������� �������� ���� ����������� ������������ ���������
			}
	}
}
void BubbleSortArrayTwo(int integerArray[], int length_array) // ���������� ���������
{
	int temp = 0; // ��������� ���������� ��� �������� �������� �������
	bool exit = false; // ������� ���������� ��� ������ �� �����, ���� ������ ������������

	while (!exit) // ���� ������ �� ������������
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // ���������� ����
																				   //���������� ��������� �� ����������� - ���� >
			if (integerArray[int_counter] > integerArray[int_counter + 1]) // ���������� ��� �������� ��������
			{
				// ��������� ������������ ��������� �������
				temp = integerArray[int_counter];
				integerArray[int_counter] = integerArray[int_counter + 1];
				integerArray[int_counter + 1] = temp;
				exit = false; // �� ��������� �������� ���� ����������� ������������ ���������
			}
	}
}
void BubbleSortArrayThree(int* arrayPtr, int length_array) // ���������� ���������
{
	int temp = 0; // ��������� ���������� ��� �������� �������� �������
	bool exit = false; // ������� ���������� ��� ������ �� �����, ���� ������ ������������

	while (!exit) // ���� ������ �� ������������
	{
		exit = true;
		for (int int_counter = 0; int_counter < (length_array - 1); int_counter++) // ���������� ����
																				   //���������� ��������� �� ����������� - ���� >
			if (arrayPtr[int_counter] > arrayPtr[int_counter + 1]) // ���������� ��� �������� ��������
			{
				// ��������� ������������ ��������� �������
				temp = arrayPtr[int_counter];
				arrayPtr[int_counter] = arrayPtr[int_counter + 1];
				arrayPtr[int_counter + 1] = temp;
				exit = false; // �� ��������� �������� ���� ����������� ������������ ���������
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
		cout << "�������... \n";
		cout << "'0' - ������� �� ����� 'Hello World'; \n";
		cout << "'1' - ��������� �����������; \n";
		cout << "'2' - ������� ������������� �����; \n";
		cout << "'3' - ���������� ������ ����������� ��������� (� ������� ����������); \n";
		cout << "'4' - ���������� ������ ����������� ��������� (� ������� ������); \n";
		cout << "'5' - ��������� ����� ���� ����������; \n";
		cout << "'6' - ������������ ������������� ���������� ����������; \n";
		cout << "'7' - ���������� ��������� ������� ������ ������ �����; \n";
		cout << "'8' - ���� '������ �����'; \n";
		cout << "'9' - �������;\n";
		cout << "'-' - ������������ ������;\n";
		cout << "������� Esc ��� ������. \n\n";

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

			cout << "������� 1-�� ������������� ��������: ";
			value1 = �hecking�orrectness();

			cout << "������� 2-�� ������������� ��������: ";
			value2 = �hecking�orrectness();

			char key;
			cout << "������� ���� �� ���������� (+, -, *, /, %): ";
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\n�������� ������!!!\n����������, ������� (+, -, *, /, %): ";
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

			cout << "������� �������: ";
			a = �hecking�orrectness();
			cout << "������� ��������: ";
			b = �hecking�orrectness();
			int result = Divide(a, b);
			cout << "\n��������� �������: " << result;

			system("pause");
			break;
		}
		case '3':
		{
			int a, b, c;
			double x1, x2;
			double* pointerX1 = &x1;
			double* pointerX2 = &x2;

			cout << "������� ���������� �: ";
			a = �hecking�orrectness();
			cout << "������� ���������� b: ";
			b = �hecking�orrectness();
			cout << "������� ���������� c: ";
			c = �hecking�orrectness();

			int countRoots = GetRootsPointers(a, b, c, pointerX1, pointerX2);

			if (countRoots == 0)
			{
				cout << "\n������ ���!" << endl;
			}
			else if (countRoots == 1)
			{
				cout << "\n���� ������: " << x1 << endl;
			}
			else
			{
				cout << "\n��� �����:" << "\n";
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

			cout << "������� ���������� �: ";
			a = �hecking�orrectness();
			cout << "������� ���������� b: ";
			b = �hecking�orrectness();
			cout << "������� ���������� c: ";
			c = �hecking�orrectness();

			int countRoots = GetRootsLinks(a, b, c, referenceX1, referenceX2);

			if (countRoots == 0)
			{
				cout << "\n������ ���!" << endl;
			}
			else if (countRoots == 1)
			{
				cout << "\n���� ������: " << x1 << endl;
			}
			else
			{
				cout << "\n��� �����:" << "\n";
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
			cout << "���������� ���������� = " << globalVariable << "\n";
			GlobalPlusTwo();
			cout << "���������� ���������� = " << globalVariable << "\n";
			GlobalMultiplyThree();
			cout << "���������� ���������� = " << globalVariable << "\n";
			GlobalEqualsOne();
			cout << "���������� ���������� = " << globalVariable << "\n";
			globalVariable = 5;
			cout << "���������� ���������� = " << globalVariable << endl;

			system("pause");
			break;
		case '7':
		{
			int base, power;
			double result;

			cout << "������� ��������� �������: ";
			base = �hecking�orrectness();
			cout << "������� ���������� �������: ";
			power = �hecking�orrectness();

			result = GetPower(base, power);
			cout << "���������: " << result << endl;

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

			cout << "������: " << "\n";
			for (int i = 0; i < arraySize; i++)
			{
				cout << integerArray[i] << " ";
			}
			cout << endl;

			//BubbleSortArrayOne(integerArray);
			//BubbleSortArrayTwo(integerArray, arraySize);
			BubbleSortArrayThree(integerArray, arraySize);

			cout << "��������������� ������: " << "\n";
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
			cout << "������� ���������� ����� ������� �: ";
			int rowsA = �hecking�orrectness();
			cout << "������� ���������� �������� ������� �: ";
			int columnsA = �hecking�orrectness();
			cout << "\n������� ���������� ����� ������� �: ";
			int rowsB = �hecking�orrectness();
			cout << "������� ���������� �������� ������� �: ";
			int columnsB = �hecking�orrectness();

			while (rowsA < 0 || rowsB < 0 || columnsA < 0 || columnsB < 0)
			{
				cout << "\n���������� ����� � �������� �� ����� ���� ������������� ��� �������!";

				cout << "\n������� ���������� ����� ������� �: ";
				rowsA = �hecking�orrectness();
				cout << "������� ���������� �������� ������� �: ";
				columnsA = �hecking�orrectness();
				cout << "\n������� ���������� ����� ������� �: ";
				rowsB = �hecking�orrectness();
				cout << "������� ���������� �������� ������� �: ";
				columnsB = �hecking�orrectness();
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

				cout << "\n������� �:" << endl;
				PrintMatrix(matrixA, columnsA, rowsA);
				cout << "____________________________" << endl;
				cout << "������� �:" << endl;
				PrintMatrix(matrixB, columnsB, rowsB);
				cout << "____________________________" << endl;
				cout << "�������������� �������:" << endl;
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
				cout << "\n���������� �������� ������� � ������ ���� ����� ���������� ����� ������� �!" << endl;

			system("pause");
			break;
		}
		}
	}
}