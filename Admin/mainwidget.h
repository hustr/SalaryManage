#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "adminlogin.h"
#include "header.h"
#include "queryinfo.h"
#include "querysala.h"
#include "resetpass.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void set_login_account(const AdminLogin *login);

private slots:
    void on_query_info_btn_clicked();

    void on_query_sala_btn_clicked();

    void on_reset_pass_btn_clicked();

    void on_add_user_btn_clicked();

    void on_del_user_btn_clicked();

private:
    Ui::MainWidget *ui;
    QString id;
};

#endif // MAINWIDGET_H
