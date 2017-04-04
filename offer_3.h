#pragma once

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		for (size_t i = 0; i < array.size(); ++i)
		{
			for (size_t j = 0; j < array[i].size(); ++j)
			{
				if (array[i][j] == target)
					return true;
			}
		}

		return false;
	}
};

bool Find(int* arr, int col, int row, int n)
{


	for (int i = 0; i < row; ++i)//ÐÐ
	{
		for (int j = 0; j < col; ++j)//ÁÐ
		{
			if ((int)arr[col*i + j] == n)
				return true;
		}
	}

	return false;
}

void TestFind()
{
	int arr[5][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 2, 3, 4, 5, 6 },
		{ 3, 4, 5, 6, 7 },
		{ 4, 5, 6, 7, 8 },
		{ 5, 6, 7, 8, 9 } };

	cout << Find((int*)arr,5,5,10) << endl;
}