#include "stdafx.h"
#include "usermenu.h"

usermenu::usermenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.usertable->setRowCount(200);
	ui.usertable->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
	ui.usertable->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
	ui.usertable->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个
	ui.usertable->verticalHeader()->setVisible(false);
}

usermenu::~usermenu()
{
}

void usermenu::slot_printuser()
{
	ui.usertable->clear();
	CUser * userineed = CUser::getglobleuser();
	int j_temp_ = 0;
	for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
	{
		if (userineed->stocking.stocklist[i_temp_].number <= 0) {  continue; }
		ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].id)));
		ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].name)));
		ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].brand)));
		ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->stocking.stocklist[i_temp_].price)));
		ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->stocking.stocklist[i_temp_].number)));
		j_temp_++;
	}
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
	ui.usertable->setHorizontalHeaderLabels(header);
	ui.usertable->update();
}

void usermenu::slot_search()
{
	CUser * userineed = CUser::getglobleuser();
	int j_temp_ = 0;
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("请输入搜索的商品名"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_ = inputwindows->getinput();
		ui.usertable->clear();
		for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
		{
			if (userineed->stocking.stocklist[i_temp_].number <= 0) { continue; }
			QString temp = temp.fromLocal8Bit(userineed->stocking.stocklist[i_temp_].name);
			if (temp.contains(temp_, Qt::CaseSensitive) == true)
			{
				ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].id)));
				ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].name)));
				ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->stocking.stocklist[i_temp_].brand)));
				ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->stocking.stocklist[i_temp_].price)));
				ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->stocking.stocklist[i_temp_].number)));
				j_temp_++;
			}
		}
		QStringList header;
		header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
		ui.usertable->setHorizontalHeaderLabels(header);
		ui.usertable->update();
	}
}

void usermenu::slot_add_cart()
{
	CUser * userineed = CUser::getglobleuser();
	CAdmin * adminineed = CAdmin::getglobaladmin();
	bool flag = false;
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("请输入将添加入购物车的的商品编号"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_id = inputwindows->getinput();
		input_new inputwindows2;
		inputwindows2.setWindowTitle(QStringLiteral("请输入添加数量"));
		if (inputwindows2.exec() == QDialog::Accepted)
		{
			QString temp_number = inputwindows2.getinput();
			for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
			{
				if (temp_id == QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].id))
				{
					if (userineed->shoppingcart.stocklist[i_temp_].number == -1)
						userineed->shoppingcart.stocklist[i_temp_].number += 1 + temp_number.toInt();
					else 
						userineed->shoppingcart.stocklist[i_temp_].number += temp_number.toInt();
					flag = true;
				}
				if (flag == true)
				{
					if (userineed->shoppingcart.checkshoppingcartrequest() == true)
					{
						int j_temp_ = 0;
						for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
						{
							if (userineed->shoppingcart.stocklist[i_temp_].number <= 0) { continue; }
							ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].id)));
							ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].name)));
							ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].brand)));
							ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].price)));
							ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].number)));
							j_temp_++;
						}
						QStringList header;
						header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
						ui.usertable->setHorizontalHeaderLabels(header);
						ui.usertable->update();
						userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
						QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("添加购物车成功"));
						return;
					}
					else
					{
						userineed->shoppingcart.cleanusershoppingcart();
						userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
						QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("添加失败！请再次检查！"));
						return;
					}
				}
			}
			char inputid[6] = {};
			strcpy(inputid, temp_id.toLocal8Bit());
			int inputnumber = temp_number.toInt();
			int n = 0;
			CStock temp;
			temp.readstockfile();
			while (n < 100)
			{
				if (strcmp(temp.stocklist[n].id, inputid) == 0)
					break;
				n++;
			}
			int i = 0;
			for (;; i++)
			{
				if (userineed->shoppingcart.stocklist[i].price == 0)
					break;
			}
			//i++;
			strcpy(userineed->shoppingcart.stocklist[i].id, temp.stocklist[n].id);
			strcpy(userineed->shoppingcart.stocklist[i].brand, temp.stocklist[n].brand);
			strcpy(userineed->shoppingcart.stocklist[i].name, temp.stocklist[n].name);
			userineed->shoppingcart.stocklist[i].number = inputnumber;
			userineed->shoppingcart.stocklist[i].price = temp.stocklist[n].price;
			ui.usertable->clear();
			if (userineed->shoppingcart.checkshoppingcartrequest() == true)
			{
				int j_temp_ = 0;
				for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
				{
					if (userineed->shoppingcart.stocklist[i_temp_].number <= 0) { continue; }
					ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].id)));
					ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].name)));
					ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].brand)));
					ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].price)));
					ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].number)));
					j_temp_++;
				}
				QStringList header;
				header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
				ui.usertable->setHorizontalHeaderLabels(header);
				ui.usertable->update();
				userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
				QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("添加购物车成功"));
				return;
			}
			else
			{
				userineed->shoppingcart.cleanusershoppingcart();
				userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
				QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("添加失败！请再次检查！"));
				return;
			}
		}
		else
			return;
	}
	else
		return;
}

void usermenu::slot_del_cart()
{
	//ui.usertable->clear();
	CUser * userineed = CUser::getglobleuser();
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("请输入将自购物车删除的商品编号"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_id = inputwindows->getinput();
		char aimid[6] = {};
		strcpy(aimid, temp_id.toLocal8Bit());
		int i = 0;
		for (i = 0; i < 100; i++)
			if (strcmp(aimid, userineed->shoppingcart.stocklist[i].id) == 0)
				break;
		if (i == 100)
		{
			QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("删除失败！请再次检查输入编号！"));
			return;
		}
		userineed->shoppingcart.stocklist[i].number = -1;
		ui.usertable->clear();
		int j_temp_ = 0;
		for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
		{
			if (userineed->shoppingcart.stocklist[i_temp_].number <= 0) { continue; }
			ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].id)));
			ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].name)));
			ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].brand)));
			ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].price)));
			ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].number)));
			j_temp_++;
		}
		QStringList header;
		header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
		ui.usertable->setHorizontalHeaderLabels(header);
		ui.usertable->update();
		userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("删除成功！"));
		return;
	}
	else
		return;
}

void usermenu::slot_print_cart()
{
	//ui.usertable->clear();
	CUser * userineed = CUser::getglobleuser();
	ui.usertable->clear();
	int j_temp_ = 0;
	for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
	{
		if (userineed->shoppingcart.stocklist[i_temp_].number<=0) { continue; }
		ui.usertable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].id)));
		ui.usertable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].name)));
		ui.usertable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(userineed->shoppingcart.stocklist[i_temp_].brand)));
		ui.usertable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].price)));
		ui.usertable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(userineed->shoppingcart.stocklist[i_temp_].number)));
		j_temp_++;
	}
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("名称") << QStringLiteral("品牌") << QStringLiteral("价格") << QStringLiteral("数量");
	ui.usertable->setHorizontalHeaderLabels(header);
	ui.usertable->update();
}

void usermenu::slot_pay()
{
	ui.usertable->clear();
	CUser * userineed = CUser::getglobleuser();
	float sum = 0;
	for (int i = 0; i < 100; i++)
	{
		if (userineed->shoppingcart.stocklist[i].number <= 0)continue;
		sum += userineed->shoppingcart.stocklist[i].price*userineed->shoppingcart.stocklist[i].number;
	}
	QString sumstr = QString::number(sum);
	sumstr = QStringLiteral("共") + sumstr + QStringLiteral("元，是否付款？");
	if (QMessageBox::Yes == QMessageBox::question(this, QStringLiteral("付款页面"), sumstr, QMessageBox::Yes | QMessageBox::No))
	{
		userineed->pay();
		userineed->stocking.readstockfile();
		QMessageBox::information(this, QStringLiteral("付款成功"), QStringLiteral("付款成功！"));
	}
	else
		return;
	 
}
