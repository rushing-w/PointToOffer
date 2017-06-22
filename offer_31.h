#pragma once

#include<iostream>
using namespace std;

//求连续子数组的最大和，要求是O(N)的时间复杂度

//我们可以通过举例去分析数组，然后得到规律去解决问题

int FindGreatestSumOfSubArray(int* arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		return 0;
	}

	int sum = 0;//
	int ret = -1;
	for (int i = 0; i < n; ++i)//利用循环去判断
	{
		if (sum <= 0)//如果当前的结果比0还要小，那么就直接将前面的得到的结果丢弃，然后从当前位置重新开始计算
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];//如果不比0小，那么就去累加
		}

		if (sum > ret)//如果累加得到的结果是大的，那么就记住这个值，然后再去计算的时候，如果还有比它更大的值，那么就
		{					//更新这个值，如果不行，就不动，最后直接返回这个值
			ret = sum;
		}
	}

	return ret;
}

void TestFindGreatestSumOfSubArray()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int ret = FindGreatestSumOfSubArray(arr, sizeof(arr) / sizeof(arr[0]));
	cout << ret << endl;
}