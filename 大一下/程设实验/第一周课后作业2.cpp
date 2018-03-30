#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int location(char a[])
{
	int n = 0;
	while (a[n] != '.')
	{
		n++;
		if (a[n] == 0)
			return -1;
	}
	return n;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i1 = 0; i1 < n; i1++)
	{
		char n1[100] = {}, n2[100] = {}, answer_temp[200] = {}, answer[200] = {};
		int n_dec1 = 0, n_dec2 = 0, n_len1 = 0, n_len2 = 0;
		cin >> n1 >> n2;
		n_dec1 = location(n1);
		n_dec2 = location(n2);
		n_len1 = strlen(n1);
		n_len2 = strlen(n2);


		int a = n_len1 - n_dec1;
		int b = n_len2 - n_dec2;
		int m = 0;
		int a_flag = 0, b_flag = 0;

		if (n_dec1 == -1 && n_dec2 == -1)
			goto L1;
		else if (n_dec1 == -1)
			a = 1, a_flag = 1;
		else if (n_dec2 == -1)
			b = 1, b_flag = 1;

		while (a > b)
		{
			answer_temp[m] = n1[n_len1 - 1];
			m++;
			n_len1--;
			a--;
		}
		while (a < b)
		{
			answer_temp[m] = n2[n_len2 - 1];
			m++;
			n_len2--;
			b--;
		}
		while (a > 2 || b > 2)
		{
			answer_temp[m] = n1[n_len1 - 1] + n2[n_len2 - 1] - '0';
			if (answer_temp[m] > '9')
			{
				answer_temp[m] -= 10;
				n1[n_len1 - 2]++;
			}
			m++; a--, b--; n_len1--, n_len2--;
		}

		if (a == 2 || b == 2)
		{
			answer_temp[m] = n1[n_len1 - 1] + n2[n_len2 - 1] - '0';
			if (answer_temp[m] > '9')
			{
				answer_temp[m] -= 10;
				n1[n_len1 - 3]++;
			}
			m++; a--, b--; n_len1--, n_len2--;
		}
		else if (a_flag)
			n_len1++;
		else if (b_flag)
			n_len2++;
		answer_temp[m] = '.';
		m++; a--, b--; n_len1--, n_len2--;

	L1: int flag = 0;

		while (n_len1 > 0 && n_len2 > 0)
		{
			answer_temp[m] = n1[n_len1 - 1] + n2[n_len2 - 1] - '0' + flag;
			flag = 0;
			if (answer_temp[m] > '9')
			{
				answer_temp[m] -= 10;
				flag = 1;
			}
			m++; n_len1--, n_len2--;
		}
		while (n_len1 > 0)
		{
			if (flag == 1)
			{
				n1[n_len1 - 1]++;
				flag = 0;
			}
			if (n1[n_len1 - 1] > '9')
			{
				n1[n_len1 - 1] -= 10;
				flag = 1;
			}
			answer_temp[m] = n1[n_len1 - 1];
			m++;
			n_len1--;
		}
		while (n_len2 > 0)
		{
			if (flag == 1)
			{
				n2[n_len2 - 1]++;
				flag = 0;
			}
			if (n2[n_len2 - 1] > '9')
			{
				n2[n_len2 - 1] -= 10;
				flag = 1;
			}
			answer_temp[m] = n2[n_len2 - 1];
			m++;
			n_len2--;
		}
		if (flag == 1)
			answer_temp[m] = '1';
		int i = 0, j = strlen(answer_temp);
		for (i = 0; i < j; i++)
			answer[i] = answer_temp[j - i - 1];
		cout << answer << endl;
	}
	system("pause");
	return 0;
}