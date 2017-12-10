#include<iostream>
#include<cstdio>
using namespace std;
#define N 8

void BubbleSort(int a[])
{
	int temp = 0;
	for (int i = 0; i < N;i++)
	for (int j = 9; i < j; j--)
	{
		if (a[j] < a[j - 1])
		{
			temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
	}
}

int main()
{
	int a[N] = { 0 };
	int k = 0;

	for (int i = 0; i < N; ++i)
		cin >> a[i];
	cin >> k;
	BubbleSort(a);
	cout << a[N - k] << endl;

	system("pause");
	return 0;
}
