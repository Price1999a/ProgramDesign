#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<cstdio>
#include<iostream>

using namespace std;
int temps = 0;
int sum = 0;
int random()
{
	srand((int)time(NULL));
	return rand() % 3 * 2;
}

int Print(int a[][4], int line)
{
	sum = 0;
	system("cls");
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum += a[i][j];
			cout << a[i][j] << "\t";
		}
		cout << endl << endl;
	}
	printf("您的总分为%d.\n", sum);
	return 0;
}

int Up(int a[4][4])
{
	for (int j = 0; j <= 3; j++)
	{
		for (int temp = 0; temp <= 6; temp++)
		{
			for (int i = 3; i >= 1; i--)
			{
				if (a[i - 1][j] == 0)
				{
					a[i - 1][j] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[i - 1][j] == a[i][j])
				{
					a[i - 1][j] = a[i][j] * 2;
					a[i][j] = 0;
				}

			}
		}
	}
	temps = 0;
	for (int j = 0; j <= 2; j++)
	{
		if (a[3][j] == 0)
			a[3][j] = random();
		else
			continue;
		if (a[3][j] != 0)
		{
			++temps; break;
		}
	}
	if (temps == 0 && a[3][3] == 0)
		a[3][3] = 4;
	return 0;
}

int Left(int a[4][4])
{
	for (int i = 0; i <= 3; i++)
	{
		for (int temp = 0; temp <= 6; temp++)
		{
			for (int j = 3; j >= 1; j--)
			{
				if (a[i][j - 1] == 0)
				{
					a[i][j - 1] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[i][j - 1] == a[i][j])
				{
					a[i][j - 1] = a[i][j] * 2;
					a[i][j] = 0;
				}

			}
		}
	}
	temps = 0;
	for (int i = 0; i <= 2; i++)
	{
		if (a[i][3] == 0)
			a[i][3] = random();
		else
			continue;
		if (a[i][3] != 0)
		{
			++temps; break;
		}
	}
	if (temps == 0 && a[3][3] == 0)
		a[3][3] = 4;
	return 0;
}

int Right(int a[4][4])
{
	for (int i = 0; i <= 3; i++)
	{
		for (int temp = 0; temp <= 6; temp++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (a[i][j + 1] == 0)
				{
					a[i][j + 1] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[i][j + 1] == a[i][j])
				{
					a[i][j + 1] = a[i][j] * 2;
					a[i][j] = 0;
				}

			}
		}
	}
	temps = 0;
	for (int i = 0; i <= 2; i++)
	{
		if (a[i][0] == 0)
			a[i][0] = random();
		else
			continue;
		if (a[i][0] != 0)
		{
			++temps; break;
		}
	}
	if (temps == 0 && a[3][0] == 0)
		a[3][0] = 4;
	return 0;
}

int Down(int a[4][4])
{
	for (int j = 0; j <= 3; j++)
	{
		for (int temp = 0; temp <= 6; temp++)
		{
			for (int i = 0; i <= 2; i++)
			{
				if (a[i + 1][j] == 0)
				{
					a[i + 1][j] = a[i][j];
					a[i][j] = 0;
				}
				else if (a[i + 1][j] == a[i][j])
				{
					a[i + 1][j] = a[i][j] * 2;
					a[i][j] = 0;
				}

			}
		}
	}
	temps = 0;
	for (int j = 0; j <= 2; j++)
	{
		if (a[0][j] == 0)
			a[0][j] = random();
		else
			continue;
		if (a[0][j] != 0)
		{
			++temps; break;
		}
	}
	if (temps == 0 && a[0][3] == 0)
		a[0][3] = 4;
	return 0;
}

int PanDing(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)
				return 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])
				return 0;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (a[i][j] == a[i + 1][j])
				return 0;
		}
	}
	return -1;
}
int a[4][4] = { 0 };
int main()
{
	int a1, a2, a3, a4;
	srand((int)time(NULL));
	a1 = rand() % 4; a2 = rand() % 4; a3 = rand() % 4; a4 = rand() % 4;
	a[a1][a2] = 2; a[a3][a4] = 2;
	Print(a, 4);

	char ch = 0;
	while (ch != EOF)
	{
		ch = getch();
		if (ch == 72)
			Up(a);
		else if (ch == 75)
			Left(a);
		else if (ch == 77)
			Right(a);
		else if (ch == 80)
			Down(a);
		else
			continue;
		Print(a, 4);

		if (PanDing(a) == -1)
		{
			printf("您已无路可走。");
			break;
		}
	}
	system("pause");
	return 0;
}