#pragma once
#include "struct.h"

class CStock//库存类
{
	friend class CShoppingCart;
protected:
	Commodity stocklist[100];//库存中至多有100条记录
public:
	CStock() {
		memset(&stocklist[0], 0, 100 * sizeof(Commodity));//不会被继承
		readstockfile();
	}
	void readstockfile();//读取库存文件初始化CStock类
	void printadminstocklist();//打印管理员所看到的商品目录（显示为数量为0的商品）
	void printusersstocklist();//打印用户所看到的商品目录（不显示数量为0的商品）//又被购物车类继承 用于查看购物车
	void addstocklist();//在商品列表中增加商品
	void changeadminstocklist();//修改商品信息（特别的，特指修改商品的数量）
	void deletestocklist();//在商品列表中删除某一商品的行为（数量置为-1）//被购物车类继承  用于删除购物车内商品
	void searchusersstocklist();//用户功能，用以查询商品的名称
	void writeinstockfile();//将目前内存文件覆盖写入文件//不被继承！！！预计将被频繁调用（假如在最后统一写入内存，修改将不会是实时的）
};

class CShoppingCart: public CStock//购物车类继承自库存类
{
public:
	CShoppingCart() {
		memset(&stocklist, 0, 100 * sizeof(Commodity));
	}
	void readshoppingcartfile(User);//读取当前用户的购物车文件写入内存（依赖于当前用户类提供的用户名）
	void writeinshopplingcartfile(User);//将目前购物车文件覆盖写入文件
	bool checkshoppingcartrequest();//检查购物车是否超限，在修改时检查，假如超限，拒绝请求。
	void cleanusershoppingcart() {
		memset(&stocklist, 0, 100 * sizeof(Commodity));
	}//清理购物车，用于购买后。
	void writeinsoldlistfile(User a);//写入已售清单
	void modifystocklistfile();//修改库存文件
	void addshoppingcart();
	void freshshoppingcart();
	bool sumprice();//计算总价
};

class CSoldlist//已售清单 功能：打印已售清单 注：向已售清单中写入一事由购物车类负责，原因在于已售清单文件可以追加方式写入
{
private:
	Soldlist soldlist[2000];//极端情形下2000条记录各不相同（可能性极小）
public:
	CSoldlist() {
		memset(&soldlist, 0, 2000 * sizeof(Soldlist));
	}
	void printsoldlist();//打印已售清单  注意先检查id是否为空，若是空，要求其不予显示
	void readsoldlist();//读取以及合并(同价格，同商品)已售清单  最后引用qsort函数
	static int compare(const void *a, const void *b);//注意！要求升序  再次注意！尚未测试过，可预料到strcmp对空字符串的行为是将其作为最小的
};
