#pragma once

#include<iostream>
using namespace std;

//쳲��������е����

//�ݹ鷽ʽ->�ݹ�Ŀ�������̫�����˺ܶ��ظ��Ĺ�����ջ֡����̫��
int Fib_R(unsigned int n)
{
	if (n < 2)
		return n;
	else
		return Fib_R(n - 1) + Fib_R(n - 2);
}

//�ǵݹ�ķ�ʽ->����ѭ��ȥʵ�ֵݹ�
int FibNonR(unsigned int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		int a = 0, b = 1, c = 0;//��������������ѭ��ʵ�ֵݹ�
		for (size_t i = 2; i <= n; ++i)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}
}

void TestFib()
{
	cout << Fib_R(10) << endl;
	cout << FibNonR(10) << endl;
}

//����-->������̨�����⣬һ������һ�ο�����1��̨�ף�Ҳ������2��̨�ף���һ��n��̨�����ܹ�������������
//��ʵ�����һ��쳲��������еı���Ӧ��

