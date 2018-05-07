#include "stdafx.h"
#include "qtproject1.h"

bool login_flag = false;

qtproject1::qtproject1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);


}

void qtproject1::solt_userlogin()
{
	login = new qtproject_login_new;
	login->setWindowTitle(QStringLiteral("用户登陆"));
	//login_flag = login->slot_accept();
	if (login->exec()==QDialog::Accepted)
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("登陆成功"));
		user = new usermenu;
		user->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("登陆失败"));;
}

void qtproject1::solt_usercreate()
{
	login = new qtproject_login_new;
	login->setWindowTitle(QStringLiteral("用户注册"));
	QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("假如注册时输入了相同的账号与密码，将直接登陆"));
	//login->exec();

	if (login->exec() == QDialog::Accepted)//todo
	{
		//QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("注册成功"));
		user = new usermenu;
		user->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("注册失败"));;
}

void qtproject1::solt_adminlogin()
{
	login = new qtproject_login_new;
	login->setWindowTitle(QStringLiteral("管理员登陆"));
	//login->exec();

	if (login->exec() == QDialog::Accepted)//todo
	{
		QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("登陆成功"));
		admin = new adminmune;
		admin->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("登陆失败"));;
}
