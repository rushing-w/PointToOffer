#pragma once

//求一个数的二进制中1的个数


int NumOf1(int n)
{
	int count = 0;
	while (n)
	{
		if ((n & 1) == 1)
			count++;
		n = n >> 1;//使用右移符号较之除号，效率要高很多
	}

	return count;
}
//但是上面的代码有一个很大的问题，那就是不能处理负数，否则会陷入死循环

int NUmOf1_G(int n)
{
	int count = 0;
	int flag = 1;
	while (flag != 0) 
	{
		if ((n & flag) != 0)//1的二进制中只有最后一位为1，依次左移就相当于将1从左往右一步步移动，
		{					//然后相与得到这一位是不是为1
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

//最优解
int NumOf1_Y(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;//优化就在这里-->把一个整数减去1，再和原整数相与，会将最右边的1变成0。
	}					//那么一个数中有多少个1，就可以进行多少次这样的操作。
	return count;
}

// 以数字9为例
// 1001 & 1000 --> 1000
// 1000 & 0111 --> 0000  
// 2次

// 以数字11为例
// 1011 & 1010 --> 1010
// 1010 & 1001 --> 1000
// 1000 & 0001 --> 0000
// 3次


void TestNumOf1()
{
	cout << NumOf1_Y(9) << endl;
}