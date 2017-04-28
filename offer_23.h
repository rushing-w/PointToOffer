#pragma once

#include<iostream>
using namespace std;
#include<queue>

//�������´�ӡ��������ÿһ��������Ҵ�ӡ--->��ʵ���ǲ������������(���ö���)
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
