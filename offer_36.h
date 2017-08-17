#include<iostream>
using namespace std;
#include<assert.h>

//数组中的逆序对

//O(N^2)
int GetInverseCount(int *a, int len)
{
	int count = 0;
	assert(a && len > 0);
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (a[i] > a[j])
			{
				count++;
			}
		}
	}
	return count;
}

//O(N)
int InversePairCore(int *a, int *tmp, int begin, int end)
{
	if (begin == end)
	{
		tmp[begin] = a[begin];
		return 0;
	}

	int len = (end - begin) / 2;
	int left = InversePairCore(tmp, a, begin, begin + len);//注意这里的两个数组参数
	int right = InversePairCore(tmp, a, begin + len + 1, end);

	int i = begin + len;
	int j = end;

	int index = end;
	int count = 0;

	while (i >= begin && j >= begin + len + 1)
	{
		if (a[i] > a[j])
		{
			tmp[index--] = a[i--];
			count += j - begin - len;
		}
		else
		{
			tmp[index--] = a[j--];
		}
	}

	for (; i >= begin; --i)
		tmp[index--] = a[i];
	for (; j >= begin + len + 1; --j)
		tmp[index--] = a[j];

	return left + right + count;
}

int InversePair(int *a, int len)
{
	assert(a && len > 0);

	int* tmp = new int[len];
	for (int i = 0; i < len; ++i)
		tmp[i] = a[i];

	int count = InversePairCore(a, tmp, 0, len - 1);

	delete[] tmp;
	return count;
}


void Test()
{
	int a[] = { 7, 5, 6, 4, 1};
	int len = sizeof(a) / sizeof(a[0]);
	cout << GetInverseCount(a, len) << endl;
	cout << InversePair(a, len) << endl;
}