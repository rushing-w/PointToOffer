#pragma once

#include<iostream>
using namespace std;
#include<vector>

//求二叉树中和为某个值的路径
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

void _FindPath(TreeNode* root, int num, vector<int>& path, int& sum)
{
	sum += root->val;
	path.push_back(root->val);

	//找到了叶子节点并且路径上节点的和等于输入的值，那么就打印这个路径
	if (sum == num && root->left == NULL && root->right == NULL)
	{
		vector<int>::iterator it = path.begin();
		while (it != path.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	//如果不是叶子节点，那么就继续去找该节点的子节点
	if (root->left)
		_FindPath(root->left, num, path, sum);
	if (root->right)
		_FindPath(root->right, num, path, sum);

	//在返回到父节点前，删除掉这个路径上的节点，并减去sum中的该节点的值
	sum -= root->val;
	path.pop_back();
}


void FindPath(TreeNode* root, int num)
{
	if (root == NULL)
		return;

	vector<int> path;
	int sum = 0;

	_FindPath(root, num, path, sum);
}

void TestFindPath()
{
	TreeNode* root = new TreeNode(1);

	TreeNode* p1 = new TreeNode(1);
	TreeNode* p2 = new TreeNode(5);
	TreeNode* p3 = new TreeNode(3);
	TreeNode* p4 = new TreeNode(4);
	TreeNode* p5 = new TreeNode(2);

	root->left = p1;
	root->right = p4;
	p1->left = p2;
	p1->right = p3;
	p4->left = p5;
	p2->left = NULL;
	p2->right = NULL;
	p3->left = NULL;
	p3->right = NULL;
	p4->right = NULL;
	p5->left = NULL;
	p5->right = NULL;

	FindPath(root, 7);
}