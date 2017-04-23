#pragma once

#include<iostream>
using namespace std;

//求链表中倒数第K个节点
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

	if (k > 0)//如果是因为fast到尾的条件退出的，那么说明没有这个倒数第K个节点
		return NULL;

	while (fast)
	{
		fast = fast->_next;
		slow = slow->_next;
	}

	return slow;
}