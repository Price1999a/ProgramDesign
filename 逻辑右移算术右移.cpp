#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;



int main()
{
	//char ch[256] = { '\0' };
	//cin >> ch;
	unsigned int a = 2147483648;//无符号整数，逻辑右移（无脑加零）
	a = a >> 4;
	cout << hex << a << endl;
	a = 1073741824;
	a = a >> 4;
	cout << hex << a << endl;
	int b = -2147483647;//有符号数，通常算数右移（根据符号位加0||1）
	b = b >> 4;
	cout << hex << b << endl;
	b = 1073741824;
	b = b >> 4;
	cout << hex << b << endl;
	                          //左移只有逻辑左移

	

	system("pause");
	return 0;
}