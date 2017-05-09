#pragma once

#include<iostream>
using namespace std;


//二叉搜索树与双向链表

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

	//将左子树构造成双向链表并返回链表头结点
	TreeNode* left = Convert(root->left);
	TreeNode* cur = left;

	//找到左子树构成的链表的最后一个节点
	while (cur && cur->right)//-->这里由于每次递归都走这个循环，开销较大，所以我们可以在一开始就记住最后一个节点
		cur = cur->right;

	//如果左子树的链表不为空，那么将root追加到链表后面
	if (left)
	{
		cur->right = root;
		root->left = cur;
	}

	//将右子树构造成双向链表并返回链表头结点
	TreeNode* right = Convert(root->right);

	//如果右子树的链表不为空，那么将链表追加到root后面
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