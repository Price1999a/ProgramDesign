#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void sel_sort(int x[], int n)
{
	for (; n > 1; n--)
	{
		int i_max = 0;
		for (int i = 1; i < n; i++)
			if (x[i] > x[i_max]) i_max = i;
		int temp = x[i_max];
		x[i_max] = x[n - 1];
		x[n - 1] = temp;
	}
}
const int N = 10;

int main()
{
	int a[N], i;
	for (i = 0; i < N; i++)
		cin >> a[i];
	sel_sort(a, N);
	for (i = 0; i < N; i++)
		cout << a[i] << ' ' << endl;
	system("pause");
	return 0;
}