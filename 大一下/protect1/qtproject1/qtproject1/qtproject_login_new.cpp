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

void qtproject_login_new::slot_accept() //��ɣ�
{
	if (this->windowTitle()== QStringLiteral("�û���½"))
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
					QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("���ﳵ���ޣ�������Ʒ�Ѿ���ա�"));
					userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
				}
			}
		}

		if (flag1 == true)
			accept();
		else
			reject();
	}
	else if (this->windowTitle() == QStringLiteral("�û�ע��"))
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
					QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�˺�������ͬ��δע�ᡣ��½�ɹ���"));
					if (userineed->shoppingcart.freshshoppingcart() == true)
					{
						QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("���ﳵ���ޣ�������Ʒ�Ѿ���ա�"));
						userineed->shoppingcart.writeinshopplingcartfile(userineed->currentuser);
					}
					accept();
					return;
				}
				else
				{
					QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("�˺���ͬ��ע��ʧ�ܣ�"));
					reject();
					return;
				}
			}
		}

		flag1 = true;
		strcpy(userineed->currentuser.username, this->ui.lineEdit1->text().toLocal8Bit());
		strcpy(userineed->currentuser.password, this->ui.lineEdit2->text().toLocal8Bit());
		FILE * fp_out = fopen("�û�.txt", "a+");
		fprintf(fp_out, "\n");
		fprintf(fp_out, "%s\t%s\n", userineed->currentuser.username, userineed->currentuser.password);
		fclose(fp_out);
		char userfilename[24] = { 0 };
		strcpy(userfilename, userineed->currentuser.username);
		strcat(userfilename, ".txt");
		FILE * fp_in = fopen(userfilename, "w");
		fprintf(fp_out, "ID\t����\tƷ��\t�۸�\t����\n");
		fclose(fp_out);
		userineed->shoppingcart.readshoppingcartfile(userineed->currentuser);
		if (flag1 == true)
		{
			QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ע��ɹ���"));
			accept();
		}
		else
			reject();
	}
	else if (this->windowTitle() == QStringLiteral("����Ա��½"))
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