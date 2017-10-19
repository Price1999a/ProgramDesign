#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int c = 0;
	
	while (c != EOF)
	{
		printf("菜单：\n0:字符画1\n1:字符画2\n2:告诉你1+1到底是多少。\n3:结束这无聊的程序。\n");
		cin >> c;

		switch (c)
		{
		case 0: printf(">.<\n\n\n"); break;
		case 1: printf(">.<\n>.<\n显然这是字符画2。\n\n\n"); break;
		case 2: printf("这还要我告诉你？\n呵呵。\n\n\n"); break;
		case 3: c = EOF; break;
		default: printf("检测到严重错误！\n...................\n即将自动爆炸！\n...........\n请即刻输入正确值！\n\n\n"); break;
		}
	}
	printf("你以为我会让你轻易走？\n");
	system("pause");
	printf("再点点？\n");
	system("pause");
	printf("有耐性点。\n");
	system("pause");
	printf("加油！大概还有57下！\n");
	system("pause");
	printf("加油！大概还有56下！\n");
	system("pause");
	printf("加油！大概还有55下！\n");
	system("pause");
	printf("再见！\n");
	system("pause");
	printf("骗你的。\n");
	system("pause");
	printf("加油！大概还有52下！\n");
	system("pause");
	printf("再见。\n");
	system("pause");
	printf("这次是真的。\n");
	system("pause");
	return 0;
}
