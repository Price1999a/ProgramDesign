#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
#define MIN 1e-5
using namespace std;

double ComputeLineK(double p1x, double p1y, double p2x, double p2y)
{
	if (p1x == p2x)
		return INT_MAX;
	return (p2y - p1y) / (p2x - p1x);
}

double ComputeLineB(double p1x, double p1y, double p2x, double p2y)
{
	if (p1x == p2x)
		return INT_MAX;
	return p1y - p1x*(p2y - p1y) / (p2x - p1x);
}

bool IsPointOnSegment(double p3x, double p3y, double k, double b, double p1x)
{
	if (k == INT_MAX)
	{
		if (p3x == p1x)
			return true;
	}
	if (fabs(p3y - k*p3x - b) <= MIN)
		return true;
	return false;
}

int main()
{
	double p1x, p2x, p1y, p2y, k, b, p3x, p3y;
	bool x = true;
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;
	k = ComputeLineK(p1x, p1y, p2x, p2y);
	b = ComputeLineB(p1x, p1y, p2x, p2y);
	x = IsPointOnSegment(p3x, p3y, k, b, p1x);

	if (k == INT_MAX)
	{
		printf("The equation is: x=%f; ", p1x);
		if (x == true)
			printf("The point is on the line segment.\n");
		else
			printf("The point is not on the line segment.\n");
	}
	else if (b == 0)
	{
		printf("The equation is: y=%fx; ", k);
		if (x == true)
			printf("The point is on the line segment.\n");
		else
			printf("The point is not on the line segment.\n");
	}
	else if (b>0)
	{
		printf("The equation is: y=%fx+%f; ", k, b);
		if (x == true)
			printf("The point is on the line segment.\n");
		else
			printf("The point is not on the line segment.\n");
	}
	else
	{
		printf("The equation is: y=%fx%f; ", k, b);
		if (x == true)
			printf("The point is on the line segment.\n");
		else
			printf("The point is not on the line segment.\n");
	}

	system("pause");
	return 0;
}