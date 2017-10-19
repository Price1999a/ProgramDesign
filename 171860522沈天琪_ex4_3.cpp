#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int i = 0,n = -1;
	char c;

	while ((c = getchar()) != '#')
	{
		++i;
		if (c == 'q')
		{
			n = i;
			break;
		}
		else
			;
	}
	cout << n << endl;
	
	system("pause");
	return 0;
}