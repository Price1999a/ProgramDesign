#include<iostream>
#include<cstdio>
using namespace std;

bool TongGouShu(int i)
{
	int a = 0, b = 0;
	for (a = 10; a <= 10000; a *= 10)
	{
		if (i / a == 0)
			break;
	}
	if ((i*i - i) % a == 0)
		return true;
	else
		return false;
}

int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (TongGouShu(i) == true)
			cout << i << endl;
	}

	//system("pause");
	return 0;
}
