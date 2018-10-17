#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <iostream>
#include <cstring>
#include <QDebug>

#include "operation.h"

using namespace rapidjson;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_login_btn_clicked();

private:
    Ui::LoginDialog *ui;
    QString name;
    QString pass;
};

#endif // LOGINDIALOG_H
