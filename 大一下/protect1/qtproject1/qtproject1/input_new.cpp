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
	if (this->windowTitle() == QStringLiteral("��������������Ʒ��"))
	{
		
	}
	else if (this->windowTitle() == QStringLiteral("�����뽫����빺�ﳵ�ĵ���Ʒ���"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("�����뽫�Թ��ﳵɾ������Ʒ��"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("�����뽫����������Ʒ��"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("�����뽫�Կ����ɾ������Ʒ��"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("�����뽫�޸ĵ���Ʒ��"))
	{

	}
	else if (this->windowTitle() == QStringLiteral("�û���½"))
	{

	}
	//QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("���"));
	accept();
}