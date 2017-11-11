#include<cstdio>
#include<iostream>
using namespace std;
int ZhongZhi(int a, int b, int c)
{
	return ((a < b&&b < c) || (c < b&&b < a)) ? b : (((b < a&&a < c) || (c < a&&a < b)) ? a : c);
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", ZhongZhi(a, b, c));
	system("pause");
	return 0;
}