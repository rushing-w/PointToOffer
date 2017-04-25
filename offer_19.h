#pragma once

#include<iostream>
using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x)
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

void Mirror(TreeNode *pRoot) 
{
	if (pRoot == NULL)
		return;

	if (pRoot->left == NULL && pRoot->right == NULL)
		return;

	std::swap(pRoot->left, pRoot->right);

	if (pRoot->left)
		Mirror(pRoot->left);

	if (pRoot->right)
		Mirror(pRoot->right);
}

