#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	double x;
	srand(time(NULL));
	for (int i = 0; i <= 9; i++)
	{
		x = rand() % 100000;
		x = x / 100000;
		cout << x << endl;
	}
	system("pause");
	return 0;
}