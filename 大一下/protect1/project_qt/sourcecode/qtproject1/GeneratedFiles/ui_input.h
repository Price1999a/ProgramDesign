/********************************************************************************
** Form generated from reading UI file 'inputHp7372.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef INPUTHP7372_H
#define INPUTHP7372_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_input
{
public:
    QLineEdit *lineEdit;
    QSplitter *splitter;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QWidget *input)
    {
        if (input->objectName().isEmpty())
            input->setObjectName(QStringLiteral("input"));
        input->resize(399, 142);
        lineEdit = new QLineEdit(input);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 50, 241, 31));
        lineEdit->setMaxLength(50);
        splitter = new QSplitter(input);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(300, 20, 91, 91));
        splitter->setOrientation(Qt::Vertical);
        yes = new QPushButton(splitter);
        yes->setObjectName(QStringLiteral("yes"));
        splitter->addWidget(yes);
        no = new QPushButton(splitter);
        no->setObjectName(QStringLiteral("no"));
        splitter->addWidget(no);

        retranslateUi(input);
        QObject::connect(no, SIGNAL(clicked()), input, SLOT(close()));
        QObject::connect(yes, SIGNAL(clicked()), input, SLOT(slot_lineinput()));

        QMetaObject::connectSlotsByName(input);
    } // setupUi

    void retranslateUi(QWidget *input)
    {
        input->setWindowTitle(QApplication::translate("input", "\344\277\241\346\201\257\350\276\223\345\205\245\347\252\227\345\217\243", Q_NULLPTR));
        yes->setText(QApplication::translate("input", "\347\241\256\345\256\232", Q_NULLPTR));
        no->setText(QApplication::translate("input", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class input: public Ui_input {};
} // namespace Ui

QT_END_NAMESPACE

#endif // INPUTHP7372_H
