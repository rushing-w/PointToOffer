#pragma once

#include<iostream>
using namespace std;

//最小的k个数

//首先想到的最小的方法就是排序，然后取前K个数就是最小的k个数
//但是，这种方法有一点不好的就是，它会改变原数组的数字的位置
void GetLeastKNum(int arr[], int n, int k)
{
	//首先排序一下
	for (size_t i = 0; i < n; ++i)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
	
	//此时数组已经排好序了，我们直接取走前k个数就行了
	for (size_t i = 0; i < k; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//利用快排的单趟排序
int PartSort(int* arr, int left, int right)
{
	int mid = right - (right - left) >> 1;
	swap(arr[mid], arr[right]);

	int key = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;
		arr[right] = arr[left];

		while (left < right && arr[right] >= key)
			right--;
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}

void GetLeastKNum(int* arr, int left, int right, int k)
{
	int ret = PartSort(arr, left, right);
	if (k - 1 < ret)
	{
		GetLeastKNum(arr, left, ret - 1, k);
	}
	else if (k - 1 > ret)
	{
		GetLeastKNum(arr, ret + 1, right, k);
	}
	else
	{
		for (size_t i = 0; i < k; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

//有一种不会改变原数组中数字位置的方法——>利用容器，这样呢将数字保存在容器中，这样就不会改变原数组中的数字位置了

void TestGetLeastKNum()
{
	int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	//GetLeastKNum(arr, 8, 4);
	GetLeastKNum(arr, 0, 7, 4);
}
