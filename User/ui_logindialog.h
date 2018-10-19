/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *login_btn;
    QPushButton *cancel_btn;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *id;
    QLineEdit *id_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *pass;
    QLineEdit *pass_edit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(420, 220);
        login_btn = new QPushButton(LoginDialog);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(170, 150, 80, 30));
        cancel_btn = new QPushButton(LoginDialog);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setGeometry(QRect(270, 150, 80, 30));
        widget = new QWidget(LoginDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(73, 42, 197, 72));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        id = new QLabel(widget);
        id->setObjectName(QStringLiteral("id"));

        horizontalLayout->addWidget(id);

        id_edit = new QLineEdit(widget);
        id_edit->setObjectName(QStringLiteral("id_edit"));

        horizontalLayout->addWidget(id_edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pass = new QLabel(widget);
        pass->setObjectName(QStringLiteral("pass"));

        horizontalLayout_2->addWidget(pass);

        pass_edit = new QLineEdit(widget);
        pass_edit->setObjectName(QStringLiteral("pass_edit"));
        pass_edit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(pass_edit);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(LoginDialog);
        QObject::connect(cancel_btn, SIGNAL(clicked()), LoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\351\231\206\347\224\250\346\210\267", nullptr));
        login_btn->setText(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", nullptr));
        cancel_btn->setText(QApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        id->setText(QApplication::translate("LoginDialog", "\350\264\246\346\210\267\357\274\232", nullptr));
        id_edit->setText(QApplication::translate("LoginDialog", "yaning", nullptr));
        id_edit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pass->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        pass_edit->setText(QApplication::translate("LoginDialog", "abcd", nullptr));
        pass_edit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
