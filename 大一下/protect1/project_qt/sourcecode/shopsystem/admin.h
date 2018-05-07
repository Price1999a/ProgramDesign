#pragma once
#include "struct.h"
#include "user.h"
//#include "shop.h"
using namespace std;
class CAdmin :public CUser
{
private:
	CSoldlist soldlist;
public:
	bool adminconfirmaton();//管理员账户验证
	void printadminmune();//打印管理员目录
	void adminbuild();//创建完整管理员类
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
};