#include<iostream>
using namespace std;

int main()
{
	int a, n, d, s = 0;
	printf("请依次输入一个等差数列的首项，项数，公差：\n");
	scanf("%d %d %d", &a, &n, &d);

	for(int i = 1; i <= n;i++)
	{
		s += a;
		a += d;
	}
	printf("对于该等差数列，其和为：%d 。\n", s);
	system("pause");
	return 0;
}
