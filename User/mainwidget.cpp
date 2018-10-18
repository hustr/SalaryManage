#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::set_login_account(const LoginDialog *login)
{
    // 登陆进来的人的用户名和密码
    this->name = login->get_name();
    this->pass = login->get_pass();
    setWindowTitle(name);
}


void MainWidget::on_query_sala_btn_clicked()
{
    QuerySalary *query = new QuerySalary();
    query->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭窗口后自动释放内存
    query->set_id(this->name); // 设置查询人员的id
    query->show(); // 显示查询界面
}

void MainWidget::on_quary_info_btn_clicked()
{

}

void MainWidget::on_change_pass_btn_clicked()
{

}
