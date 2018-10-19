#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "operation.h"
#include "logindialog.h"
#include "querysalary.h"
#include "changepass.h"
#include "queryinfo.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void set_login_account(const LoginDialog *login);

private slots:


    void on_query_sala_btn_clicked();

    void on_quary_info_btn_clicked();

    void on_change_pass_btn_clicked();

private:
    Ui::MainWidget *ui;
    QString id;
    QString pass;
};

#endif // MAINWIDGET_H
