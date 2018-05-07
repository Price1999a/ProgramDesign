#pragma once

#include <QWidget>
#include "ui_qtproject1_login.h"

class project1login : public QWidget
{
	Q_OBJECT

public:
	project1login(QWidget *parent = Q_NULLPTR);
	~project1login();

public Q_SLOTS:
void slot_inputnamepassword();

private:
	Ui::project1login ui;
};
