#include "stdafx.h"
#include "input_new.h"
#include "admin.h"
#include "user.h"

input_new::input_new(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

input_new::~input_new()
{
}

void input_new::slot_lineinput() 
{
	if (this->windowTitle() == QStringLiteral("请输入搜索的商品名"))
	{
		
	}
	else if (this->windowTitle() == QStringLiteral("请输入将添加入购物车的的商品编号"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("请输入将自购物车删除的商品名"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("请输入将添加入库存的商品名"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("请输入将自库存中删除的商品名"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("请输入将修改的商品名"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("用户登陆"))
	{

	}
	//QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("点击"));
	accept();
}