#include<iostream>
#include<cstdio>
using namespace std;

int CountDigit(int n)//���庯������������n��
{
	int i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}

	return i;         //����λ����
}

int KthDigit(int n, int k)//���庯������������n��Ŀ��λ��k��
{
	int temp = 0;
	for (int i = 1; i < k; i++)
		n /= 10;
	temp = n % 10;

	return temp;//����λֵ��
}

int main()
{
	int m, n, k;
	printf("������һ��������\n");
	cin >> n;
	m = CountDigit(n);
	k = m / 2;
	printf("%d��һ��%dλ�������%dλ��Ϊ%d\n", n, m, k, KthDigit(n, k));

	system("pause");
	return 0;
}