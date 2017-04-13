#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

//����ת�����е���СԪ��-->���ö��ֲ��ҵ�˼�� �����������������ת�����Կ��Կ�����һ����������򣬼̶�ͨ������˼����
int Min(int* arr, int len)
{
	assert(arr);
	assert(len > 0);
	
	int start = 0;
	int end = len - 1;
	int mid = start;//������������δ��ת���������飬��ô��ֱ�ӷ��ص�һ��Ԫ��
	while (arr[start] >= arr[end])
	{
		if (end - start == 1)
		{
			mid = end;
			break;
		}

		mid = (start + end) >> 1;

		//������start��end��mid������ָ����������ʱ������ֻ��ͨ������ȥ�ҵ���Сֵ
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