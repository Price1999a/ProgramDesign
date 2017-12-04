#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool SuShuPanDing(int n)
{
	int j = sqrt(n) + 1;
	if (n == 2 || n == 1)
		return true;
	else
	for (int i = 3; i < j; i += 2)
	{
		if (n%i == 0)
		{
			return false; break;
		}
	}
	return true;
}

int main()
{
	int n = 5000;
	while (n != -1)
	{
		cin >> n;
		cout << n;
		int p = n / 2 + 1;
		if (n == 4)
			printf("=1+3\n=2+2");
		else if (n == -1)
			break;
		else
		for (int i = 1; (i != -1) && (i <= p); i += 2)
		{
			if (SuShuPanDing(i) == true && SuShuPanDing(n - i) == true)
			{
				printf("=%d+%d£¬ÒÑÑéÖ¤¡£\n", i, n - i); i = -3;
			}

		}
	}
	//system("pause");
	return 0;
}
