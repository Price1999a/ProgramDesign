#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;



int main()
{
	//char ch[256] = { '\0' };
	//cin >> ch;
	unsigned int a = 2147483648;//�޷����������߼����ƣ����Լ��㣩
	a = a >> 4;
	cout << hex << a << endl;
	a = 1073741824;
	a = a >> 4;
	cout << hex << a << endl;
	int b = -2147483647;//�з�������ͨ���������ƣ����ݷ���λ��0||1��
	b = b >> 4;
	cout << hex << b << endl;
	b = 1073741824;
	b = b >> 4;
	cout << hex << b << endl;
	                          //����ֻ���߼�����

	

	system("pause");
	return 0;
}