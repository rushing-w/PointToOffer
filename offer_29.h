#pragma once

#include<iostream>
using namespace std;

//数组中出现次数超过一半的数字

//首先想到的是时间复杂度较高的算法，先排序，排完的数据在数组中，出现次数最多的那个数据一定是在数组的中间，
//毕竟这个数字占据了数组的一半，这样可以直接得到数字

//这种是O(N)时间复杂度的算法
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