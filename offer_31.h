#pragma once

#include<iostream>
using namespace std;

//����������������ͣ�Ҫ����O(N)��ʱ�临�Ӷ�

//���ǿ���ͨ������ȥ�������飬Ȼ��õ�����ȥ�������

int FindGreatestSumOfSubArray(int* arr, int n)
{
	if (arr == NULL || n <= 0)
	{
		return 0;
	}

	int sum = 0;//
	int ret = -1;
	for (int i = 0; i < n; ++i)//����ѭ��ȥ�ж�
	{
		if (sum <= 0)//�����ǰ�Ľ����0��ҪС����ô��ֱ�ӽ�ǰ��ĵõ��Ľ��������Ȼ��ӵ�ǰλ�����¿�ʼ����
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];//�������0С����ô��ȥ�ۼ�
		}

		if (sum > ret)//����ۼӵõ��Ľ���Ǵ�ģ���ô�ͼ�ס���ֵ��Ȼ����ȥ�����ʱ��������б��������ֵ����ô��
		{					//�������ֵ��������У��Ͳ��������ֱ�ӷ������ֵ
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