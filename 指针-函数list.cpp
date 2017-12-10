#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

typedef double(*PF)(double);
PF func_list[8] = { sin, cos, tan, asin, acos, atan, log, log10 };

int main()
{
	int index;
	double x;
	do
	{
		cout << "dd\n";
		cin >> index;
	} while (index<0 || index>7);
	cout << "canshu\n";
	cin >> x;
	cout << (*func_list[index])(x) << endl;

	system("pause");
	return 0;
}