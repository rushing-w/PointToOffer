#pragma once

#include<iostream>
using namespace std;
#include<vector>
#include<assert.h>

//�ؽ�������
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

//���õݹ�ȥ�ؽ�������
Node* ReConstructTree(int* Prev, int* In, int len)
{
	if (Prev == NULL || In == NULL || len <= 0)
		return NULL;

	int rootval = Prev[0];
	Node* root = new Node(rootval);
	int i = 0;
	for (; i < len && In[i] != rootval; ++i)//��˵õ����������������Ľڵ����
	{
		;
	}

	int len_L = i;
	int len_R = len - i - 1;//��1����Ϊ���Ǵ�0��ʼ�����ģ�len-1������ȷ�Ľڵ����

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

Node* ReBulid(int* PrevOrder, int& PrevIndex, int* InOrder, int InBegin, int InEnd, int len)
{
	assert(PrevOrder && InOrder);
	
	Node* root = NULL;
	if (InBegin < InEnd && PrevIndex < len)
	{
		root = new Node(PrevOrder[PrevIndex]);
		if (InBegin == InEnd)
			return root;
		int i = InBegin; 
		for (; i < InEnd; ++i)
		{
			if (PrevOrder[PrevIndex] == InOrder[i])
				break;
		}

		root->left = ReBulid(PrevOrder, ++PrevIndex, InOrder, InBegin, i - 1, len);

		root->right = ReBulid(PrevOrder, ++PrevIndex, InOrder, i + 1, InEnd, len);
	}
	else
	{
		PrevIndex--;
	}
	return root;
}

Node* ReBulid(int* PrevOrder, int& PrevIndex, int* InOrder, int InBegin, int InEnd)
{
	assert(PrevOrder && InOrder);

	Node* root = NULL;
	if (InBegin <= InEnd)
	{
		root = new Node(PrevOrder[PrevIndex]);
		if (InBegin == InEnd)
			return root;

		int i = InBegin;
		for (; i < InEnd; ++i)
		{
			if (PrevOrder[PrevIndex] == InOrder[i])
				break;
		}

		if (i > InEnd)
			throw invalid_argument("������˳��ƥ��");
		if (i - 1 > 0)
		{
			root->left = ReBulid(PrevOrder, ++PrevIndex, InOrder, InBegin, i - 1);
		}

		if (i + 1 <= InEnd)
		{
			root->right = ReBulid(PrevOrder, ++PrevIndex, InOrder, i + 1, InEnd);
		}
	}
	return root;
}
class solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		if (pre.size() <= 0 || vin.size() <= 0)
			return NULL;

		int rootval = pre[0];
		Node* root = new Node(rootval);
		size_t i = 0;
		for (; i < pre.size() && vin[i] != rootval; ++i)//��˵õ����������������Ľڵ����
		{
			;
		}

		//�ֱ����������Ľڵ����˳����У�����ԭ��ǰ�����������ķ�ʽ���룬����ת����������
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
	int i = 0;
	//Node* root = ReConstructTree(Prev, In, 8);
	Node* root = ReBulid(Prev, i, In, 0, 7);
}