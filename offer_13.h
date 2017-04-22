#pragma once

#include<iostream>
using namespace std;


//O(1)ʱ����ɾ���������еĽڵ�
struct Node
{
	int _val;
	Node* _next;
};

//��Ϊ��Ҫ��O(1)��ʱ����ɾ���ڵ㣬����ʹ�ñ���Ȼ��ɾ���ķ������в�ͨ�ģ��������ǵ������������ǿ��Ի�һ�ַ���
//--> ����Ҫɾ���Ľڵ�ĸ���һ���ڵ��ֵ������ǰ�ڵ㣬Ȼ��ɾ����һ���ڵ㣬����ɾ���ڵ���β�ڵ�Ļ��Ͳ������������
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
	else//��ǰ�ڵ�ʱβ�ڵ㣬����ͨ������˵���ķ��������ֻ�ܱ��������
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
