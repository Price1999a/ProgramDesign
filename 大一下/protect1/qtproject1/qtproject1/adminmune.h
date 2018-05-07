#pragma once

#include <QWidget>
#include "ui_adminmune.h"
#include "input.h"
#include "input_new.h"
#include "admin.h"
#include "user.h"

class adminmune : public QWidget
{
	Q_OBJECT

public:
	adminmune(QWidget *parent = Q_NULLPTR);
	~adminmune();

public Q_SLOTS:
	void slot_printadmin();
	void slot_add_stock();
	void slot_del_stock();
	void slot_modify_stock();
	void slot_printsoldlist();

private:
	Ui::adminmune ui;
	input_new * inputwindows;
};
