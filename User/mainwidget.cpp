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
    this->id = login->get_id();
    this->pass = login->get_pass();
}


void MainWidget::on_query_sala_btn_clicked()
{
    QuerySalary *query = new QuerySalary();
    query->setAttribute(Qt::WA_DeleteOnClose); // 设置关闭窗口后自动释放内存
    query->set_id(this->id); // 设置查询人员的id
    query->show(); // 显示查询界面
}

void MainWidget::on_quary_info_btn_clicked()
{
    // 直接在这里获取人的信息，通过参数传送到界面中
    User user;
    int status = query_info(id, user);
    if (status == OK) {
        // 输出个信息先
        QMessageBox::information(this, "查询结果", "查询个人信息成功。", QMessageBox::Ok);
        QueryInfo *info = new QueryInfo(user);
        info->show();
    } else {
        switch (status) {
        case NO_USER:
            QMessageBox::warning(this, "警告","没有查找到您的信息！", QMessageBox::Ok);
        default:
            break;
        }
    }

}

void MainWidget::on_change_pass_btn_clicked()
{
    ChangePass *change = new ChangePass(pass);
    change->setWindowModality(Qt::ApplicationModal);
    change->set_id(id);
    change->show();
}
