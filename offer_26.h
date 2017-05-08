#pragma once

#include<iostream>
using namespace std;

#include<unordered_map>

//��������ĸ���
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

//���ǿ����ȿ���һ���ڵ����ԭ�ڵ�ĺ��棬Ȼ��ģ��ԭʼ��������������Ľڵ�Ҳ��������Ȼ���ڷֱ�ȡ������ż��λ��
ComplexListNode* Clone(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	ComplexListNode* cur = pHead;
	ComplexListNode* next = NULL;
	//���ｫ���нڵ㶼������һ�ݲ���������
	while (cur)
	{
		ComplexListNode* tmp = new ComplexListNode(cur->val);
		next = cur->next;
		cur->next = tmp;
		tmp->next = next;
		cur = next;
	}

	cur = pHead;
	//���ｫ�����ڵ�ĸ�������������
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
	//���ｫ����������ԭʼ����ֿ�
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

//��ϣ��-->���ÿռ任ʱ�䣬ʱ��ռ临�Ӷȶ���O(N)
ComplexListNode* Clone_Hash(ComplexListNode* pHead)
{
	if (pHead == NULL)
		return NULL;

	//����һ����ϣ��
	unordered_map<ComplexListNode*, ComplexListNode*>hashtable;

	//������һ���µ�����
	for (ComplexListNode* p = pHead; p != NULL; p = p->next)
	{
		hashtable[p] = new ComplexListNode(p->val);
	}

	//����complex�ڵ�
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
