#pragma once

#include<iostream>
using namespace std;

//��С��k����

//�����뵽����С�ķ�����������Ȼ��ȡǰK����������С��k����
//���ǣ����ַ�����һ�㲻�õľ��ǣ�����ı�ԭ��������ֵ�λ��
void GetLeastKNum(int arr[], int n, int k)
{
	//��������һ��
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
	
	//��ʱ�����Ѿ��ź����ˣ�����ֱ��ȡ��ǰk����������
	for (size_t i = 0; i < k; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

//���ÿ��ŵĵ�������
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

//��һ�ֲ���ı�ԭ����������λ�õķ�������>���������������ؽ����ֱ����������У������Ͳ���ı�ԭ�����е�����λ����

void TestGetLeastKNum()
{
	int arr[] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	//GetLeastKNum(arr, 8, 4);
	GetLeastKNum(arr, 0, 7, 4);
}
