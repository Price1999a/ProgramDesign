#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<cstdio>
#include<iostream>
//注意：本cpp编译时关闭了vs的sdl安全检查！
using namespace std;
int temps = 0;
int sum = 0;
int random()    //用于产生0、2、4随机数。
{
	srand((int)time(NULL));//以时间为种子
	return rand() % 3 * 2;
}

int Print(int a[][4], int line)//打印二维数组、总分
{
	sum = 0;              //该全局变量仅用于该函数，我当时在干嘛？
	system("cls");        //清屏
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
	return 0;    //实际上该函数并不需要返回值，可以被定义为void类型。
}

int Up(int a[4][4])//同样，事实上不需要返回值。
{
	for (int j = 0; j <= 3; j++)//移位器
	{
		for (int temp = 0; temp <= 6; temp++)//检查6次在于最多可能会有3次相加与3次移位。
		{                                    //然而问题是实际上并不需要如此之多的检查步骤，完全不需要。
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
				                            //迷之空行，原因可能在于原有else；
			}
		}
	}
	temps = 0;
	for (int j = 0; j <= 2; j++)//随机数发生器（bug在这里，有时他不一定一定产生一个随机数。）
	{
		if (a[3][j] == 0)//该判断用于防止随机数代替原有数字
			a[3][j] = random();
		else
			continue;
		if (a[3][j] != 0)
		{
			++temps; break;//一旦产生随机数，立刻退出发生器，事实上这里使用return语句效率高。
		}
	}
	if (temps == 0 && a[3][3] == 0)//temps判断前面有没有产生过随机数了
		a[3][3] = 4;               //bug可能就在这里，如果前面产生的均为0且最后一位非0，他不会产生随机数。
	return 0;                      //a[3][3]=4，鉴于这次随机过程无法保证为非0，只好使用常量了。（实际是懒）
}

int Left(int a[4][4])//与up类似，这里存在一个问题，这4个操作函数是可以写到一起的。
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

int Right(int a[4][4])//同上
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

int Down(int a[4][4])//同上
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

int PanDing(int a[4][4])//判断这局是否结束。0代表未结束，-1表示结束。
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)//结束条件1：全部非0.
				return 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])//结束条件2：全部相邻元素无相同。判断两次，横纵各一次。
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
	srand((int)time(NULL));//主函数中的随机器，由于仅使用一次，未将其模块化。
	a1 = rand() % 4; a2 = rand() % 4; a3 = rand() % 4; a4 = rand() % 4;
	a[a1][a2] = 2; a[a3][a4] = 2;//这里存在a1==a3,a2==a4的可能，但不大，我还没跑出来过，假如要重构，这里也要改。
	Print(a, 4);//第一次输出。

	char ch = 0;//用于捕获键盘输入。
	while (ch != EOF)//事实上这是一个不可能的结束条件，键盘一个键输入不了EOF（-1）.
	{
		ch = getch();
		if (ch == 72)//实际上这里可以使用switch语句。
			Up(a);
		else if (ch == 75)
			Left(a);
		else if (ch == 77)
			Right(a);
		else if (ch == 80)
			Down(a);
		else
			continue;//跳过所有错误输入。
		Print(a, 4);

		if (PanDing(a) == -1)//捕获到结束条件时操作。
		{
			printf("您已无路可走。");
			break;
		}
	}
	system("pause");//防止一闪而过的结束语句与一脸懵逼的用户。
	return 0;
}