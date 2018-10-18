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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *name;
    QLabel *pass;
    QLineEdit *name_edit;
    QLineEdit *pass_edit;
    QPushButton *login_btn;
    QPushButton *cancel_btn;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(420, 220);
        name = new QLabel(LoginDialog);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(73, 42, 60, 22));
        pass = new QLabel(LoginDialog);
        pass->setObjectName(QStringLiteral("pass"));
        pass->setGeometry(QRect(73, 80, 61, 22));
        name_edit = new QLineEdit(LoginDialog);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setGeometry(QRect(139, 42, 171, 30));
        pass_edit = new QLineEdit(LoginDialog);
        pass_edit->setObjectName(QStringLiteral("pass_edit"));
        pass_edit->setGeometry(QRect(140, 80, 171, 30));
        pass_edit->setEchoMode(QLineEdit::Password);
        login_btn = new QPushButton(LoginDialog);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(170, 150, 80, 30));
        cancel_btn = new QPushButton(LoginDialog);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setGeometry(QRect(270, 150, 80, 30));

        retranslateUi(LoginDialog);
        QObject::connect(cancel_btn, SIGNAL(clicked()), LoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "\347\231\273\351\231\206\347\224\250\346\210\267", nullptr));
        name->setText(QApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pass->setText(QApplication::translate("LoginDialog", "    \345\257\206\347\240\201\357\274\232", nullptr));
        name_edit->setText(QApplication::translate("LoginDialog", "yaning", nullptr));
        name_edit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        pass_edit->setText(QApplication::translate("LoginDialog", "abcd", nullptr));
        pass_edit->setPlaceholderText(QApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        login_btn->setText(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", nullptr));
        cancel_btn->setText(QApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
