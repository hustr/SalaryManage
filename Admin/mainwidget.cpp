#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::set_login_account(const AdminLogin *login)
{
    this->id = login->get_id();
}

void MainWidget::on_query_info_btn_clicked()
{
    QueryInfo *query = new QueryInfo();
    query->setAttribute(Qt::WA_DeleteOnClose);
    query->setWindowModality(Qt::ApplicationModal);
    query->show();
}

void MainWidget::on_query_sala_btn_clicked()
{
    QuerySala *sala = new QuerySala();
    sala->setAttribute(Qt::WA_DeleteOnClose);
    sala->setWindowModality(Qt::ApplicationModal);
    sala->show();
}

void MainWidget::on_reset_pass_btn_clicked()
{
    ResetPass *reset = new ResetPass();
    reset->setAttribute(Qt::WA_DeleteOnClose);
    reset->setWindowModality(Qt::ApplicationModal);
    reset->show();
}

void MainWidget::on_add_user_btn_clicked()
{

}

void MainWidget::on_del_user_btn_clicked()
{

}
