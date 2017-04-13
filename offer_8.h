#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

//求旋转数组中的最小元素-->利用二分查找的思想 由于是有序数组的旋转，所以可以看做是一种另类的有序，继而通过二分思想求
int Min(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	
	int start = 0;
	int end = len - 1;
	int mid = start;//如果这个数组是未旋转的排序数组，那么就直接返回第一个元素
	while (arr[start] >= arr[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}

		mid = (start + end) >> 1;

		//在遇到start，end，mid三个所指向的数字相等时，我们只能通过遍历去找到最小值
		if (arr[mid] == arr[start] && arr[start] == arr[end])
		{
			int min = arr[start];
			for (int i = start + 1; i <= end; i++)
			{
				if (arr[i] < min)
				{
					min = arr[i];
				}
			}
			return min;
		}

		if (arr[mid] >= arr[start])
		{
			start = mid;
		}
		else if (arr[mid] <= arr[end])
		{
			mid = end;
		}
	}
	return arr[mid];
}

void TestMin()
{
	int arr[] = { 1, 1, 1, 0, 1 };
	int a[] = { 3, 4, 5, 6, 1, 2 };
	cout << Min(a, 5) << endl;
	cout << Min(arr, 5) << endl;
}