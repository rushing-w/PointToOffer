#pragma once

#include<iostream>
using namespace std;

//˳ʱ���ӡ����

void PrintMatrixInCircle(int arr[][4], int cols, int rows, int start)
{
	int end_X = cols - 1 - start;
	int end_Y = rows - 1 - start;

	//�����ҽ��д�ӡһ��
	for (int i = start; i <= end_X; ++i)
	{
		cout << arr[start][i] << " ";
	}

	//���ϵ��´�ӡһ��
	if (start < end_Y)//��ֹ���к�Ҫ������ʼ�кŲŻ���Ҫ��ӡ�ģ����ֻ��һ�оͲ��ô�ӡ��
	{
		for (int i = start + 1; i <= end_Y; ++i)
		{
			cout << arr[i][end_X] << " ";
		}
	}

	//���ҵ����ӡһ��
	if (start < end_X && start < end_Y)//����Ҫ���������в��ܴ�ӡ������ֹ�кŴ�����ʼ�кţ���ֹ�кŴ�����ʼ�к�
	{
		for (int i = end_X - 1; i >= start; --i)
		{
			cout << arr[end_Y][i] << " ";
		}
	}

	//���µ��ϴ�ӡһ��
	if (start < end_X && start < end_Y - 1)//����Ҫ���������в��ܴ�ӡ������ֹ�кű���ʼ�к����ٴ�2����ֹ�кŴ�����ʼ�к�
	{
		for (int i = end_Y - 1; i >= start + 1; --i)
		{
			cout << arr[i][start] << "��";
		}
	}
}


void PrintMatrix(int arr[][4], int cols/*��*/, int rows/*��*/)
{
	if (arr == NULL || cols <= 0 || rows <= 0)
		return;

	int start = 0;

	while (cols > start * 2 && rows > start * 2)
	{
		PrintMatrixInCircle(arr, cols, rows, start);
		++start;
	}
	cout << endl;

}

void TestPrint()
{
	int a[][4] = { 
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}};

	PrintMatrix(a, 4, 4);
}
