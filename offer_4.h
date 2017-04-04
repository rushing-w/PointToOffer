#pragma once

#include<iostream>
using namespace std;
#include<string.h>


void Replace(char* str, int len)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < len)//遇到空格就计数
	{
		if (str[i] == ' ')
		{
			count++;
		}
		++i;
	}
	i = len;
	j = 2 * count + len;//修改字符串的长度，每一次的空格都加上2个长度
	while (i != j && i >= 0)//i!=j这个条件是为了减少最后一次空格前的字符替换，进行一些优化
	{
		if (str[i] == ' ')//倒着插入可以减少移动的次数，反正原本也是需要往前走的
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
			i--;
		}
		else
		{
			str[j] = str[i];
			j--; 
			i--;
		}
	}

}

void TestReplace()
{
	char str[128] = "We are happy";
	int len = strlen(str);
	Replace(str, len);
	len = strlen(str);
	int i = 0;
	while (i < len)
	{
		cout << *(str + i);
		++i;
	}
	cout << endl;
}

//利用字符串替换->这里是取巧，直接将空格打印成字符串。
void Replace_c(char* str)
{
	char ch[] = "%20";

	while (*str != '\0')
	{
		if (*str == ' ')
		{
			printf("%s", ch);
			*str++;
		}
		printf("%c", *str);
		*str++;
	}
}


void TestReplace_c()
{
	char str[128] = "We are happy";
	Replace_c(str);
}