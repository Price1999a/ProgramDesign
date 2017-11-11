#include<iostream>
#include<cstdio>
using namespace std;

int jiecheng(int m)
{
	int temp = 1;
	for (int i = 1; i <= m; i++)
		temp *= i;
	return temp;
}

int palieshu(int n, int r)
{
	int a;
	a = jiecheng(n) / (jiecheng(r)*jiecheng(n - r));
	return a;
}

int main()
{
	int n, r;
	printf("共有几位数？\n");
	cin >> n;
	printf("取出几位数？\n");
	cin >> r;
	if (n <= 0 || r <= 0 || n < r)
		printf("不合法输入！\n");
	else
		printf("共有%d种选择\n", palieshu(n, r));

	system("pause");
	return 0;
}