#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int split(int x[],int first,int last)
{
	int split_point,pivot;
	pivot = x[first];
	split_point = first;
	for(int unknown=first+1;unknown<=last;unknown++)
		if(x[unknown]<pivot)
		{
			split_point++;
			int t = x[split_point];
			x[split_point]=x[unknown];
			x[unknown]=t;
		}
	x[first]=x[split_point];
	x[split_point]=pivot;
	return split_point;
}

void quick_sort(int x[],int first, int last)
{
	if(first<last)
	{
		int split_point;
		split_point= split(x,first,last);
		quick_sort(x,first,split_point-1);
		quick_sort(x,split_point+1,last);
	}
}

const int N = 10;

int main()
{
	int a[N], i;
	for (i = 0; i < N; i++)
		cin >> a[i];
	quick_sort(a,0,9);
	for (i = 0; i < N; i++)
		cout << a[i] << ' ' << endl;
	system("pause");
	return 0;
}
