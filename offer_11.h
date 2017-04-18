#pragma once

#include<iostream>
#include<math.h>
using namespace std;

//����ֵ�������η�

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0001) && (num1 - num2 < 0.0001))
		return true;
	else
		return false;
}

double Pow(double base, int exponent)
{
	//if (base == 0)//0��n�η���û��ɶ����ģ����Ծ�������ֱ�Ӵ����
	if (Equal(base, 0.0))//-->��Ϊdouble���ͺ�0����Ǵ��ھ�������ģ����Խ��д����ʹ�������
		return 0;
	if (exponent == 0)//��Ϊ�����ѭ���Ǵ�1��ʼ�ģ�����������Ҫ��ָ��Ϊ0�����
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