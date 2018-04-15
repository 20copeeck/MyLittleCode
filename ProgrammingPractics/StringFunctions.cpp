#include "stdafx.h"
#include "StringFunctions.h"

void CopyString(char* string1, char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
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

char* Concatenate(char* string1, char* string2)
{
	int start = GetLength(string1);
	for (int i = 0; string2[i]; i++)
	{
		string1[start + i] = string2[i];
	}
	string1[start + GetLength(string2)] = '\0';
	return string1;
}

char* Concatenate(char* string1, const char* string2)
{
	/*char* doubleStr = new char[GetLength(string1) + GetLength(string2) + 1];
	int i = 0, j = 0;

	for (; string1[i]; i++)
	{
		doubleStr[i] = string1[i];
	}
	for (; string2[j]; j++)
	{
		doubleStr[i + j] = string2[j];
	}

	doubleStr[i + j] = '\0';
	return doubleStr;*/

	int start = GetLength(string1);
	for (int i = 0; string2[i]; i++)
	{
		string1[start + i] = string2[i];
	}
	string1[start + GetLength(string2)] = '\0';
	return string1;
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

int GetLength(char* string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

int GetLength(const char* string)
{
	int length = 0;

	while (string[length] != '\0')
	{
		length++;
	}
	return length;
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

		for (; i < charCount; i++)
		{
			substring[i] = string[startIndex + i];
		}

		substring[i] = '\0';
		return substring;
	}
}