#include<iostream>
using namespace std;

int main()
{
	int a, n, d, s = 0;
	printf("����������һ���Ȳ����е�������������\n");
	scanf("%d %d %d", &a, &n, &d);

	for(int i = 1; i <= n;i++)
	{
		s += a;
		a += d;
	}
	printf("���ڸõȲ����У����Ϊ��%d ��\n", s);
	system("pause");
	return 0;
}
