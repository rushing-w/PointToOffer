#pragma once

#include<iostream>
using namespace std;

//顺时针打印矩阵

void PrintMatrixInCircle(int arr[][4], int cols, int rows, int start)
{
	int end_X = cols - 1 - start;
	int end_Y = rows - 1 - start;

	//从左到右进行打印一行
	for (int i = start; i <= end_X; ++i)
	{
		cout << arr[start][i] << " ";
	}

	//从上到下打印一列
	if (start < end_Y)//终止的行号要大于起始行号才会有要打印的，如果只有一行就不用打印了
	{
		for (int i = start + 1; i <= end_Y; ++i)
		{
			cout << arr[i][end_X] << " ";
		}
	}

	//从右到左打印一行
	if (start < end_X && start < end_Y)//至少要有两行两列才能打印，即终止行号大于起始行号，终止列号大于起始列号
	{
		for (int i = end_X - 1; i >= start; --i)
		{
			cout << arr[end_Y][i] << " ";
		}
	}

	//从下到上打印一列
	if (start < end_X && start < end_Y - 1)//至少要有三行两列才能打印，则终止行号比起始行号至少大2，终止列号大于起始列号
	{
		for (int i = end_Y - 1; i >= start + 1; --i)
		{
			cout << arr[i][start] << "　";
		}
	}
}


void PrintMatrix(int arr[][4], int cols/*列*/, int rows/*行*/)
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
