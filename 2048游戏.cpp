#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<cstdio>
#include<iostream>
//ע�⣺��cpp����ʱ�ر���vs��sdl��ȫ��飡
using namespace std;
int temps = 0;
int sum = 0;
int random()    //���ڲ���0��2��4�������
{
	srand((int)time(NULL));//��ʱ��Ϊ����
	return rand() % 3 * 2;
}

int Print(int a[][4], int line)//��ӡ��ά���顢�ܷ�
{
	sum = 0;              //��ȫ�ֱ��������ڸú������ҵ�ʱ�ڸ��
	system("cls");        //����
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum += a[i][j];
			cout << a[i][j] << "\t";
		}
		cout << endl << endl;
	}
	printf("�����ܷ�Ϊ%d.\n", sum);
	return 0;    //ʵ���ϸú���������Ҫ����ֵ�����Ա�����Ϊvoid���͡�
}

int Up(int a[4][4])//ͬ������ʵ�ϲ���Ҫ����ֵ��
{
	for (int j = 0; j <= 3; j++)//��λ��
	{
		for (int temp = 0; temp <= 6; temp++)//���6�����������ܻ���3�������3����λ��
		{                                    //Ȼ��������ʵ���ϲ�����Ҫ���֮��ļ�鲽�裬��ȫ����Ҫ��
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
				                            //��֮���У�ԭ���������ԭ��else��
			}
		}
	}
	temps = 0;
	for (int j = 0; j <= 2; j++)//�������������bug�������ʱ����һ��һ������һ�����������
	{
		if (a[3][j] == 0)//���ж����ڷ�ֹ���������ԭ������
			a[3][j] = random();
		else
			continue;
		if (a[3][j] != 0)
		{
			++temps; break;//һ������������������˳�����������ʵ������ʹ��return���Ч�ʸߡ�
		}
	}
	if (temps == 0 && a[3][3] == 0)//temps�ж�ǰ����û�в������������
		a[3][3] = 4;               //bug���ܾ���������ǰ������ľ�Ϊ0�����һλ��0������������������
	return 0;                      //a[3][3]=4�����������������޷���֤Ϊ��0��ֻ��ʹ�ó����ˡ���ʵ��������
}

int Left(int a[4][4])//��up���ƣ��������һ�����⣬��4�����������ǿ���д��һ��ġ�
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

int Right(int a[4][4])//ͬ��
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

int Down(int a[4][4])//ͬ��
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

int PanDing(int a[4][4])//�ж�����Ƿ������0����δ������-1��ʾ������
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] == 0)//��������1��ȫ����0.
				return 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] == a[i][j + 1])//��������2��ȫ������Ԫ������ͬ���ж����Σ����ݸ�һ�Ρ�
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
	srand((int)time(NULL));//�������е�����������ڽ�ʹ��һ�Σ�δ����ģ�黯��
	a1 = rand() % 4; a2 = rand() % 4; a3 = rand() % 4; a4 = rand() % 4;
	a[a1][a2] = 2; a[a3][a4] = 2;//�������a1==a3,a2==a4�Ŀ��ܣ��������һ�û�ܳ�����������Ҫ�ع�������ҲҪ�ġ�
	Print(a, 4);//��һ�������

	char ch = 0;//���ڲ���������롣
	while (ch != EOF)//��ʵ������һ�������ܵĽ�������������һ�������벻��EOF��-1��.
	{
		ch = getch();
		if (ch == 72)//ʵ�����������ʹ��switch��䡣
			Up(a);
		else if (ch == 75)
			Left(a);
		else if (ch == 77)
			Right(a);
		else if (ch == 80)
			Down(a);
		else
			continue;//�������д������롣
		Print(a, 4);

		if (PanDing(a) == -1)//���񵽽�������ʱ������
		{
			printf("������·���ߡ�");
			break;
		}
	}
	system("pause");//��ֹһ�������Ľ��������һ���±Ƶ��û���
	return 0;
}