#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n = 0,x = 0, s = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		s += x;
	}
	cout << s << endl;
	system("pause");
	return 0;
}