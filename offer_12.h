#pragma once

#include<iostream>
#include<assert.h>
using namespace std;


void PrintNum(char* arr)//为了符合习惯，不打印前面的0
{
	int i = 0;
	bool flag = false;
	while (arr[i] != '\0')
	{
		if (!flag && arr[i] != '0')
		{
			flag = true;
		}
		if (flag)
		{
			cout << arr[i];
		}
		++i;
	}
	cout << endl;
}

void Print1ToMaxN_R(char* arr, int len, int index)//利用全排列打印，每一位的数字都是0-9，全排列打印一下
{
	if (index == len - 1)//数字的最后一位了
	{
		PrintNum(arr);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		arr[index + 1] = i + '0';
		Print1ToMaxN_R(arr, len, index + 1);
	}
}

//打印1到最大的n位数-->这里最大的陷阱就在于你能否发现数可能会溢出，n比较大的时候可能int甚至long long都不够
void Print1ToMaxn(int n)
{
	assert(n > 0);

	char* arr = new char[n + 1];
	memset(arr, '0', n);
	arr[n] = '\0';
	
	for (int i = 0; i < 10; ++i)
	{
		arr[0] = i + '0';
		Print1ToMaxN_R(arr, n, 0);
	}
	
	delete[] arr;
}

void TestPrint1ToMaxN()
{
	Print1ToMaxn(3);
}