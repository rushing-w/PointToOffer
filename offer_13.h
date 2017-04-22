#pragma once

#include<iostream>
using namespace std;


//O(1)时间内删除单链表中的节点
struct Node
{
	int _val;
	Node* _next;
};

//因为是要在O(1)的时间内删除节点，所以使用遍历然后删除的方法是行不通的，而且这是单链表，所以我们可以换一种方法
//--> 将需要删除的节点的给下一个节点的值赋给当前节点，然后删除下一个节点，但是删除节点是尾节点的话就不能用这个方法
void DeleteNode(Node* pHead, Node* pDel)
{
	if (pHead == NULL || pDel == NULL)
		return;

	if (pDel->_next != NULL)
	{
		Node* cur = pDel->_next;
		pDel->_val = cur->_val;
		pDel->_next = cur->_next;
		delete cur;
		cur = NULL;
	}
	else if (pHead == pDel)
	{
		delete pDel;
		pDel = NULL;
		pHead == NULL;
	}
	else//当前节点时尾节点，不能通过上面说到的方法解决，只能遍历解决了
	{
		Node* cur = pHead;
		while (cur->_next != pDel)
		{
			cur = cur->_next;
		}

		cur->_next = NULL;
		delete pDel;
		pDel = NULL;
	}
}
