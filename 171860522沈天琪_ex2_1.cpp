#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	cout << "������һ��������\n";
	cin >> n;

	if (1 - n > n - 1)
		cout << "1-n��n-1����\n";
	else if (1 - n == n - 1)
		cout << "1-n��n-1һ����\n";
	else
		cout << "1-n��n-1С��\n";

	cout << "�Ƚ���ɡ�\n";
	system("pause");
	return 0;
}
