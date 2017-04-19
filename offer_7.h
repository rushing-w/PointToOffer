#pragma once

#include<iostream>
using namespace std;
#include<stack>

//����ջʵ��һ�����еĲ���ɾ��
template<class T>
class Queue
{
public:
	Queue()
	{}

	~Queue()
	{}

	void Push(const T& x)
	{
		s1.push(x);
	}

	T Pop()
	{
		if (s2.size() <= 0)
		{
			while (s1.size() > 0)
			{
				T& data = s1.top();
				s1.pop();
				s2.push(data);
			}
		}

		if (s2.size() == 0)
			throw invalid_argument("queue is empty");

		T head = s2.top();
		s2.pop();
		return head;
	}


private:
	stack<T> s1;
	stack<T> s2;
};
