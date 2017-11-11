#include<iostream>
#include<cstdio>
using namespace std;

int CountDigit(int n)//定义函数，输入整数n。
{
	int i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}

	return i;         //返回位数。
}

int KthDigit(int n, int k)//定义函数，输入整数n与目标位置k。
{
	int temp = 0;
	for (int i = 1; i < k; i++)
		n /= 10;
	temp = n % 10;

	return temp;//返回位值。
}

int main()
{
	int m, n, k;
	printf("请输入一个正整数\n");
	cin >> n;
	m = CountDigit(n);
	k = m / 2;
	printf("%d是一个%d位数，其第%d位数为%d\n", n, m, k, KthDigit(n, k));

	system("pause");
	return 0;
}