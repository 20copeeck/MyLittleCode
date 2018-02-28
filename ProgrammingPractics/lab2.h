#pragma once

void PrintHelloWorld();  //Реализация функции, выводящей на экран текст
int СheckingСorrectness();  //Проверка на введение целочисленных значений
double MakeCalculation(int value1, int value2, char operationKey); //Функция, выполняющая математические операции
int Divide(int dividend, int divisor);  //Функция деления двух целочисленных переменных
int GetRootsPointers(int a, int b, int c, double* x1, double* x2); //Функция, вычисляющая корни квадратного уравнения (с помощью указателей)
int GetRootsLinks(int a, int b, int c, double& x1, double& x2);  //Функция, вычисляющая корни квадратного уравнения (с помощью ссылок)
void SummNumbers(int value1, int value2); //Рассчитать сумму двух целочисленных переменных
void SummNumbers(double value1, double value2); //Рассчитать сумму двух double переменных
void SummNumbers(int value1, double value2); //Рассчитать сумму целого и double переменных
void GlobalPlusTwo();  //Демонстрация использования глобальных переменных
void GlobalMultiplyThree();  //Демонстрация использования глобальных переменных
void GlobalEqualsOne();  //Демонстрация использования глобальных переменных
double GetPower(int base, int power); //Функция для вычисления указанной степени любого целого числа


void LauncherLab2();