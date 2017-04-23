#pragma once

#include<iostream>
using namespace std;

//�ϲ��������������

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
	
	if (p1->_val <= p2->_val)//ȷ����p1����p2��ͷ������������ͷ�ڵ�
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
		if (p1->_val <= p2->_val)//���p1��ֵС��p2����ô�ͽ�p1����cur���棬����ͽ�p2���ں��棬Ȼ����������
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