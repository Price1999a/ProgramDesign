#pragma once
#include "stdafx.h"
#include "struct.h"
#include "user.h"
//#include "shop.h"
using namespace std;
class CAdmin :public CUser
{
private:
	
public:
	CSoldlist soldlist;
	bool adminconfirmaton();//����Ա�˻���֤
	void printadminmune();//��ӡ����ԱĿ¼
	void adminbuild();//������������Ա��
	void printadminstock() {
		stocking.printadminstocklist();
	}
	void addstock(){
		stocking.addstocklist();
		stocking.writeinstockfile();
		stocking.printadminstocklist();
	}
	void delstock() {
		stocking.deletestocklist();
		stocking.writeinstockfile();
		stocking.printadminstocklist();
	}
	void changestock() {
		stocking.changeadminstocklist();
		stocking.writeinstockfile();
		stocking.printadminstocklist();
	}
	void printsoldlist() {
		soldlist.readsoldlist();
		soldlist.printsoldlist();
	}
	static CAdmin * getglobaladmin()
	{
		static CAdmin globaladmin;
		return &globaladmin;
	}
};