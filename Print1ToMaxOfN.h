#ifndef __PRINT1TOMAXOFN_H__
#define __PRINT1TOMAXOFN_H__

#include<iostream>
using namespace std;

bool IncreaseNum(char* num);
void PrintNum(char* num);

//解法一：常规解法
void Print1ToMaxOfN(int n)
{
	//边界检查
	if (n <= 0)
		return;

	//多开辟一个空间放'\0'
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

	//模拟加法的过程
	for (int i = Length - 1; i >= 0; --i)
	{
		int Sum = num[i] - '0' + Step;

		if (i == Length - 1)
			Sum++;

		if (Sum >= 10)
		{
			//如果数组的第一个数产生了进位，那么说明已经加到了最大值
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
//解法二：递归解法
void Print1ToMaxOfN__(int n)
{
	if (n <= 0)
		return;

	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	//每一位都把0-9输出一遍
	for (int i = 0; i < 10; i++)
	{
		num[0] = i + '0';
		Print1ToMaxOfNDigit(num, n, 0);
	}

	delete[]num;
}


void Print1ToMaxOfNDigit(char* num, int n, int index)
{
	//递归出口，当到达最后一位时，直接打印
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