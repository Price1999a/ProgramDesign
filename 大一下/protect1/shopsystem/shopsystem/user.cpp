#include "user.h"

bool CUser::usercomfirmation()
{
	CTracker tracker("CUser::usercomfirmation");
	FILE * fp_in = fopen("用户.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	int n = 0;
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
	n = 0;
	cout << "请输入用户名：";
	cin >> inputuser.username;
	while (userslist[n].username[0] != 0)
		if (strcmp(userslist[n].username, inputuser.username) == 0)
			break;
		else
			n++;
	if (userslist[n].username[0] == 0)
	{
		cerr << "用户名不存在！" << endl;
		return false;
	}
	cout << "请输入密码：" << endl;
	cin >> inputuser.password;
	if (strcmp(userslist[n].password, inputuser.password) == 0)
		return true;
	else
	{
		cerr << "密码错误！" << endl;
		return false;
	}
}

void CUser::userbuild()
{
	CTracker tracker("CUser::userbuild");
	strcpy(currentuser.username, inputuser.username);
	strcpy(currentuser.password, inputuser.password);
	stocking.readstockfile();
	shoppingcart.readshoppingcartfile(currentuser);
}

void CUser::printusermune()
{
	CTracker tracker("CUser::printusermune");
	printf("==========================================================================================================\n");
	printf("1.注销登陆    2.查看商品    3.商品搜索    4.添加商品至购物车    5.删除购物车商品    6.查看购物车    7.结账\n");
	printf("==========================================================================================================\n");
	printf("请输入操作：");
}

void CUser::builduserslist()
{
	CTracker tracker("CUser::builduserslist");
}

bool CUser::createnewuser()
{
	CTracker tracker("CUser::createnewuser");
	return true;
}

bool CUser::checkduplicationusername()
{
	CTracker tracker("CUser::checkduplicationusername");

	return true;
}
