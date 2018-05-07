//#include "struct.h"
#include "admin.h"
#include "user.h"

void printmainmune();

int main()
{
	char instruction = 0;
	//CAdmin test;
	//test.printadminmune();
	while (1)
	{
		printmainmune();
		cin >> instruction;
		if (instruction == '*')break;
		else if (instruction == '1')
		{
			CUser user;
			instruction = 0;
			if (!user.usercomfirmation())continue;
			user.userbuild();
			while (instruction != '1')
			{
				user.printusermune();
				instruction = getchar();
				instruction = getchar();
				if (instruction == '2')
					user.printstock();
				else if (instruction == '3')
					user.searchstock();
				else if (instruction == '4')
					user.addshoppingcart();
				else if (instruction == '5')
					user.delshoppingcart();
				else if (instruction == '6')
					user.printshoppingcart();
				else if (instruction == '7')
				{
					user.pay();
					user.userbuild();
				}
			}
		}
		else if (instruction == '2')
		{
			CUser user;
			instruction = 0;
			if (!user.createnewuser())continue;
			user.userbuild();
			while (instruction != '1')
			{
				user.printusermune();
				instruction = getchar();
				instruction = getchar();
				if (instruction == '2')
					user.printstock();
				else if (instruction == '3')
					user.searchstock();
				else if (instruction == '4')
					user.addshoppingcart();
				else if (instruction == '5')
					user.delshoppingcart();
				else if (instruction == '6')
					user.printshoppingcart();
				else if (instruction == '7')
				{
					user.pay();
					user.userbuild();
				}
			}
		}
		else if (instruction == '3')
		{
			CAdmin admin;
			if (!admin.adminconfirmaton())continue;
			admin.adminbuild();
			while (instruction != '0')
			{
				admin.printadminmune();
				instruction = getchar();
				instruction = getchar();
				if (instruction == '1')
					admin.printadminstock();
				else if (instruction == '2')
					admin.addstock();
				else if (instruction == '3')
					admin.delstock();
				else if (instruction == '4')
					admin.changestock();
				else if (instruction == '5')
					admin.printsoldlist();
			}
		}

	}

	system("pause");
	return 0;
}

void printmainmune()
{
	printf("======================================================\n");
	printf("1.用户登陆    2.用户注册    3.管理员登陆    *.退出系统\n");
	printf("======================================================\n");
	printf("请输入操作：");
}