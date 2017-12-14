#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	union A {
		int i;
		char c;
		double d;
	};
	A a;

	a.i = 12;
	cout << a.c;
	system("pause");
	return 0;
}