#pragma once

void PrintHelloWorld();  //���������� �������, ��������� �� ����� �����
int �hecking�orrectness();  //�������� �� �������� ������������� ��������
double MakeCalculation(int value1, int value2, char operationKey); //�������, ����������� �������������� ��������
int Divide(int dividend, int divisor);  //������� ������� ���� ������������� ����������
int GetRootsPointers(int a, int b, int c, double* x1, double* x2); //�������, ����������� ����� ����������� ��������� (� ������� ����������)
int GetRootsLinks(int a, int b, int c, double& x1, double& x2);  //�������, ����������� ����� ����������� ��������� (� ������� ������)
void SummNumbers(int value1, int value2); //���������� ����� ���� ������������� ����������
void SummNumbers(double value1, double value2); //���������� ����� ���� double ����������
void SummNumbers(int value1, double value2); //���������� ����� ������ � double ����������
void GlobalPlusTwo();  //������������ ������������� ���������� ����������
void GlobalMultiplyThree();  //������������ ������������� ���������� ����������
void GlobalEqualsOne();  //������������ ������������� ���������� ����������
double GetPower(int base, int power); //������� ��� ���������� ��������� ������� ������ ������ �����


void LauncherLab2();