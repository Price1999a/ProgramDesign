#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double x, y;
	cout << "请输入乘出租车的公里数：\n";
	cin >> x;

	if (x <= 3)
		y = 9 + 1;
	else
		y = 9 + (x - 3) * 2.4 + 1;

	printf("乘坐该次出租车需要 %.1f 元。\n", y);
	system("pause");
	return 0;
}
