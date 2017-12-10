#include<iostream>
#include<cstdio>
using namespace std;

void Print(int a, int i)
{
	if (i == 0);
	else
	{
		printf("%d(%d)", a, i);
	}
	//i = 0;(原来的一个bug)
}

int main()
{
	int n = 1, i = 0;
	cin >> n;
	while (n % 2 == 0)
	{
		n /= 2;
		i++;
	}
	Print(2, i); i = 0;
	for (int j = 3;n>1; j += 2)
	{
		while (n%j == 0)
		{
			n /= j;
			i++;
		}
		Print(j, i); i = 0;
	}


	//system("pause");
	return 0;
}