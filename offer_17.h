#pragma once

#include<iostream>
using namespace std;

//合并两个排序的链表

struct Node
{
	int _val;
	Node* _next;
};

Node* MergeList(Node* phead1, Node* phead2)
{
	if (phead1 == NULL)
		return phead2;

	if (phead2 == NULL)
		return phead1;

	if (phead1 == phead2)
		return phead1;

	Node* p1 = phead1;
	Node* p2 = phead2;

	Node* cur = NULL;
	Node* newhead = NULL;
	
	if (p1->_val <= p2->_val)//确定是p1还是p2的头结点做新链表的头节点
	{
		cur = p1;
		p1 = p1->_next;
	}
	else
	{
		cur = p2;
		p2 = p2->_next;
	}

	newhead = cur;
	while (p1 && p2)
	{
		if (p1->_val <= p2->_val)//如果p1的值小于p2，那么就将p1链在cur后面，否则就将p2链在后面，然后再往下走
		{
			cur->_next = p1;
			p1 = p1->_next;
		}
		else
		{
			cur->_next = p2;
			p2 = p2->_next;
		}
		cur = cur->_next;
	}

	if (p1 == NULL)
	{
		cur->_next = p2;
	}
	else
	{
		cur->_next = p1;
	}

	return newhead;
}