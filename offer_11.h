#pragma once

#include<iostream>
#include<math.h>
using namespace std;

//求数值的整数次方

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0001) && (num1 - num2 < 0.0001))
		return true;
	else
		return false;
}

double Pow(double base, int exponent)
{
	//if (base == 0)//0的n次方是没有啥意义的，所以就在这里直接处理掉
	if (Equal(base, 0.0))//-->因为double类型和0相比是存在精度问题的，所以进行处理会使其更合理
		return 0;
	if (exponent == 0)//因为下面的循环是从1开始的，所以在这里要将指数为0处理掉
		return 1;

	double ret = 1.0;
	for (int i = 1; i <= abs(exponent); ++i)
	{
		ret *= base;
	}

	if (exponent <= 0)
		return 1 / ret;
	else
		return ret;
	
}

void TestPow()
{
	cout << Pow(0, 0) << endl;
}