#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double x, y;
	cout << "������˳��⳵�Ĺ�������\n";
	cin >> x;

	if (x <= 3)
		y = 9 + 1;
	else
		y = 9 + (x - 3) * 2.4 + 1;

	printf("�����ôγ��⳵��Ҫ %.1f Ԫ��\n", y);
	system("pause");
	return 0;
}
