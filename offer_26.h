#pragma once

#include<iostream>
using namespace std;

#include<unordered_map>

//复杂链表的复制
struct ComplexListNode 
{
	int val;
	struct ComplexListNode *next, *complex;
	ComplexListNode(int x)
		: val(x)
		, next(NULL)
		, complex(NULL)
	{}
};

//我们可以先拷贝一个节点放在原节点的后面，然后模仿原始链表，将复制链表的节点也链起来，然后在分别取出奇数偶数位置
ComplexListNode* Clone(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ComplexListNode* cur = pHead;
	ComplexListNode* next = NULL;
	//这里将所有节点都复制了一份并链接起来
	while (cur)
	{
		ComplexListNode* tmp = new ComplexListNode(cur->val);
		next = cur->next;
		cur->next = tmp;
		tmp->next = next;
		cur = next;
	}

	cur = pHead;
	//这里将拷贝节点的复杂链表链起来
	while (cur)
	{
		next = cur->next;
		if (next)
		{
			if (cur->complex)
				next->complex = cur->complex->next;
			else
				next->complex = NULL;
			cur = next->next;
		}
	}

	cur = pHead;
	next = cur->next;
	ComplexListNode* head = next;
	//这里将拷贝链表与原始链表分开
	while (cur)
	{
		cur->next = next->next;
		cur = cur->next;
		if (cur)
		{
			next->next = cur->next;
			next = next->next;
		}
	}
	return head;
}

//哈希表法-->利用空间换时间，时间空间复杂度都是O(N)
ComplexListNode* Clone_Hash(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	//定义一个哈希表
	unordered_map<ComplexListNode*, ComplexListNode*>hashtable;

	//拷贝出一个新的链表
	for (ComplexListNode* p = pHead; p != NULL; p = p->next)
	{
		hashtable[p] = new ComplexListNode(p->val);
	}

	//设置complex节点
	for (ComplexListNode* p = pHead; p != NULL; p = p->next)
	{
		hashtable[p]->next = hashtable[p->next];
		hashtable[p]->complex = hashtable[p->complex];
	}
	
	return hashtable[pHead];
}

void TestClone()
{
	ComplexListNode* node1 = new ComplexListNode(1);
	ComplexListNode* node2 = new ComplexListNode(2);
	ComplexListNode* node3 = new ComplexListNode(3);
	ComplexListNode* node4 = new ComplexListNode(4);
	ComplexListNode* node5 = new ComplexListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	node1->complex = node3;
	node2->complex = node5;
	node4->complex = node2;

	ComplexListNode* head;
	head = Clone_Hash(node1);

}
