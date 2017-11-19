#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define X 0.43

void Drawtri(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y)
{
	int a[21][21] = { 0 }; //预计坐标均大于等于0
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if ((j <= ((p1x > p2x) ? p1x : p2x)) && (j >= ((p1x<p2x) ? p1x : p2x)))
			if ((i <= ((p1y>p2y) ? p1y : p2y)) && (i >= ((p1y < p2y) ? p1y : p2y)))
			if (fabs(i - p1y - (j - p1x)*(p2y - p1y) / (p2x - p1x)) < X)
				a[i][j] = 1;
		}
	}
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if ((j <= ((p3x>p2x) ? p3x : p2x)) && (j >= ((p3x<p2x) ? p3x : p2x)))
			if ((i <= ((p3y>p2y) ? p3y : p2y)) && (i >= ((p3y < p2y) ? p3y : p2y)))
			if (fabs(i - p3y - (j - p3x)*(p2y - p3y) / (p2x - p3x)) < X)
				a[i][j] = 1;
		}
	}
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if ((j <= ((p3x>p1x) ? p3x : p1x)) && (j >= ((p3x<p1x) ? p3x : p1x)))
			if ((i <= ((p3y>p1y) ? p3y : p1y)) && (i >= ((p3y < p1y) ? p3y : p1y)))
			if (fabs(i - p3y - (j - p3x)*(p1y - p3y) / (p1x - p3x)) < X)
				a[i][j] = 1;
		}
	}
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (a[i][j] == 1)
				printf(" * ");
			else
				printf("   ");
		}
		printf("\n");
	}

}

int main()
{
	double p1x, p1y, p2x, p2y, p3x, p3y, a, b, c, p, s;
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	Drawtri(p1x, p1y, p2x, p2y, p3x, p3y);
	a = sqrt((p1x - p2x)*(p1x - p2x) + (p1y - p2y)*(p1y - p2y));
	b = sqrt((p3x - p2x)*(p3x - p2x) + (p3y - p2y)*(p3y - p2y));
	c = sqrt((p1x - p3x)*(p1x - p3x) + (p1y - p3y)*(p1y - p3y));
	p = (a + b + c) / 2;
	s = sqrt(p*(p - a)*(p - b)*(p - c));
	cout << s << endl;

	system("pause");
	return 0;
}