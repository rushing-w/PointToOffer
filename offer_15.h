#pragma once

#include<iostream>
using namespace std;

//�������е�����K���ڵ�
struct Node
{
	int _val;
	Node* _next;
};

Node* GetLastKNode(Node* pHead, int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;

	Node* fast = pHead;
	Node* slow = pHead;
	while (fast && k--)
	{
		fast = fast->_next;
	}

	if (k > 0)//�������Ϊfast��β�������˳��ģ���ô˵��û�����������K���ڵ�
		return NULL;

	while (fast)
	{
		fast = fast->_next;
		slow = slow->_next;
	}

	return slow;
}