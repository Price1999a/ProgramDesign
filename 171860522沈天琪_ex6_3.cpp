#include<cstdio>
#include<iostream>

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

int E(int i, int k)
{
	int b=1;
	for (int a = 2; a <= k - i; a++)
		b *= 10;
	return b;
}

int IntRevs(int n)
{
	int a[10] = { 0 };
	int temp = 0,k = CountDigit(n);
	for (int i = 0; i <= 9; i++)
	{
		a[i] = n % 10;
		n = n / 10;
		temp = a[i] * E(i,k) + temp;
	}
	
	return temp;
}
int main()
{
	int n = 0;
	cin >> n;
	cout << IntRevs(n) << endl;

	system("pause");
	return 0;
}