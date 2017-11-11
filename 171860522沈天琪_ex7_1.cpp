#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	double a = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
			a += (1 / (double)i);
		else
			a -= (1 / (double)i);
	}
	cout << a;
	system("pause");
	return 0;
}