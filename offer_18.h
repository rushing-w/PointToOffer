#pragma once

#include<iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) 
	{}
};


TreeNode* CreateTree(int* a, size_t size, size_t& index)
{
	if (index < size && a[index] !=  '#')
	{
		TreeNode* root = new TreeNode(a[index]);
		root->left = CreateTree(a, size, ++index);
		root->right = CreateTree(a, size, ++index);
		return root;
	}
	return NULL;
}


bool IsTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)//一定要先判断子树，因为可能恰好子树是主树的叶子节点部分，如果先判断主树为空，那么就会返回false
		return true;

	if (pRoot1 == NULL)
		return false;

	if (pRoot1->val != pRoot2->val)//判断当前节点是否相等
		return false;

	return IsTree1HasTree2(pRoot1->left,  pRoot2->left) && IsTree1HasTree2(pRoot1->right, pRoot2->right);
	//在这里用递归去判断子树与主树的左右子树是否相等
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool ret = false;
	if (pRoot1 && pRoot2)
	{
		if (pRoot1->val == pRoot2->val)
			ret = IsTree1HasTree2(pRoot1, pRoot2);

		if (ret == false)
			ret = HasSubtree(pRoot1->left, pRoot2);

		if (ret == false)
			ret = HasSubtree(pRoot1->right, pRoot2);

	}
	return ret;
}

void TestHasSubTree()
{
	int a1[] = { 8, 8,  9, 2, '#', '#', '#', '#', 4, 7 };
	int a2[] = { 8, 9, 2 };
	size_t index = 0;
	TreeNode* root1 = CreateTree(a1, sizeof(a1) / sizeof(a1[0]), index);
	index = 0;
	TreeNode* root2 = CreateTree(a2, sizeof(a2) / sizeof(a2[0]), index);

	cout << HasSubtree(root1, root2) << endl;
}