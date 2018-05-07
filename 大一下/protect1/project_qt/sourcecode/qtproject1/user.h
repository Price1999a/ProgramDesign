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
	User inputuser;//������û�
	CShoppingCart shoppingcart;
	CStock stocking;
	CUser() {
		memset(userslist, 0, 20 * sizeof(User));
		memset(&currentuser, 0, sizeof(User));
		memset(&inputuser, 0, sizeof(User));
		builduserslist();
	}
	User currentuser;//��ǰ�û���Ϣ����Ӧ�����븴�ƹ�������
	bool usercomfirmation();//�û���֤
	void userbuild();//��֤�ɹ��󴴽������û��ࣨ��ȡ�ؼ������ݴ���CStock�ࡢCShoppinglist�ࣩ
	void printusermune();//��ӡ�û�Ŀ¼
	void builduserslist();//���������û���
	bool createnewuser();//�������û�1.����2.��֤�û����Ƿ��ظ�3.���ظ������Ե�½��ʧ���򷵻�0,��ͨ���ظ�����֤�򴴽��û����������û���
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
	void pay()//������Ͽ�����빺�ﳵ���һϵ�в���
	{
		shoppingcart.writeinsoldlistfile(currentuser);//׷��д�������嵥
		shoppingcart.modifystocklistfile();//�޸Ŀ���ļ���չ��ﳵ
		shoppingcart.writeinshopplingcartfile(currentuser);//д�빺�ﳵ
	}
	static CUser * getglobleuser()
	{
		static CUser globleuser;
		return &globleuser;
	}
};