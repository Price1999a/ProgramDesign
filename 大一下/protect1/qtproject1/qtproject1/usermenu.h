#pragma once

#include <QWidget>
#include "ui_usermenu.h"
//#include "input.h"
#include "input_new.h"
#include "admin.h"
#include "user.h"

class usermenu : public QWidget
{
	Q_OBJECT

public:
	usermenu(QWidget *parent = Q_NULLPTR);
	~usermenu();

public Q_SLOTS:
	void slot_printuser();
	void slot_search();
	void slot_add_cart();
	void slot_del_cart();
	void slot_print_cart();
	void slot_pay();

private:
	Ui::usermenu ui;
	input_new * inputwindows;
};
