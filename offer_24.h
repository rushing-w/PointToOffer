#pragma once

#include<iostream>
using namespace std;
#include<vector>

//�ж϶����������ĺ����������

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node(int x)
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

bool VerifySquenceOfBST(int* arr, int len)
{
	if (arr == NULL || len <= 0)
		return false;

	int rootval = arr[len - 1];
	
	//��������ֵС�ڸ��ڵ�
	int i = 0;
	for (; i < len - 1; ++i)
	{
		if (arr[i] > rootval)
			break;
	}

	//�������е�ֵ���ڸ��ڵ�
	int j = i;
	for (; j < len - 1; ++j)
	{
		if (arr[j] < rootval)
			return false;
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST(arr, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < len - 1)
		right = VerifySquenceOfBST(arr + i, len - i - 1);

	return left&&right;
}


bool isLastOrder(vector<int>& a, int low, int high) 
{
	if (low >= high) 
		return true;
	int mid = 0;
	// a[high]Ϊ����㣬���ҵ��ȸ����С�ͱȸ�����ķֽ��mid
	while (a[mid] < a[high] && mid < high) 
		++mid;
	// ������mid��Ϊ�ݹ������
	int j = mid;
	// �ж�mid�����Ԫ���Ƿ񶼱ȸ����������˵�����ڸ������������
	while (j < high) 
	{
		if (a[j] > a[high]) 
		{
			++j;
			continue;
		}
		else 
			return false;
	}
	// �ݹ����mid��ߺ�mid�ұߣ�����������
	return isLastOrder(a, low, mid - 1) && isLastOrder(a, mid, high - 1);

}
bool VerifySquenceOfBST(vector<int>& a) 
{
	if (a.empty()) return false;
	return isLastOrder(a, 0, a.size() - 1);
}