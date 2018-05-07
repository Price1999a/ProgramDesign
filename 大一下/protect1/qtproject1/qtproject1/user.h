#pragma once
#include "stdafx.h"
#include "struct.h"
#include "shop.h"
using namespace std;
class CUser
{
private:
	
protected:
	
public:
	User userslist[20];//
	User inputuser;//输入的用户
	CShoppingCart shoppingcart;
	CStock stocking;
	CUser() {
		memset(userslist, 0, 20 * sizeof(User));
		memset(&currentuser, 0, sizeof(User));
		memset(&inputuser, 0, sizeof(User));
		builduserslist();
	}
	User currentuser;//当前用户信息（不应将密码复制过来！）
	bool usercomfirmation();//用户验证
	void userbuild();//验证成功后创建完整用户类（读取关键性数据创建CStock类、CShoppinglist类）
	void printusermune();//打印用户目录
	void builduserslist();//建立已有用户表
	bool createnewuser();//创建新用户1.输入2.验证用户名是否重复3.若重复，尝试登陆，失败则返回0,若通过重复性验证则创建用户，并创建用户类
	void printstock() {
		stocking.printusersstocklist();
	}
	void searchstock() {
		stocking.searchusersstocklist();
	}
	void printshoppingcart() {
		shoppingcart.printusersstocklist();
	}
	void addshoppingcart() {
		shoppingcart.addshoppingcart();
		if (shoppingcart.checkshoppingcartrequest())
			shoppingcart.writeinshopplingcartfile(currentuser);
		else
		{
			shoppingcart.cleanusershoppingcart();
			shoppingcart.readshoppingcartfile(currentuser);
		}
		shoppingcart.printusersstocklist();
	}
	void delshoppingcart() {
		shoppingcart.deletestocklist();
		shoppingcart.writeinshopplingcartfile(currentuser);
		shoppingcart.printusersstocklist();
	}
	void pay()//付款，整合库存类与购物车类的一系列操作
	{
		shoppingcart.writeinsoldlistfile(currentuser);//追加写入已售清单
		shoppingcart.modifystocklistfile();//修改库存文件清空购物车
		shoppingcart.writeinshopplingcartfile(currentuser);//写入购物车
	}
	static CUser * getglobleuser()
	{
		static CUser globleuser;
		return &globleuser;
	}
};