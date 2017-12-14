#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char * DeleteSubstring(char ch[], const char * ch_z)
{
	int n1 = strlen(ch_z);
	//cout << n1;

	for (char * pch = ch; (*pch) != '\0'; pch++)
	{
		int i;
		for (i = 0; i < n1; i++)
			if (pch[i] != ch_z[i])
				break;
			else
				;
		if (i == n1)
			for (char *temp = pch; (*temp) != '\0'; temp++)
				temp[0] = temp[n1];
		else;
	}

	return ch;
}

int main()
{
	char ch[256] = "aaa1aaa2aaa345aaa67ag89aaa", ch_z[256] = "aaa";
	cin >> ch >> ch_z;
	cout << DeleteSubstring(ch, ch_z);

	//system("pause");
	return 0;
}
