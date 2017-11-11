#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	for (a = 0; a <= 9; a++)
	for (b = 0; b <= 9; b++)
	{
		c = 1100 * a + 11 * b;
		for (int i = 0; i <= sqrt(c) + 1;i++)
		if (i*i == c&&a!=b)
		{
			cout << c << endl;
			break;
		}
	
	}
	system("pause");
	return 0;
}
