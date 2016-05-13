#ifndef __PRINT1TOMAXOFN_H__
#define __PRINT1TOMAXOFN_H__

#include<iostream>
using namespace std;

bool IncreaseNum(char* num);
void PrintNum(char* num);

//�ⷨһ������ⷨ
void Print1ToMaxOfN(int n)
{
	//�߽���
	if (n <= 0)
		return;

	//�࿪��һ���ռ��'\0'
	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	while (!(IncreaseNum(num)))
	{
		PrintNum(num);
	}

	delete []num;
} 

bool IncreaseNum(char* num)
{
	bool IsOverflow = false;
	int Length = strlen(num);
	int Step = 0;

	//ģ��ӷ��Ĺ���
	for (int i = Length - 1; i >= 0; --i)
	{
		int Sum = num[i] - '0' + Step;

		if (i == Length - 1)
			Sum++;

		if (Sum >= 10)
		{
			//�������ĵ�һ���������˽�λ����ô˵���Ѿ��ӵ������ֵ
			if (i == 0)
				IsOverflow = true;

			else
			{
				Sum -= 10;
				Step = 1;
				num[i] = Sum + '0';
			}
		}

		else
		{
			num[i] = Sum + '0';
			break;
		}
	}
	return IsOverflow;
}

void PrintNum(char* num)
{
	bool Begin = true;
	int Length = strlen(num);

	for (int i = 0; i < Length; ++i)
	{
		if (Begin && num[i] != '0')
			Begin = false;

		if (!Begin)
		{
			printf("%c", num[i]);
		}
	}

	printf(" ");
}

void test()
{
	Print1ToMaxOfN(3);
}

void Print1ToMaxOfNDigit(char* num, int n, int index);
//�ⷨ�����ݹ�ⷨ
void Print1ToMaxOfN__(int n)
{
	if (n <= 0)
		return;

	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	//ÿһλ����0-9���һ��
	for (int i = 0; i < 10; i++)
	{
		num[0] = i + '0';
		Print1ToMaxOfNDigit(num, n, 0);
	}

	delete[]num;
}


void Print1ToMaxOfNDigit(char* num, int n, int index)
{
	//�ݹ���ڣ����������һλʱ��ֱ�Ӵ�ӡ
	if (index == n - 1)
	{
		PrintNum(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		num[index + 1] = i + '0';
		Print1ToMaxOfNDigit(num, n, index + 1);
	}
}

void test1()
{
	Print1ToMaxOfN__(1);
}



#endif //__PRINT1TOMAXOFN_H__