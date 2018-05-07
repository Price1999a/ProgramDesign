#include "user.h"

bool CUser::usercomfirmation()
{
	//CTracker tracker("CUser::usercomfirmation");
	/*FILE * fp_in = fopen("用户.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
	n = 0;//*/
	int n = 0;
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
	cout << "请输入密码：";
	cin >> inputuser.password;
	if (strcmp(userslist[n].password, inputuser.password) == 0)
	{
		printf("**********\n");
		printf("登陆成功！\n");
		printf("**********\n");
		return true;
	}
	else
	{
		cerr << "密码错误！" << endl;
		return false;
	}
}

void CUser::userbuild()
{
	//CTracker tracker("CUser::userbuild");
	strcpy(currentuser.username, inputuser.username);
	//strcpy(currentuser.password, inputuser.password);//没有必要复制密码
	stocking.readstockfile();
	shoppingcart.readshoppingcartfile(currentuser);
	shoppingcart.freshshoppingcart();
	shoppingcart.writeinshopplingcartfile(currentuser);
}

void CUser::printusermune()
{
	//CTracker tracker("CUser::printusermune");
	printf("==========================================================================================================\n");
	printf("1.注销登陆    2.查看商品    3.商品搜索    4.添加商品至购物车    5.删除购物车商品    6.查看购物车    7.结账\n");
	printf("==========================================================================================================\n");
	printf("请输入操作：");
}

void CUser::builduserslist()
{
	//CTracker tracker("CUser::builduserslist");
	FILE * fp_in = fopen("用户.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	int n = 0;
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
}

bool CUser::createnewuser()
{
	//CTracker tracker("CUser::createnewuser");
	cout << "输入用户名：";
	cin >> inputuser.username;
	cout << "输入密码：";
	cin >> inputuser.password;
	for (int i = 0; i < 20; i++)
	{
		if(strcmp(inputuser.username,userslist[i].username)==0)
			if (strcmp(inputuser.password, userslist[i].password) == 0)
			{
				strcpy(currentuser.username, inputuser.username);
				return true;
			}
			else
			{
				cout << "用户名被占用！创建新用户失败" << endl;
				return false;
			}
	}
	FILE * fp_out = fopen("用户.txt", "a+");
	fprintf(fp_out, "%s\t%s\n", inputuser.username, inputuser.password);
	fclose(fp_out);
	char userfilename[24] = { 0 };
	strcpy(userfilename, inputuser.username);
	strcat(userfilename, ".txt");
	FILE * fp_in = fopen(userfilename, "w");
	fprintf(fp_out, "ID\t名称\t品牌\t价格\t数量\n");
	fclose(fp_out);
	printf("*******************\n");
	printf("注册成功！登陆成功！\n");
	printf("*******************\n");
	return true;
}

