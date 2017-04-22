#pragma once

#include<iostream>
using namespace std;

//调整数组顺序使奇数位于偶数前面


//一种方法就是遇到前偶后奇的情况就直接交换，每一轮都会将一个奇数交换到前面去，最终就会让这个数组中奇数全部位于前面
void ReOrderarray(int arr[], int len)
{
	for (size_t i = 0; i < len; ++i)
	{
		for (size_t j = len - 1; j > i; --j)
		{
			if (arr[j] % 2 == 1 && arr[j - 1] % 2 == 0)
			{
				std::swap(arr[j], arr[j - 1]);
			}	
		}
	}
}

//所以，我们可以通过前后两个指针，一个指向奇数，一个指向偶数，交换指针指向的内容即可
void ReOrderArray(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return;

	int* left = &arr[0];
	int* right = &arr[len - 1];

	while (left < right)
	{
		while (left < right && *left % 2 != 0)//先不断往有走，遇到奇数不停，遇到偶数就停下来
			left++;

		while (left < right && *right % 2 == 0)
			right--;

		std::swap(*left, *right);
	}

}

void TestReOrderArray()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//ReOrderArray(arr, sizeof(arr) / sizeof(arr[0]));
	ReOrderarray(arr, sizeof(arr) / sizeof(arr[0]));
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}