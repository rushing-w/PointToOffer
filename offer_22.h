#pragma once

#include<iostream>
using namespace std;
#include<stack>
#include<vector>

//栈的压入、弹出序列

bool IsPopOrder(const int* Push, const int* Pop, int len)
{
	if (Push && Pop && len > 0)
	{
		const int* p1 = Push;
		const int* p2 = Pop;

		stack<int> s;
		while (p2 - Pop < len)//当弹出的元素还没走到结束时，进行处理
		{
			while (s.empty() || s.top() != *p2)//当栈为空或者栈顶元素不是需要弹出的元素时，压栈
			{
				if (p1 - Push == len)//如果需要压入的序列已经空了，那就不用再压入了
					break;

				s.push(*p1);
				p1++;
			}

			if (*p2 != s.top())//如果栈顶元素不是需要被弹出的，那就跳出，此时要么序列错误，要么栈为空
				break;

			s.pop();
			p2++;
		}

		if (s.empty() && p2 - Pop == len)
			return true;
	}
	return false;
}

bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	if (!pushV.empty() && !popV.empty())
	{
		stack<int> s;
		int j = 0;
		for (int i = 0; i<pushV.size(); ++i)
		{
			s.push(pushV[i]);
			while (!s.empty() && s.top() == popV[j])
			{
				s.pop();
				j++;
			}
		}
		if (s.empty())
			return true;
	}
	return false;
}

void TestIsPopOrder()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int a1[] = { 4, 5, 3, 2, 1 };
	int a2[] = { 4, 3, 5, 1, 2 };
	cout << IsPopOrder(a, a1, 5) << endl;
	cout << IsPopOrder(a, a2, 5) << endl;
}
