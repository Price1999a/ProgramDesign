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
	printf("���м�λ����\n");
	cin >> n;
	printf("ȡ����λ����\n");
	cin >> r;
	if (n <= 0 || r <= 0 || n < r)
		printf("���Ϸ����룡\n");
	else
		printf("����%d��ѡ��\n", palieshu(n, r));

	system("pause");
	return 0;
}