#pragma once

#include<iostream>
#include<math.h>
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
//延伸-->我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
//请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//-->还是斐波那契数列的变形

//延伸-->青蛙跳台阶问题，一个青蛙一次可以跳1级台阶，也可以跳2级台阶，求一个n级台阶青蛙共多少种跳法？
//其实这就是一个斐波那契数列的变形应用

//延伸-->变态青蛙跳台阶问题，一个青蛙一次可以跳1级台阶，也可以跳2级台阶……也可以跳n级台阶，
//求一个n级台阶青蛙共多少种跳法？
//其实方法也很简单-->
//①青蛙跳一次台阶有n中跳法，跳1级，剩下n-1级台阶，则剩下需要跳f(n-1);跳2级，则剩下n-2级，需要
//跳f(n-2);依次类推，得到f(n)=f(n-1)+f(n-2)+……+f(1)+f(0);又因为f(n-1)=f(n-2)+f(n-3)+……+f(1)+f(0);所以f(n)=2*f(n-1)
//②青蛙跳一次台阶，除了最后一次台阶必须跳，剩余的n-1次台阶都分为跳与不跳两种情况，所以可以简单写为2^(n-1)即2的n-1次方


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
