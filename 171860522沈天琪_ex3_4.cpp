#include<iostream>
#include<cmath>
using namespace std;
#define E 0.000001

int main()
{
	double x, x1 = 0, x2;
	printf("������Ŀ������\n");
	cin >> x;
	x2 = x;
	while (fabs(x2 - x1) >= E)
	{
		x1 = x2;
		x2 = (2 * x1 + x / (x1 * x1))/3;
	}
	printf("Ŀ������������Ϊ��%.2f", x2);
	system("pause");
	return 0;
}
