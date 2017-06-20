#pragma once

#include<iostream>
using namespace std;

//�����г��ִ�������һ�������

//�����뵽����ʱ�临�ӶȽϸߵ��㷨������������������������У����ִ��������Ǹ�����һ������������м䣬
//�Ͼ��������ռ���������һ�룬��������ֱ�ӵõ�����

//������O(N)ʱ�临�Ӷȵ��㷨
int GetMoreThanHalfNum(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		return -1;
	}

	int ret = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			ret = numbers[i];
			times = 1;
		}
		else if (numbers[i] == ret)
		{
			times++;
		}
		else
		{
			times--;
		}
	}

	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == ret)
		{
			count++;
		}
	}
	if (count * 2 <= length)
	{
		return -1;
	}

	return ret;
}

void TestMoreThanHalfNum()
{
	//int a[] = { 1, 2, 3, 2, 3, 2, 5, 4, 6 };
	int a[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int ret = GetMoreThanHalfNum(a, sizeof(a) / sizeof(a[0]));
	cout << ret << endl;
}