#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n = 0, b = 1, temp = 0;
	cin >> n;

	for (; b <= n; ++b)//��1��n���� 
	{
		for (int i = 1; i < b; ++i)//��1��n-1�����������Լӡ� 
		{
			if (b%i == 0)
				temp += i;
			else;
		}
		if (temp == b)
			cout << b << ' ';
		else;
		temp = 0;
	}

	return 0;
}
