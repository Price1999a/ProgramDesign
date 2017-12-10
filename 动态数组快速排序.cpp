#include<cmath>
#include<cstdio>
#include<iostream>
#define DELTA 0.000001
using namespace std;

int split(int x[], int first, int last)
{
	int split_point, pivot;
	pivot = x[first];
	split_point = first;
	for (int unknown = first + 1; unknown <= last; unknown++)
	if (x[unknown]<pivot)
	{
		split_point++;
		int t = x[split_point];
		x[split_point] = x[unknown];
		x[unknown] = t;
	}
	x[first] = x[split_point];
	x[split_point] = pivot;
	return split_point;
}

void quick_sort(int x[], int first, int last)
{
	if (first<last)
	{
		int split_point;
		split_point = split(x, first, last);
		quick_sort(x, first, split_point - 1);
		quick_sort(x, split_point + 1, last);
	}
}

int main()
{
	int n, i;
	int *pda;
	cin >> n;
	pda = new int[n];
	for (i = 0; i < n; i++)
		cin >> pda[i];
	quick_sort(pda, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << pda[i] << " ";
	cout << endl;
	delete []pda;

	system("pause");
	return 0;
}