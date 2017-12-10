#include<cmath>
#include<cstdio>
#include<iostream>
#define DELTA 0.000001
using namespace std;

double Integrate(double(*pf)(double x), double x1, double x2)
{
	double s = 0;
	if (x1 == x2)
		return 0;
	else if (x1 > x2)
	{
		//cout << "case 1\n";
		for (double i = x2; i <= x1; i += DELTA)
		{
			s += DELTA*((*pf)(i)+(*pf)(i + DELTA)) / 2;
		}
		return -s;
		//s *= (-1);
		//return s;
	}
	else
	{
		//cout << "case 2\n";
		for (double i = x1; i <= x2; i += DELTA)
		{
			s += DELTA*((*pf)(i)+(*pf)(i + DELTA)) / 2;
		}
		return s;
	}

}

int main()
{
	double x1, x2;
	cin >> x1 >> x2;
	cout << Integrate(sin/*your function here*/, x1, x2);

	system("pause");
	return 0;
}
