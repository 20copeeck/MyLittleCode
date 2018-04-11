#pragma once

void CopyString(char* string1, const char* string2); //Функция копирует символы из одной строки в другую
void CopyString(char* string1, char* string2); 
int GetLength(const char* string); //Функция для подсчета кол-ва символов в введенной строке
int GetLength(char* string); 
char* Concatenate(char* string1, const char* string2); //Функция, объединяющая две строки в одну
char* Concatenate(char* string1, char* string2);
char* GetSubstring(char* string, int startIndex, int charCount); //Вывод подстроки
char* Uppercase(char* string); //Перевести строку в верхний регистр
char* Lowercase(char* string); //Перевести строку в нижний регистр