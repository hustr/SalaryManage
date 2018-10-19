#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::get_id()const
{
    return id;
}

QString LoginDialog::get_pass()const
{
    return pass;
}

void LoginDialog::on_login_btn_clicked()
{
    id = ui->id_edit->text();
    pass = ui->pass_edit->text();

    if (id.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入用户名或密码", QMessageBox::Ok);
        return;
    }

    switch (login(id, pass)) {
    case OK:
        QMessageBox::information(this, "欢迎", "欢迎登陆工资系统。");
        this->accept();
        break;
    case NETWORK_ERR:
        QMessageBox::critical(this, "错误", "无法连接到服务器！", QMessageBox::Ok);
        break;
    case NAME_PASS_ERR:
        QMessageBox::warning(this, "警告", "用户名或密码错误。");
        break;
     default:
        QMessageBox::warning(this, "警告", "未知错误");
    }
}
