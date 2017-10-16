#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cout << "请输入一个整数：\n";
	cin >> n;

	if (1 - n > n - 1)
		cout << "1-n比n-1更大。\n";
	else if (1 - n == n - 1)
		cout << "1-n和n-1一样大。\n";
	else
		cout << "1-n比n-1小。\n";

	cout << "比较完成。\n";
	system("pause");
	return 0;
}
