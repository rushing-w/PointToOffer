#pragma once

#include<iostream>
using namespace std;

//·´×ªÁ´±í
struct Node
{
	int _val;
	Node* _next;
};

Node* ReverseList(Node* pHead)
{
	Node* newhead = NULL;
	Node* cur = pHead;
	Node* prev = NULL;

	if (pHead == NULL)
		return NULL;

	while (cur)
	{
		Node* next = cur->_next;

		if (next == NULL)
			newhead = cur;

		cur->_next = prev;

		prev = cur;
		cur = next;
	}

	return newhead;
}