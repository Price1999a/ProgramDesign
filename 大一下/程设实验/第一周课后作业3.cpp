#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int sum_(int n[])
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum += n[i];
	return sum;
}

int largest(int n[])
{
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < n[i])
			max = n[i];
	}
	return max;
}

bool judging(int n1[], int n2[])
{
	int sum = sum_(n2);
	if (sum <= 3||(sum==4&&largest(n2)==4))
	{
		for (int i = 9; i > 0; i--)
		{
			if (n1[i] > n2[i] && n1[i] >= sum && n2[i] < sum)
				return true;
			else if (n1[i] < n2[i])
				return false;
			else if (n1[i] == n2[i] && n1[i] > 0)
				return false;
		}
	}
	else if (sum == 4)
	{
		int i,j;
		for (i = 0; n2[i] == 0; i++);
		for (j = 9; j > 0; j--)
			if (n1[j] >= 2 && n1[j - 1] >= 2)
				break;
		j--;
		//cout << i << endl << j << endl;
		if (j > i)
			return true;
		else
			return false;
	}
	else if (sum == 6)
	{
		int i, j;
		for (i = 0; n2[i] == 0; i++);
		for (j = 9; j > 0; j--)
			if (n1[j] >= 3 && n1[j - 1] >= 3)
				break;
		j--;
		//cout << i << endl << j << endl;
		if (j > i)
			return true;
		else
			return false;
	}
	else if (sum == 5)
	{
		int i, j;
		for (i = 0; n2[i] == 0; i++);
		for (j = 9; j > 0; j--)
			if (n1[j] >= 1 && n1[j - 1] >= 1&&n1[j-2]>=1 && n1[j - 3] >= 1 && n1[j - 4] >= 1)
				break;
		j-=4;
		//cout << i << endl << j << endl;
		if (j > i)
			return true;
		else
			return false;
	}
}



int main()
{
	int in = 0;
	cin >> in;
	for (int i1 = 0; i1 < in; i1++) 
	{
		int my[10] = {}, his[10] = {};
		char c = 0;
		cin >> c;
		while (c != '\n')
		{
			my[c - '0']++;
			c = getchar();
		}
		cin >> c;
		while (c != '\n')
		{
			his[c - '0']++;
			c = getchar();
		}
		if (judging(my, his))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		//cout << endl;
	}
	system("pause");
	return 0;
}