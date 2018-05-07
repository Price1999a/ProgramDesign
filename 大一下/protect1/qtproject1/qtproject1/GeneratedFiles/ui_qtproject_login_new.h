/********************************************************************************
** Form generated from reading UI file 'qtproject_login_new.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPROJECT_LOGIN_NEW_H
#define UI_QTPROJECT_LOGIN_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtproject_login_new
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLabel *label_2;
    QLineEdit *lineEdit2;

    void setupUi(QDialog *qtproject_login_new)
    {
        if (qtproject_login_new->objectName().isEmpty())
            qtproject_login_new->setObjectName(QStringLiteral("qtproject_login_new"));
        qtproject_login_new->resize(430, 205);
        buttonBox = new QDialogButtonBox(qtproject_login_new);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(310, 120, 101, 71));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(qtproject_login_new);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 251, 121));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit1 = new QLineEdit(layoutWidget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));
        lineEdit1->setMaxLength(20);

        gridLayout->addWidget(lineEdit1, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit2 = new QLineEdit(layoutWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setMaxLength(20);
        lineEdit2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit2, 1, 1, 1, 1);


        retranslateUi(qtproject_login_new);
        QObject::connect(buttonBox, SIGNAL(rejected()), qtproject_login_new, SLOT(close()));
        QObject::connect(buttonBox, SIGNAL(accepted()), qtproject_login_new, SLOT(slot_accept()));

        QMetaObject::connectSlotsByName(qtproject_login_new);
    } // setupUi

    void retranslateUi(QDialog *qtproject_login_new)
    {
        qtproject_login_new->setWindowTitle(QApplication::translate("qtproject_login_new", "qtproject_login_new", Q_NULLPTR));
        label->setText(QApplication::translate("qtproject_login_new", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("qtproject_login_new", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class qtproject_login_new: public Ui_qtproject_login_new {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPROJECT_LOGIN_NEW_H
