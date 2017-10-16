#include<iostream>
using namespace std;

int main()
{
	int d1 = 0, d2 = 0, d3 = 1;
	while (d3 != EOF)
	{

		printf("请输入两个整数：\n注意：0表示程序结束！\n");
		cin >> d1 >> d2;
		printf("请输入除数：\n注意：0表示程序结束！\n");
		cin >> d3;
		if (d3 != 0&&d2 != 0&&d1 != 0)
		for (int i = d1; i <= d2; ++i)
		{
			if (i%d3 != 0)
				printf("不能被整除的数为：%d\n", i);
			else
				;
		}
		else
			d3 = EOF;
	}
		printf("欢迎使用，再见。\n");
	
	system("pause");
	return 0;
}
