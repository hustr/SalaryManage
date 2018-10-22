#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "header.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

    QString get_id()const;

private slots:
    void on_login_btn_clicked();

private:
    Ui::AdminLogin *ui;
    QString id;
    QString pass;
};

#endif // ADMINLOGIN_H
