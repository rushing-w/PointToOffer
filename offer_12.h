#pragma once

#include<iostream>
#include<assert.h>
using namespace std;


void PrintNum(char* arr)//Ϊ�˷���ϰ�ߣ�����ӡǰ���0
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

void Print1ToMaxN_R(char* arr, int len, int index)//����ȫ���д�ӡ��ÿһλ�����ֶ���0-9��ȫ���д�ӡһ��
{
	if (index == len - 1)//���ֵ����һλ��
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

//��ӡ1������nλ��-->��������������������ܷ��������ܻ������n�Ƚϴ��ʱ�����int����long long������
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