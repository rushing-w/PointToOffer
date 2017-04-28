#pragma once

#include<iostream>
using namespace std;
#include<queue>

//从上往下打印二叉树，每一层从左往右打印--->其实就是层序遍历二叉树(利用队列)
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

void PrintFromTopToBottom(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
		cout << front->val << " ";
		q.pop();
		if (front->left)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
	}
	cout << endl;
}
