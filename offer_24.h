#pragma once

#include<iostream>
using namespace std;
#include<vector>

//判断二叉搜索树的后序遍历序列

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
	
	//左子树的值小于根节点
	int i = 0;
	for (; i < len - 1; ++i)
	{
		if (arr[i] > rootval)
			break;
	}

	//右子树中的值大于根节点
	int j = i;
	for (; j < len - 1; ++j)
	{
		if (arr[j] < rootval)
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySquenceOfBST(arr, i);

	//判断右子树是不是二叉搜索树
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
	// a[high]为根结点，先找到比根结点小和比根结点大的分界点mid
	while (a[mid] < a[high] && mid < high) 
		++mid;
	// 保存下mid作为递归的输入
	int j = mid;
	// 判断mid后面的元素是否都比根结点大，如果是说明对于根结点满足条件
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
	// 递归遍历mid左边和mid右边，即左右子树
	return isLastOrder(a, low, mid - 1) && isLastOrder(a, mid, high - 1);

}
bool VerifySquenceOfBST(vector<int>& a) 
{
	if (a.empty()) return false;
	return isLastOrder(a, 0, a.size() - 1);
}