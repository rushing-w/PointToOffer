#pragma once

#include<iostream>
using namespace std;
#include<vector>

//重建二叉树
//Definition for binary tree
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

typedef TreeNode Node;

//利用递归去重建二叉树
Node* ReConstructTree(int* Prev, int* In, int len)
{
	if (Prev == NULL || In == NULL || len <= 0)
		return NULL;

	int rootval = Prev[0];
	Node* root = new Node(rootval);
	int i = 0;
	for (; i < len && In[i] != rootval; ++i)//借此得到左子树和右子树的节点个数
	{
		;
	}

	int len_L = i;
	int len_R = len - i - 1;//减1是因为这是从0开始计数的，len-1才是正确的节点个数

	if (len_L>0)
	{
		root->left = ReConstructTree(&Prev[1], &In[0], len_L);
	}

	if (len_R > 0)
	{
		root->right = ReConstructTree(&Prev[len_L + 1], &In[len_L + 1], len_R);
	}

	return root;
}

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;

		int rootval = pre[0];
		Node* root = new Node(rootval);
		int i = 0;
		for (; i < pre.size() && vin[i] != rootval; ++i)//借此得到左子树和右子树的节点个数
		{
			;
		}

		//分别将左右子树的节点放入顺序表中，按照原本前序和中序遍历的方式存入，将其转化成子问题
		vector<int> Leftpre, Rightpre, Leftvin, Rightvin;
		for (size_t j = 0; j < i; j++)
		{
			Leftpre.push_back(pre[j + 1]);
			Leftvin.push_back(vin[j]);
		}

		for (size_t j = i + 1; j < pre.size(); j++)
		{
			Rightpre.push_back(pre[j]);
			Rightvin.push_back(vin[j]);
		}

		root->left = reConstructBinaryTree(Leftpre, Leftvin);
		root->right = reConstructBinaryTree(Rightpre, Rightvin);

		return root;
	}
};

void TestReConstructTree()
{
	int Prev[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int In[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Node* root = ReConstructTree(Prev, In, 8);
}