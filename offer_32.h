#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
using namespace std;

//1��n������1���ֵĴ���

//�����뵽�ľ����ۼӳ��ֵ�1�Ĵ���������Ǽ�λ������ô��ģ10����10�õ���������ж��Ƿ�Ϊ1
//ʱ�临�Ӷ�ΪO(N*logN)
//����дһ����һ�������е�1�ĸ������㷨
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

//��Ȼ������㷨�ǱȽ��鷳��,���n������ֱȽϴ��ʱ��������㷨���ԵñȽ�����
//���ԣ����ǿ�������Щ������ȥѰ�ҹ��ɣ�Ȼ��ͨ�����ɽ������

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
	
	//���ڼ����ַ�����"21345"
	int num1 = 0;//����������10000-19999��1�ĸ���
	if (first > 1)
		num1 = Power10(len - 1);//�����һλ��1����ô10000-19999���и�λ��1ȫȡ����10000��
	else if (first == 1)
		num1 = atoi(str + 1) + 1;//�����һλ����1����ô�ͱ���10000-12345����ô��λ��ֻ��2345+1��1��

	int num2 = first*(len - 1)*Power10(len - 2);//����������1346��21345�г��˵�һλ֮�����λ�е�1�ĸ���
										//��ʵ����ͦ�򵥣���ȥ���λ������ÿһ��λȡһ��Ϊ1����ô����3λ��
										//��������ȡ0-9�е�һ���������Կ���ֱ�ӵõ�4*10^3���ٽ����ݷֳ�����
										//һ����1346-11345��һ����11346-21345�����Եõ��Ľ����Ҫ��*2.
	int num3 = NumberOf1(str + 1);//������ľ���1-1345��1�ĸ����ˣ����õݹ�ȥ������+1��Ϊ��ÿһ��������һλ��

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