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
	login->setWindowTitle(QStringLiteral("�û���½"));
	//login_flag = login->slot_accept();
	if (login->exec()==QDialog::Accepted)
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("��½�ɹ�"));
		user = new usermenu;
		user->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("��½ʧ��"));;
}

void qtproject1::solt_usercreate()
{
	login = new qtproject_login_new;
	login->setWindowTitle(QStringLiteral("�û�ע��"));
	QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("����ע��ʱ��������ͬ���˺������룬��ֱ�ӵ�½"));
	//login->exec();

	if (login->exec() == QDialog::Accepted)//todo
	{
		//QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ע��ɹ�"));
		user = new usermenu;
		user->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("ע��ʧ��"));;
}

void qtproject1::solt_adminlogin()
{
	login = new qtproject_login_new;
	login->setWindowTitle(QStringLiteral("����Ա��½"));
	//login->exec();

	if (login->exec() == QDialog::Accepted)//todo
	{
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("��½�ɹ�"));
		admin = new adminmune;
		admin->show();
	}
	else
		QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("��½ʧ��"));;
}
