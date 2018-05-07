#pragma once

#include <QWidget>
#include "ui_input.h"

class input : public QWidget
{
	Q_OBJECT

public:
	input(QWidget *parent = Q_NULLPTR);
	~input();

public Q_SLOTS:
	void slot_lineinput();

private:
	Ui::input ui;
};
