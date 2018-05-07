#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtproject1_main.h"
#include "qtproject_login_new.h"
#include "usermenu.h"
#include "adminmune.h"
#include <QtGui>
#include "admin.h"
#include "user.h"


class qtproject1 : public QMainWindow
{
	Q_OBJECT

public:
	qtproject1(QWidget *parent = Q_NULLPTR);
	

public Q_SLOTS:
	void solt_userlogin();
	void solt_usercreate();
	void solt_adminlogin();

private:
	Ui::qtproject1Class ui;
	qtproject_login_new * login;
	usermenu * user;
	adminmune * admin;
};
