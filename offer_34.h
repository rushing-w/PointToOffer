#include<iostream>
using namespace std;

//��ȡ����
bool IsUglyNum(int n)
{
	while (n % 2 == 0)
		n /= 2;

	while (n % 3 == 0)
		n /= 3;

	while (n % 5 == 0)
		n /= 5;

	if (n == 1)
		return true;
	else
		return false;
}

int GetUglyNum(int index)
{
	if (index <= 0)
		return 0;

	int num = 0;
	int flag = 0;
	while (flag < index)
	{
		++num;
		if (IsUglyNum(num))
			++flag;
	}
	return num;
}

int Min(int n1, int n2, int n3)
{
	int min = n1;
	if (n2 < n1)
		min = n2;
	if (min>n3)
		min = n3;
	return min;
}
//����һ���������鱣���ź���ĳ���
int GetUglyNum_2(int index)
{
	if (index <= 0)
		return 0;
	int* arr = new int[index];
	arr[0] = 1;
	int uglyindex = 1;

	int* num_2 = arr;
	int* num_3 = arr;
	int* num_5 = arr;

	while (uglyindex < index)
	{
		int min = Min(*num_2 * 2, *num_3 * 3, *num_5 * 5);
		arr[uglyindex] = min;
		
		//�ҵ��ȵ�ǰֵ��ĵ�һ������Ȼ������ѭ����ȡ�������н�Сֵ
		while (*num_2 * 2 <= arr[uglyindex])
			++num_2;

		while (*num_3 * 3 <= arr[uglyindex])
			++num_3;

		while (*num_5 * 5 <= arr[uglyindex])
			++num_5;

		++uglyindex;
	}

	int ugly = arr[uglyindex - 1];
	delete[] arr;
	return ugly;
}

void Test()
{
	cout << GetUglyNum(15) << endl;
	cout << GetUglyNum_2(150) << endl;
}