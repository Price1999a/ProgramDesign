/********************************************************************************
** Form generated from reading UI file 'input_new.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUT_NEW_H
#define UI_INPUT_NEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_input_new
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *inputliine;

    void setupUi(QDialog *input_new)
    {
        if (input_new->objectName().isEmpty())
            input_new->setObjectName(QStringLiteral("input_new"));
        input_new->resize(482, 142);
        buttonBox = new QDialogButtonBox(input_new);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(290, 90, 151, 41));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        inputliine = new QLineEdit(input_new);
        inputliine->setObjectName(QStringLiteral("inputliine"));
        inputliine->setGeometry(QRect(40, 40, 411, 31));
        inputliine->setMaxLength(50);

        retranslateUi(input_new);
        QObject::connect(buttonBox, SIGNAL(rejected()), input_new, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), input_new, SLOT(slot_lineinput()));

        QMetaObject::connectSlotsByName(input_new);
    } // setupUi

    void retranslateUi(QDialog *input_new)
    {
        input_new->setWindowTitle(QApplication::translate("input_new", "input_new", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class input_new: public Ui_input_new {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUT_NEW_H
