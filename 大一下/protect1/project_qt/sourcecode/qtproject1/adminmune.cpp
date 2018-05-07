#include "stdafx.h"
#include "adminmune.h"

adminmune::adminmune(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.admintable->setRowCount(200);
	ui.admintable->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ�еķ�ʽ
	ui.admintable->setEditTriggers(QAbstractItemView::NoEditTriggers);   //��ֹ�޸�
	ui.admintable->setSelectionMode(QAbstractItemView::SingleSelection);  //����Ϊ����ѡ�е���
	ui.admintable->verticalHeader()->setVisible(false);
}

adminmune::~adminmune()
{
}

void adminmune::slot_printadmin()
{
	ui.admintable->clear();
	CAdmin * adminineed = CAdmin::getglobaladmin();
	int j_temp_ = 0;
	for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
	{
		if (adminineed->stocking.stocklist[i_temp_].price <= 0) { continue; }
		ui.admintable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].id)));
		ui.admintable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].name)));
		ui.admintable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].brand)));
		ui.admintable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].price)));
		ui.admintable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].number)));
		j_temp_++;
	}
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("����") << QStringLiteral("Ʒ��") << QStringLiteral("�۸�") << QStringLiteral("����");
	ui.admintable->setHorizontalHeaderLabels(header);
	ui.admintable->update();
}

void adminmune::slot_add_stock()
{
	//ui.admintable->clear();
	Commodity addstock;
	memset(&addstock, 0, sizeof(Commodity));
	CAdmin * adminineed = CAdmin::getglobaladmin();
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("�����뽫����������Ʒ��"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_name = inputwindows->getinput();
		strcpy(addstock.name, temp_name.toLocal8Bit());
		input_new inputwindows2;
		inputwindows2.setWindowTitle(QStringLiteral("�����뽫����������ƷƷ��"));
		if (inputwindows2.exec() == QDialog::Accepted)
		{
			QString temp_brand = inputwindows2.getinput();
			strcpy(addstock.brand, temp_brand.toLocal8Bit());
			int i;
			bool flag_change = false;
			for (i = 0; i < 100; i++)
			{
				if (strcmp(addstock.name, adminineed->stocking.stocklist[i].name) == 0)
					if (strcmp(addstock.brand, adminineed->stocking.stocklist[i].brand) == 0)
					{
						input_new inputwindows3;
						inputwindows3.setWindowTitle(QStringLiteral("�����뽫����������Ʒ����"));
						if (inputwindows3.exec() == QDialog::Accepted)
						{
							QString temp_number = inputwindows3.getinput();
							if (adminineed->stocking.stocklist[i].number == -1)
								adminineed->stocking.stocklist[i].number += temp_number.toInt() + 1;
							else
								adminineed->stocking.stocklist[i].number += temp_number.toInt();
							flag_change = true;
							break;
						}
					}
			}
			if (flag_change == false)
			{
				i = 0;
				while (adminineed->stocking.stocklist[i].name[0] != 0)i++;
				char idtemp[6] = { 0 };
				idtemp[0] = '1';
				for (int j = 0; j < 5; j++)idtemp[j + 1] = adminineed->stocking.stocklist[i - 1].id[j + 1];
				int idtemp1 = atoi(idtemp);
				idtemp1++;
				itoa(idtemp1, idtemp, 10);
				idtemp[0] = adminineed->stocking.stocklist[i - 1].id[0];
				strcpy(adminineed->stocking.stocklist[i].id, idtemp);
				strcpy(adminineed->stocking.stocklist[i].brand, addstock.brand);
				strcpy(adminineed->stocking.stocklist[i].name, addstock.name);
				input_new inputwindows3;
				inputwindows3.setWindowTitle(QStringLiteral("�����뽫����������Ʒ����"));
				if (inputwindows3.exec() == QDialog::Accepted)
				{
					QString temp_number = inputwindows3.getinput();
					input_new inputwindows4;
					inputwindows4.setWindowTitle(QStringLiteral("�����뽫����������Ʒ�۸�"));
					if (inputwindows4.exec() == QDialog::Accepted)
					{
						QString temp_price = inputwindows4.getinput();
						adminineed->stocking.stocklist[i].number = temp_number.toInt();
						adminineed->stocking.stocklist[i].price = temp_price.toFloat();
					}
				}
				//cout << "������۸����������Կո�ָ�����";
				//cin >> stocklist[i].price >> stocklist[i].number;
			}
			adminineed->stocking.writeinstockfile();
			//to display the new table
			ui.admintable->clear();
			int j_temp_ = 0;
			for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
			{
				if (adminineed->stocking.stocklist[i_temp_].price <= 0) { continue; }
				ui.admintable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].id)));
				ui.admintable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].name)));
				ui.admintable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].brand)));
				ui.admintable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].price)));
				ui.admintable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].number)));
				j_temp_++;
			}
			QStringList header;
			header << QStringLiteral("ID") << QStringLiteral("����") << QStringLiteral("Ʒ��") << QStringLiteral("�۸�") << QStringLiteral("����");
			ui.admintable->setHorizontalHeaderLabels(header);
			ui.admintable->update();
		}
	}
}

void adminmune::slot_del_stock()
{
	//ui.admintable->clear();
	CAdmin * adminineed = CAdmin::getglobaladmin();
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("�����뽫�Կ����ɾ������Ʒ���"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_id = inputwindows->getinput();
		char aimid[6] = {};
		strcpy(aimid, temp_id.toLocal8Bit());
		int i = 0;
		for (i = 0; i < 100; i++)
			if (strcmp(aimid, adminineed->stocking.stocklist[i].id) == 0)
				break;
		if (i == 100)
		{
			QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("ɾ��ʧ�ܣ����ٴμ�������ţ�"));
			return;
		}
		adminineed->stocking.stocklist[i].number = -1;
		ui.admintable->clear();
		int j_temp_ = 0;
		for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
		{
			if (adminineed->stocking.stocklist[i_temp_].number <= 0) { continue; }
			ui.admintable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].id)));
			ui.admintable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].name)));
			ui.admintable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].brand)));
			ui.admintable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].price)));
			ui.admintable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].number)));
			j_temp_++;
		}
		QStringList header;
		header << QStringLiteral("ID") << QStringLiteral("����") << QStringLiteral("Ʒ��") << QStringLiteral("�۸�") << QStringLiteral("����");
		ui.admintable->setHorizontalHeaderLabels(header);
		ui.admintable->update();
		adminineed->stocking.writeinstockfile();
		QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("ɾ���ɹ���"));
		return;
	}
	else
		return;
}

void adminmune::slot_modify_stock()
{
	CAdmin * adminineed = CAdmin::getglobaladmin();
	inputwindows = new input_new;
	inputwindows->setWindowTitle(QStringLiteral("�����뽫�Կ�����޸ĵ���Ʒ���"));
	if (inputwindows->exec() == QDialog::Accepted)
	{
		QString temp_id = inputwindows->getinput();
		char aimid[6] = {};
		strcpy(aimid, temp_id.toLocal8Bit());
		int i = 0;
		for (i = 0; i < 100; i++)
			if (strcmp(aimid, adminineed->stocking.stocklist[i].id) == 0)
				break;
		if (i == 100)
		{
			QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("�޸�ʧ�ܣ�δ��鵽����Ʒ�����ٴμ�������ţ�"));
			return;
		}
		input_new inputwindows2;
		inputwindows2.setWindowTitle(QStringLiteral("�����뽫�Կ�����޸ĵ���Ʒ��Ϣ"));
		if (inputwindows2.exec() == QDialog::Accepted)
		{
			QString temp_info = inputwindows2.getinput();
			if (strcmp("����",temp_info.toLocal8Bit())==0)
			{
				input_new inputwindows3;
				inputwindows3.setWindowTitle(QStringLiteral("������������Ϣ"));
				if (inputwindows3.exec() == QDialog::Accepted)
				{
					QString temp_name = inputwindows3.getinput();
					strcpy(adminineed->stocking.stocklist[i].name, temp_name.toLocal8Bit());
				}
			}
			else if (strcmp("Ʒ��", temp_info.toLocal8Bit()) == 0)
			{
				input_new inputwindows3;
				inputwindows3.setWindowTitle(QStringLiteral("������������Ϣ"));
				if (inputwindows3.exec() == QDialog::Accepted)
				{
					QString temp_brand = inputwindows3.getinput();
					strcpy(adminineed->stocking.stocklist[i].brand, temp_brand.toLocal8Bit());
				}
			}
			else if (strcmp("�۸�", temp_info.toLocal8Bit()) == 0)
			{
				input_new inputwindows3;
				inputwindows3.setWindowTitle(QStringLiteral("������������Ϣ"));
				if (inputwindows3.exec() == QDialog::Accepted)
				{
					QString temp_price = inputwindows3.getinput();
					adminineed->stocking.stocklist[i].price = temp_price.toFloat();
				}
			}
			else if (strcmp("����", temp_info.toLocal8Bit()) == 0)
			{
				input_new inputwindows3;
				inputwindows3.setWindowTitle(QStringLiteral("������������Ϣ"));
				if (inputwindows3.exec() == QDialog::Accepted)
				{
					QString temp_number = inputwindows3.getinput();
					adminineed->stocking.stocklist[i].number = temp_number.toInt();
				}
			}
			else
				QMessageBox::warning(this, QStringLiteral("��ʾ"), QStringLiteral("������󣬾ܾ�����"));
		}
	}
	ui.admintable->clear();
	int j_temp_ = 0;
	for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
	{
		if (adminineed->stocking.stocklist[i_temp_].number <= 0) { continue; }
		ui.admintable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].id)));
		ui.admintable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].name)));
		ui.admintable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->stocking.stocklist[i_temp_].brand)));
		ui.admintable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].price)));
		ui.admintable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(adminineed->stocking.stocklist[i_temp_].number)));
		j_temp_++;
	}
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("����") << QStringLiteral("Ʒ��") << QStringLiteral("�۸�") << QStringLiteral("����");
	ui.admintable->setHorizontalHeaderLabels(header);
	ui.admintable->update();
	adminineed->stocking.writeinstockfile();
	//QMessageBox::information(this, QStringLiteral("��ʾ"), QStringLiteral("�޸ĳɹ���"));
}

void adminmune::slot_printsoldlist()
{
	ui.admintable->clear();
	CAdmin * adminineed = CAdmin::getglobaladmin();
	adminineed->soldlist.readsoldlist();
	int j_temp_ = 0;
	for (int i_temp_ = 0; i_temp_ < 100; i_temp_++)
	{
		if (adminineed->soldlist.soldlist[i_temp_].soldcommodity.number <= 0) { continue; }
		ui.admintable->setItem(j_temp_, 0, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->soldlist.soldlist[i_temp_].soldcommodity.id)));
		ui.admintable->setItem(j_temp_, 1, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->soldlist.soldlist[i_temp_].soldcommodity.name)));
		ui.admintable->setItem(j_temp_, 2, new QTableWidgetItem(QString::fromLocal8Bit(adminineed->soldlist.soldlist[i_temp_].soldcommodity.brand)));
		ui.admintable->setItem(j_temp_, 3, new QTableWidgetItem(QString::number(adminineed->soldlist.soldlist[i_temp_].soldcommodity.price)));
		ui.admintable->setItem(j_temp_, 4, new QTableWidgetItem(QString::number(adminineed->soldlist.soldlist[i_temp_].soldcommodity.number)));
		j_temp_++;
	}
	QStringList header;
	header << QStringLiteral("ID") << QStringLiteral("����") << QStringLiteral("Ʒ��") << QStringLiteral("�۸�") << QStringLiteral("����");
	ui.admintable->setHorizontalHeaderLabels(header);
	ui.admintable->update();
}
