#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n = 0, b = 0; //n件数 b单价 
	cin >> n >> b;

	if (n < 10)
		cout << n*b + 10 << endl;
	else if (n >= 10 && n < 30)
		cout << n*b*0.9 << endl;
	else
		cout << n*b*0.8 << endl;

	return 0;
}