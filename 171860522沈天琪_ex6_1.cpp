#include<cstdio>
#include<iostream>

using namespace std;

int DieDai(int n)
{
	if (n == 1)
		return 1;
	else;
	int a = 1, b = 1;
	for (int i = 2; i <= n; i++)
	{
		int temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}

int DiGui(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return DiGui(n - 1) + DiGui(n - 2);
}
int main()
{
	int n = 0;
	cin >> n;
	cout << DieDai(n) << endl << DiGui(n);

	system("pause");
	return 0;
}