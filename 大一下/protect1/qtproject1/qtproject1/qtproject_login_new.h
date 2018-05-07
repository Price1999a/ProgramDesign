#pragma once

#include <QDialog>
#include "ui_qtproject_login_new.h"
#include "admin.h"
#include "user.h"

class qtproject_login_new : public QDialog
{
	Q_OBJECT

public:
	qtproject_login_new(QWidget *parent = Q_NULLPTR);
	~qtproject_login_new();
	//QString * get_login_information();

public Q_SLOTS:
	void slot_accept();

private:
	Ui::qtproject_login_new ui;
};
