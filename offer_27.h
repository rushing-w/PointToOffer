#pragma once

#include<iostream>
using namespace std;


//������������˫������

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) 
	{}
};

TreeNode* Convert(TreeNode* root)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL)
		return root;

	//�������������˫��������������ͷ���
	TreeNode* left = Convert(root->left);
	TreeNode* cur = left;

	//�ҵ����������ɵ���������һ���ڵ�
	while (cur && cur->right)//-->��������ÿ�εݹ鶼�����ѭ���������ϴ��������ǿ�����һ��ʼ�ͼ�ס���һ���ڵ�
		cur = cur->right;

	//���������������Ϊ�գ���ô��root׷�ӵ��������
	if (left)
	{
		cur->right = root;
		root->left = cur;
	}

	//�������������˫��������������ͷ���
	TreeNode* right = Convert(root->right);

	//���������������Ϊ�գ���ô������׷�ӵ�root����
	if (right)
	{
		root->right = right;
		right->left = root;
	}

	return left != NULL ? left : root;
}

void TestConvert()
{
	TreeNode* root = new TreeNode(10);
	TreeNode* node1 = new TreeNode(4);
	TreeNode* node2 = new TreeNode(6);
	TreeNode* node3 = new TreeNode(8);
	TreeNode* node4 = new TreeNode(12);
	TreeNode* node5 = new TreeNode(14);
	TreeNode* node6 = new TreeNode(16);

	root->left = node2;
	root->right = node5;

	node2->left = node1;
	node2->right = node3;

	node1->left = NULL;
	node1->right = NULL;

	node3->left = NULL;
	node3->right = NULL;

	node5->left = node4;
	node5->right = node6;

	node4->left = NULL;
	node4->right = NULL;

	node6->left = NULL;
	node6->right = NULL;

	TreeNode* ret = Convert(root);
}