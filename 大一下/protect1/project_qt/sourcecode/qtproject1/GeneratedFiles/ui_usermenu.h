/********************************************************************************
** Form generated from reading UI file 'usermenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMENU_H
#define UI_USERMENU_H

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

class Ui_usermenu
{
public:
    QTableWidget *usertable;
    QSplitter *splitter;
    QPushButton *print_user;
    QPushButton *search;
    QPushButton *addcart;
    QPushButton *del_cart;
    QPushButton *print_cart;
    QPushButton *pay;

    void setupUi(QWidget *usermenu)
    {
        if (usermenu->objectName().isEmpty())
            usermenu->setObjectName(QStringLiteral("usermenu"));
        usermenu->resize(859, 565);
        usertable = new QTableWidget(usermenu);
        if (usertable->columnCount() < 5)
            usertable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usertable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usertable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usertable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usertable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usertable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        usertable->setObjectName(QStringLiteral("usertable"));
        usertable->setGeometry(QRect(20, 20, 541, 521));
        splitter = new QSplitter(usermenu);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(640, 60, 181, 451));
        splitter->setOrientation(Qt::Vertical);
        print_user = new QPushButton(splitter);
        print_user->setObjectName(QStringLiteral("print_user"));
        splitter->addWidget(print_user);
        search = new QPushButton(splitter);
        search->setObjectName(QStringLiteral("search"));
        splitter->addWidget(search);
        addcart = new QPushButton(splitter);
        addcart->setObjectName(QStringLiteral("addcart"));
        splitter->addWidget(addcart);
        del_cart = new QPushButton(splitter);
        del_cart->setObjectName(QStringLiteral("del_cart"));
        splitter->addWidget(del_cart);
        print_cart = new QPushButton(splitter);
        print_cart->setObjectName(QStringLiteral("print_cart"));
        splitter->addWidget(print_cart);
        pay = new QPushButton(splitter);
        pay->setObjectName(QStringLiteral("pay"));
        splitter->addWidget(pay);

        retranslateUi(usermenu);
        QObject::connect(print_user, SIGNAL(clicked()), usermenu, SLOT(slot_printuser()));
        QObject::connect(search, SIGNAL(clicked()), usermenu, SLOT(slot_search()));
        QObject::connect(addcart, SIGNAL(clicked()), usermenu, SLOT(slot_add_cart()));
        QObject::connect(del_cart, SIGNAL(clicked()), usermenu, SLOT(slot_del_cart()));
        QObject::connect(print_cart, SIGNAL(clicked()), usermenu, SLOT(slot_print_cart()));
        QObject::connect(pay, SIGNAL(clicked()), usermenu, SLOT(slot_pay()));

        QMetaObject::connectSlotsByName(usermenu);
    } // setupUi

    void retranslateUi(QWidget *usermenu)
    {
        usermenu->setWindowTitle(QApplication::translate("usermenu", "\347\224\250\346\210\267\350\217\234\345\215\225", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = usertable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("usermenu", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = usertable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("usermenu", "\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = usertable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("usermenu", "\345\223\201\347\211\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = usertable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("usermenu", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = usertable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("usermenu", "\346\225\260\351\207\217", Q_NULLPTR));
        print_user->setText(QApplication::translate("usermenu", "\346\237\245\347\234\213\345\225\206\345\223\201", Q_NULLPTR));
        search->setText(QApplication::translate("usermenu", "\345\225\206\345\223\201\346\220\234\347\264\242", Q_NULLPTR));
        addcart->setText(QApplication::translate("usermenu", "\346\267\273\345\212\240\345\225\206\345\223\201\350\207\263\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        del_cart->setText(QApplication::translate("usermenu", "\345\210\240\351\231\244\350\264\255\347\211\251\350\275\246\345\225\206\345\223\201", Q_NULLPTR));
        print_cart->setText(QApplication::translate("usermenu", "\346\237\245\347\234\213\350\264\255\347\211\251\350\275\246", Q_NULLPTR));
        pay->setText(QApplication::translate("usermenu", "\347\273\223\350\264\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class usermenu: public Ui_usermenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMENU_H
