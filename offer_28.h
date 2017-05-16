#pragma once

#include<iostream>
using namespace std;
#include<string.h>

void _Permutation(char* str, size_t begin, size_t end)
{
	if (begin == end-1)
	{
		printf("%s\n", str);
		return;
	}
	else
	{
		for (size_t s = begin; s != end ; ++s)
		{
				std::swap(str[begin], str[s]);
			
			_Permutation(str, begin + 1, end);

			std::swap(str[begin], str[s]);
		}
	}
}

void Permutation(char* str)
{
	if (str == NULL)
		return;

	_Permutation(str, 0, strlen(str));
}

void TestPermutation()
{
	char str[] = "abc"; 
	Permutation(str);
}
