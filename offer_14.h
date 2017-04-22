#pragma once

#include<iostream>
using namespace std;

//��������˳��ʹ����λ��ż��ǰ��


//һ�ַ�����������ǰż����������ֱ�ӽ�����ÿһ�ֶ��Ὣһ������������ǰ��ȥ�����վͻ����������������ȫ��λ��ǰ��
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

//���ԣ����ǿ���ͨ��ǰ������ָ�룬һ��ָ��������һ��ָ��ż��������ָ��ָ������ݼ���
void ReOrderArray(int arr[], int len)
{
	if (arr == NULL || len <= 0)
		return;

	int* left = &arr[0];
	int* right = &arr[len - 1];

	while (left < right)
	{
		while (left < right && *left % 2 != 0)//�Ȳ��������ߣ�����������ͣ������ż����ͣ����
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