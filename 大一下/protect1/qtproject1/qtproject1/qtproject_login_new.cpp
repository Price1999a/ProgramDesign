#include "stdafx.h"
#include "qtproject_login_new.h"

qtproject_login_new::qtproject_login_new(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

qtproject_login_new::~qtproject_login_new()
{
}

/*QString * qtproject_login_new::get_login_information()
{
	QString s[2];
	s[0] = ui->lineEdit1->text();
	return s;
}*/

void qtproject_login_new::slot_accept() //完成！
{
	if (this->windowTitle()== QStringLiteral("用户登陆"))
	{
		CUser * userineed = CUser::getglobleuser();
		userineed->shoppingcart.cleanusershoppingcart();
		bool flag1 = false;
		for (int i_temp_ = 0; i_temp_ < 20; i_temp_++)
		{
			if (this->ui.lineEdit1->text() == tr(userineed->userslist[i_temp_].username) && this->ui.lineEdit2->text() == tr(userineed->userslist[i_temp_].password))
			{
				strcpy(userineed->currentuser.username, this->ui.lineEdit1->text().toLocal8Bit());
				flag1 = true;
				userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
				if (userineed->shoppingcart.freshshoppingcart() == true)
				{
					QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("购物车超限，超限商品已经清空。"));
					userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
				}
			}
		}

		if (flag1 == true)
			accept();
		else
			reject();
	}
	else if (this->windowTitle() == QStringLiteral("用户注册"))
	{
		CUser * userineed = CUser::getglobleuser();
		userineed->shoppingcart.cleanusershoppingcart();
		bool flag1 = false;
		for (int i_temp_ = 0; i_temp_ < 20; i_temp_++)
		{
			if (this->ui.lineEdit1->text() == tr(userineed->userslist[i_temp_].username))
			{
				if (this->ui.lineEdit2->text() == tr(userineed->userslist[i_temp_].password))
				{
					strcpy(userineed->currentuser.username, this->ui.lineEdit1->text().toLocal8Bit());
					flag1 = true;
					userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
					QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("账号密码相同，未注册。登陆成功！"));
					if (userineed->shoppingcart.freshshoppingcart() == true)
					{
						QMessageBox::warning(this, QStringLiteral("警告"), QStringLiteral("购物车超限，超限商品已经清空。"));
						userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
					}
					accept();
					return;
				}
				else
				{
					QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("账号相同，注册失败！"));
					reject();
					return;
				}
			}
		}

		flag1 = true;
		strcpy(userineed->currentuser.username, this->ui.lineEdit1->text().toLocal8Bit());
		strcpy(userineed->currentuser.password, this->ui.lineEdit2->text().toLocal8Bit());
		FILE * fp_out = fopen("用户.txt", "a+");
		fprintf(fp_out, "\n");
		fprintf(fp_out, "%s\t%s\n", userineed->currentuser.username, userineed->currentuser.password);
		fclose(fp_out);
		char userfilename[24] = { 0 };
		strcpy(userfilename, userineed->currentuser.username);
		strcat(userfilename, ".txt");
		FILE * fp_in = fopen(userfilename, "w");
		fprintf(fp_out, "ID\t名称\t品牌\t价格\t数量\n");
		fclose(fp_out);
		userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
		if (flag1 == true)
		{
			QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("注册成功！"));
			accept();
		}
		else
			reject();
	}
	else if (this->windowTitle() == QStringLiteral("管理员登陆"))
	{
		CAdmin * adminineed = CAdmin::getglobaladmin();
		if (this->ui.lineEdit1->text() == tr("Admin") && this->ui.lineEdit2->text() == tr("admin"))
		{
			adminineed->stocking.readstockfile();
			accept();
		}
		else
		{
			reject();
		}
	}
		//return true;
}