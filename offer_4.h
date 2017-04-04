#pragma once

#include<iostream>
using namespace std;
#include<string.h>


void Replace(char* str, int len)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < len)//�����ո�ͼ���
	{
		if (str[i] == ' ')
		{
			count++;
		}
		++i;
	}
	i = len;
	j = 2 * count + len;//�޸��ַ����ĳ��ȣ�ÿһ�εĿո񶼼���2������
	while (i != j && i >= 0)//i!=j���������Ϊ�˼������һ�οո�ǰ���ַ��滻������һЩ�Ż�
	{
		if (str[i] == ' ')//���Ų�����Լ����ƶ��Ĵ���������ԭ��Ҳ����Ҫ��ǰ�ߵ�
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

//�����ַ����滻->������ȡ�ɣ�ֱ�ӽ��ո��ӡ���ַ�����
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