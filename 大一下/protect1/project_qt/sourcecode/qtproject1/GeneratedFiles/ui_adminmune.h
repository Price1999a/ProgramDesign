/********************************************************************************
** Form generated from reading UI file 'adminmune.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMUNE_H
#define UI_ADMINMUNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminmune
{
public:
    QTableWidget *admintable;
    QSplitter *splitter;
    QPushButton *print_admin;
    QPushButton *add_stock;
    QPushButton *del_stock;
    QPushButton *modify_stock;
    QPushButton *print_soldlist;

    void setupUi(QWidget *adminmune)
    {
        if (adminmune->objectName().isEmpty())
            adminmune->setObjectName(QStringLiteral("adminmune"));
        adminmune->resize(858, 563);
        admintable = new QTableWidget(adminmune);
        if (admintable->columnCount() < 5)
            admintable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        admintable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        admintable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        admintable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        admintable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        admintable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        admintable->setObjectName(QStringLiteral("admintable"));
        admintable->setGeometry(QRect(30, 30, 541, 521));
        splitter = new QSplitter(adminmune);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(640, 90, 171, 361));
        splitter->setOrientation(Qt::Vertical);
        print_admin = new QPushButton(splitter);
        print_admin->setObjectName(QStringLiteral("print_admin"));
        splitter->addWidget(print_admin);
        add_stock = new QPushButton(splitter);
        add_stock->setObjectName(QStringLiteral("add_stock"));
        splitter->addWidget(add_stock);
        del_stock = new QPushButton(splitter);
        del_stock->setObjectName(QStringLiteral("del_stock"));
        splitter->addWidget(del_stock);
        modify_stock = new QPushButton(splitter);
        modify_stock->setObjectName(QStringLiteral("modify_stock"));
        splitter->addWidget(modify_stock);
        print_soldlist = new QPushButton(splitter);
        print_soldlist->setObjectName(QStringLiteral("print_soldlist"));
        splitter->addWidget(print_soldlist);

        retranslateUi(adminmune);
        QObject::connect(print_admin, SIGNAL(clicked()), adminmune, SLOT(slot_printadmin()));
        QObject::connect(add_stock, SIGNAL(clicked()), adminmune, SLOT(slot_add_stock()));
        QObject::connect(del_stock, SIGNAL(clicked()), adminmune, SLOT(slot_del_stock()));
        QObject::connect(modify_stock, SIGNAL(clicked()), adminmune, SLOT(slot_modify_stock()));
        QObject::connect(print_soldlist, SIGNAL(clicked()), adminmune, SLOT(slot_printsoldlist()));

        QMetaObject::connectSlotsByName(adminmune);
    } // setupUi

    void retranslateUi(QWidget *adminmune)
    {
        adminmune->setWindowTitle(QApplication::translate("adminmune", "\347\256\241\347\220\206\345\221\230\350\217\234\345\215\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = admintable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("adminmune", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = admintable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("adminmune", "\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = admintable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("adminmune", "\345\223\201\347\211\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = admintable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("adminmune", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = admintable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("adminmune", "\346\225\260\351\207\217", Q_NULLPTR));
        print_admin->setText(QApplication::translate("adminmune", "\346\237\245\350\257\242\345\225\206\345\223\201", Q_NULLPTR));
        add_stock->setText(QApplication::translate("adminmune", "\345\242\236\345\212\240\345\225\206\345\223\201", Q_NULLPTR));
        del_stock->setText(QApplication::translate("adminmune", "\345\210\240\351\231\244\345\225\206\345\223\201", Q_NULLPTR));
        modify_stock->setText(QApplication::translate("adminmune", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", Q_NULLPTR));
        print_soldlist->setText(QApplication::translate("adminmune", "\345\224\256\350\264\247\346\270\205\345\215\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adminmune: public Ui_adminmune {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMUNE_H
