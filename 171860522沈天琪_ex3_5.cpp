#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float i, j, k, n;
	printf("������һ�����ڶ���������\n");
	cin >> n;
	k = (n + 1) / 2;
	for (j = 1; j <= n; ++j)
	{
		for (i = 1; i <= n; ++i)
		{
			if (fabs(i - k) <= k - 1 - fabs(k - j))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
