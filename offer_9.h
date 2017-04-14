#pragma once

#include<iostream>
using namespace std;

//斐波那契数列的求解

//递归方式->递归的开销明显太大，做了很多重复的工作，栈帧开销太大
int Fib_R(unsigned int n)
{
	if (n < 2)
		return n;
	else
		return Fib_R(n - 1) + Fib_R(n - 2);
}

//非递归的方式->利用循环去实现递归
int FibNonR(unsigned int n)
{
	if (n < 2)
	{
		return n;
	}
	else
	{
		int a = 0, b = 1, c = 0;//利用三个变量和循环实现递归
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

//延伸-->青蛙跳台阶问题，一个青蛙一次可以跳1级台阶，也可以跳2级台阶，求一个n级台阶青蛙共多少种跳法？
//其实这就是一个斐波那契数列的变形应用

