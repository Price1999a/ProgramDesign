#include<iostream>
#include<cstdio>
using namespace std;

<<<<<<< HEAD
int CountDigit(int n)//���庯������������n��
=======
int CountDigit(int n)
>>>>>>> 80b902d3373a52242eed3751892f693c45cc9fd5
{
	int i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}

<<<<<<< HEAD
	return i;         //����λ����
}

int KthDigit(int n, int k)//���庯������������n��Ŀ��λ��k��
=======
	return i;
}

int KthDigit(int n, int k)
>>>>>>> 80b902d3373a52242eed3751892f693c45cc9fd5
{
	int temp = 0;
	for (int i = 1; i < k; i++)
		n /= 10;
	temp = n % 10;

<<<<<<< HEAD
	return temp;//����λֵ��
=======
	return temp;
>>>>>>> 80b902d3373a52242eed3751892f693c45cc9fd5
}

int main()
{
	int m, n, k;
<<<<<<< HEAD
	printf("������һ��������\n");
	cin >> n;
	m = CountDigit(n);
	k = m / 2;
	printf("%d��һ��%dλ�������%dλ��Ϊ%d\n", n, m, k, KthDigit(n, k));
=======
	cin >> n;
	m = CountDigit(n);
	k = m / 2;
	printf("%d %d %d %d\n", n, m, k, KthDigit(n, k));
>>>>>>> 80b902d3373a52242eed3751892f693c45cc9fd5

	system("pause");
	return 0;
}