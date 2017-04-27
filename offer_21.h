#pragma once

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//����min������ջ

template<class T>
class StackWithMin
{
public:
	void Push(const T& x)
	{
		s.push(x);
		if (min.size() == 0 || x <= min.top())//ע�⣬������Ҫѹ��С�ڵ��ڵ�ֵ�������������
		{
			min.push(x);
		}
	}

	void Pop()
	{
		assert(s.size() > 0 && min.size() > 0);
		if (s.top() == min.top())
		{
			min.pop();
		}
		s.pop();
		
	}

	const T& Min()
	{
		assert(s.size() > 0 && min.size() > 0);
		return min.top();
	}

protected:
	stack<T> s;
	stack<T> min;
};

void TestStackWithMin()
{
	StackWithMin<int> s;
	s.Push(4);
	s.Push(2);
	s.Push(6);
	s.Push(1);
	s.Push(1);
	s.Push(9);
	s.Pop();
	s.Pop();
	s.Pop();
	cout << s.Min() << endl;
}
