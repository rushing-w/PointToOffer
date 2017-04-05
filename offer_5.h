#pragma once

#include<iostream>
using namespace std;
#include<stack>
#include<vector>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x), next(NULL) 
	{}
};

//�ݹ�ķ�ʽ
void PrintListFromTailToHead_R(ListNode* head)
{
	if (head)
	{
		if (head->next)
			PrintListFromTailToHead_R(head->next);
		cout << head->val << " ";
	}
}

//�ǵݹ鷽ʽ->����ջ
void PrintListFromTailToHead_Stack(ListNode* head)
{
	stack<int> s;
	ListNode* cur = head;
	while (cur)
	{
		s.push(cur->val);
		cur = cur->next;
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) 
	{
		vector<int> v;
		stack<int> s;
		ListNode* cur = head;
		while (cur)
		{
			s.push(cur->val);
			cur = cur->next;
		}

		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}

		return v;

	}
};


