#pragma once

#include<iostream>
using namespace std;
#include<stack>
#include<vector>

//ջ��ѹ�롢��������

bool IsPopOrder(const int* Push, const int* Pop, int len)
{
	if (Push && Pop && len > 0)
	{
		const int* p1 = Push;
		const int* p2 = Pop;

		stack<int> s;
		while (p2 - Pop < len)//��������Ԫ�ػ�û�ߵ�����ʱ�����д���
		{
			while (s.empty() || s.top() != *p2)//��ջΪ�ջ���ջ��Ԫ�ز�����Ҫ������Ԫ��ʱ��ѹջ
			{
				if (p1 - Push == len)//�����Ҫѹ��������Ѿ����ˣ��ǾͲ�����ѹ����
					break;

				s.push(*p1);
				p1++;
			}

			if (*p2 != s.top())//���ջ��Ԫ�ز�����Ҫ�������ģ��Ǿ���������ʱҪô���д���ҪôջΪ��
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
