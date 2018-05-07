#include "admin.h"

bool CAdmin::adminconfirmaton()
{
	//CTracker tracker("CAdmin::adminconfirmaton");
	char admin[20] = { 0 }, adminpassword[20] = { 0 };
	cout << "输入管理员ID：";
	cin >> admin;
	if (strcmp(admin, "Admin"))
	{
		cout << "管理员ID错误！" << endl;
		return false;
	}
	cout << "输入管理员密码：";
	cin >> adminpassword;
	if (strcmp(adminpassword, "admin"))
	{
		cout << "管理员密码错误！" << endl;
		return false;
	}
	return true;
}

void CAdmin::printadminmune()
{
	//CTracker tracker("CAdmin::printadminmune");

	printf("====================================================================================\n");
	printf("0.注销登陆    1.查询商品    2.增加商品    3.删除商品    4.修改商品数量    5.售货清单\n");
	printf("====================================================================================\n");
	printf("请输入操作：");
}

void CAdmin::adminbuild()
{
	//CTracker tracker("CAdmin::adminbuild");
	stocking.readstockfile();
}
