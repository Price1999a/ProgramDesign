#pragma once
#include "struct.h"
#include "shop.h"
using namespace std;
class CUser
{
private:
	User userslist[20];//
	User currentuser;//��ǰ�û���Ϣ
	User inputuser;//������û�
	CShoppingCart shoppingcart;
protected:
	CStock stocking;
public:
	CUser() {
		memset(userslist, 0, 20 * sizeof(User));
		memset(&currentuser, 0, sizeof(User));
		memset(&inputuser, 0, sizeof(User));
		builduserslist();
	}
	bool usercomfirmation();//�û���֤
	void userbuild();//��֤�ɹ��󴴽������û��ࣨ��ȡ�ؼ������ݴ���CStock�ࡢCShoppinglist�ࣩ
	void printusermune();//��ӡ�û�Ŀ¼
	void builduserslist();//���������û���
	bool createnewuser();//�������û�1.����2.��֤�û����Ƿ��ظ�3.���ظ������Ե�½��ʧ���򷵻�0,��ͨ���ظ�����֤�򴴽��û����������û���
	bool checkduplicationusername();//�û����ظ����
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
			shoppingcart.readshoppingcartfile(currentuser);
	}
	void delshoppingcart() {
		shoppingcart.deletestocklist();
		if (shoppingcart.checkshoppingcartrequest())
			shoppingcart.writeinshopplingcartfile(currentuser);
		else
			shoppingcart.readshoppingcartfile(currentuser);
	}
	void pay()//������Ͽ�����빺�ﳵ���һϵ�в���
	{

	}
};