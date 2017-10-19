#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double a = 6,b = 6;
	for (; a < 10000; a += 5)
	{
		b = a;
		for (int i = 1; i <= 5; ++i)
		{
			b = 0.8*(b - 1);
		}
		if (b == floor(b))
			break;
		else
			;
	}
	cout << a << "   " << b << endl;
	system("pause");
	return 0;
}