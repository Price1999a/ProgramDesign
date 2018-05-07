#pragma once

#include <QDialog>
#include "ui_input_new.h"
#include "admin.h"
#include "user.h"

class input_new : public QDialog
{
	Q_OBJECT

public:
	input_new(QWidget *parent = Q_NULLPTR);
	~input_new();
	QString getinput() {
		QString s = ui.inputliine->text();
		return s;
	}

public Q_SLOTS:
	void slot_lineinput();

private:
	Ui::input_new ui;
};
