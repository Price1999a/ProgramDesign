#include<iostream>
#include<cstdio>
using namespace std;
#define N 5

int main()
{
	int a[N][N], b[N][N];

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		cin >> a[i][j];

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		b[j][i] = a[i][j];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << b[i][j] << "\t";
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}