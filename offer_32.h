#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
using namespace std;

//1到n整数中1出现的次数

//首先想到的就是累加出现的1的次数，如果是几位数，那么就模10，除10得到这个数，判断是否为1
//时间复杂度为O(N*logN)
//首先写一个求一个数字中的1的个数的算法
int NumberOf1(size_t n)
{
	int count = 0;
	while (n)
	{
		if (n % 10 == 1)
			count++;

		n = n / 10;
	}
	return count;
}

int NumberOf1Between1AndN(size_t n)
{
	int count = 0;
	for (size_t i = 1; i <= n; ++i)
	{
		count += NumberOf1(i);
	}
	return count;
}

//当然上面的算法是比较麻烦的,如果n这个数字比较大的时候，上面的算法就显得比较慢了
//所以，我们可以在这些数字中去寻找规律，然后通过规律解决问题

int Power10(int n)
{
	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		ret *= 10;
	}
	return ret;
}

int NumberOf1(const char* str)
{
	if (str == NULL || *str<'0' || *str>'9' || *str == '\0')
		return 0;

	int first = *str - '0';
	int len = strlen(str);

	if (len == 1 && first == 0)
		return 0;
	if (len == 1 && first > 0)
		return 1;
	
	//现在假设字符串是"21345"
	int num1 = 0;//这里计算的是10000-19999中1的个数
	if (first > 1)
		num1 = Power10(len - 1);//如果第一位比1大，那么10000-19999所有高位的1全取，共10000个
	else if (first == 1)
		num1 = atoi(str + 1) + 1;//如果第一位等于1，那么就比如10000-12345，那么高位就只有2345+1个1了

	int num2 = first*(len - 1)*Power10(len - 2);//这里计算的是1346到21345中除了第一位之外的数位中的1的个数
										//其实方法挺简单，除去最高位，其余每一个位取一个为1，那么其余3位中
										//可以随意取0-9中的一个数，所以可以直接得到4*10^3，再将数据分成两段
										//一段是1346-11345，一段是11346-21345，所以得到的结果还要再*2.
	int num3 = NumberOf1(str + 1);//这里求的就是1-1345中1的个数了，利用递归去求，至于+1是为了每一次跳过第一位。

	return num1 + num2 + num3;
}

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;

	char str[50];
	sprintf_s(str, "%d", n);

	return NumberOf1(str);
}


void TestNumberOf1Between1AndN()
{
	int ret = NumberOf1Between1AndN(21345);
	cout << ret << endl;
}