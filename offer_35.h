#include<iostream>
using namespace std;

//第一个只出现一次的字符
char FindFirstOneStr(char* arr, int len)
{
	if (arr == NULL)
		return '\0';

	int hashtable[26] = { 0 };

	for (int i = 0; i < len; i++)
	{
		hashtable[arr[i] - 'a']++;
	}

	for (int i = 0; i < len; i++)
	{
		if (hashtable[arr[i] - 'a'] == 1)
			return arr[i];
	}
	return '\0';
}

void Test()
{
	char arr[] = "abcdefgabcdefabcdef";
	char c = FindFirstOneStr(arr, strlen(arr));
	cout << c << endl;
}