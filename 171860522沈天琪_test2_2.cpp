#include<iostream>
#include<cstdio>
using namespace std;

int HouZiChiTao(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 4;
	else if (n == 3)
		return 10;
	else if (n == 4)
		return 22;
	else
		return (2 * (HouZiChiTao(n - 1) + 1));
}

int main()
{
	int n = 1;
	cin >> n;
	cout << HouZiChiTao(n) << " " << HouZiChiTao(10) << endl;

	//system("pause");
	return 0;
}