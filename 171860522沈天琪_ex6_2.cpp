#include<cstdio>
#include<iostream>

using namespace std;
int n = 0;
int Houzi(int i)
{
	if (n == 5)
	{
		n = 0; return i;
	}
	else if ((i - 1) % 5 != 0||i<=0)
	{
		n = 0; return -1;
	}
	else if ((i - 1) % 5 == 0)
	{
		i = (i - 1) / 5 * 4;
		++n;
		return Houzi(i);
	}
}

int main()
{
	int i = 6,b = 0;
	for (;; i += 5)
	{
		if (Houzi(i) == -1);
		else
		{
			b = Houzi(i);
			break;
		}
	}
	
	cout << i << " " << b;
	return 0;
}
