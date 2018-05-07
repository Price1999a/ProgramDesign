/********************************************************************************
** Form generated from reading UI file 'qtproject1_main.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPROJECT1_MAIN_H
#define UI_QTPROJECT1_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtproject1Class
{
public:
    QWidget *centralWidget;
    QSplitter *splitter;
    QPushButton *user_loginin;
    QPushButton *user_create;
    QPushButton *admin_loginin;
    QTextBrowser *textBrowser;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtproject1Class)
    {
        if (qtproject1Class->objectName().isEmpty())
            qtproject1Class->setObjectName(QStringLiteral("qtproject1Class"));
        qtproject1Class->resize(868, 514);
        qtproject1Class->setAcceptDrops(false);
        qtproject1Class->setAutoFillBackground(false);
        qtproject1Class->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(qtproject1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(210, 180, 431, 251));
        splitter->setOrientation(Qt::Vertical);
        user_loginin = new QPushButton(splitter);
        user_loginin->setObjectName(QStringLiteral("user_loginin"));
        splitter->addWidget(user_loginin);
        user_create = new QPushButton(splitter);
        user_create->setObjectName(QStringLiteral("user_create"));
        splitter->addWidget(user_create);
        admin_loginin = new QPushButton(splitter);
        admin_loginin->setObjectName(QStringLiteral("admin_loginin"));
        splitter->addWidget(admin_loginin);
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(210, 30, 431, 141));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 170, 881, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(189, 0, 21, 581));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(640, 0, 21, 581));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(703, 411, 101, 31));
        qtproject1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qtproject1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 868, 23));
        qtproject1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtproject1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qtproject1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qtproject1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qtproject1Class->setStatusBar(statusBar);

        retranslateUi(qtproject1Class);
        QObject::connect(user_loginin, SIGNAL(clicked()), qtproject1Class, SLOT(solt_userlogin()));
        QObject::connect(user_create, SIGNAL(clicked()), qtproject1Class, SLOT(solt_usercreate()));
        QObject::connect(admin_loginin, SIGNAL(clicked()), qtproject1Class, SLOT(solt_adminlogin()));

        QMetaObject::connectSlotsByName(qtproject1Class);
    } // setupUi

    void retranslateUi(QMainWindow *qtproject1Class)
    {
        qtproject1Class->setWindowTitle(QApplication::translate("qtproject1Class", "\347\275\221\345\272\227\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        user_loginin->setText(QApplication::translate("qtproject1Class", "\347\224\250\346\210\267\347\231\273\351\231\206", Q_NULLPTR));
        user_create->setText(QApplication::translate("qtproject1Class", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        admin_loginin->setText(QApplication::translate("qtproject1Class", "\347\256\241\347\220\206\345\221\230\347\231\273\351\231\206", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("qtproject1Class", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:600; color:#aa0000;\">\347\275\221\345\272\227\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#5500ff"
                        ";\">171860522</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#5500ff;\">\346\262\210\345\244\251\347\220\252</span></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("qtproject1Class", "version\357\274\2321.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class qtproject1Class: public Ui_qtproject1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPROJECT1_MAIN_H
