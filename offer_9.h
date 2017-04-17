#pragma once

#include<iostream>
#include<math.h>
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
//����-->���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
//������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
//-->����쳲��������еı���

//����-->������̨�����⣬һ������һ�ο�����1��̨�ף�Ҳ������2��̨�ף���һ��n��̨�����ܹ�������������
//��ʵ�����һ��쳲��������еı���Ӧ��

//����-->��̬������̨�����⣬һ������һ�ο�����1��̨�ף�Ҳ������2��̨�ס���Ҳ������n��̨�ף�
//��һ��n��̨�����ܹ�������������
//��ʵ����Ҳ�ܼ�-->
//��������һ��̨����n����������1����ʣ��n-1��̨�ף���ʣ����Ҫ��f(n-1);��2������ʣ��n-2������Ҫ
//��f(n-2);�������ƣ��õ�f(n)=f(n-1)+f(n-2)+����+f(1)+f(0);����Ϊf(n-1)=f(n-2)+f(n-3)+����+f(1)+f(0);����f(n)=2*f(n-1)
//��������һ��̨�ף��������һ��̨�ױ�������ʣ���n-1��̨�׶���Ϊ���벻��������������Կ��Լ�дΪ2^(n-1)��2��n-1�η�


int JumperFloorI(int n)
{
	assert(n > 0);
	if (n < 2)
		return n;
	else
		return JumperFloorI(n - 1) * 2;	
}

int JumperFloorII(int n)
{
	assert(n>0);
	if (n < 2)
		return 2;
	else
		return pow(2, n - 1);
}

void TestJump()
{
	cout << JumperFloorI(9) << endl;
	cout << JumperFloorII(9) << endl;
}
