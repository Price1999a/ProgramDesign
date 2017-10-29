#include<iostream>
#include<cstdio>
using namespace std;

int CountDigit(int n)
{
	int i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}

	return i;
}

int KthDigit(int n, int k)
{
	int temp = 0;
	for (int i = 1; i < k; i++)
		n /= 10;
	temp = n % 10;

	return temp;
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