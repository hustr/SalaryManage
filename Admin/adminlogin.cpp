#include "adminlogin.h"
#include "ui_adminlogin.h"

AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

QString AdminLogin::get_id()const
{
    return id;
}

void AdminLogin::on_login_btn_clicked()
{
    id = ui->id_edit->text();
    pass = ui->pass_edit->text();
    if (id.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "警告", "请输入用户名或密码！", QMessageBox::Ok);
        return;
    }
    int status = admin_login(id, pass);
    if (status == 0) {
        QMessageBox::information(this, "欢迎", "欢迎登陆管理员系统！", QMessageBox::Ok);
        QDialog::accept();
    } else {
        switch (status) {
        case NETWORK_ERR:
            QMessageBox::warning(this, "错误", "网络错误！", QMessageBox::Ok);
            break;
        case NO_USER:
            QMessageBox::warning(this, "错误", "无此管理员账户！", QMessageBox::Ok);
            break;
        case NAME_PASS_ERR:
            QMessageBox::warning(this, "错误", "用户名或密码错误！", QMessageBox::Ok);
            break;
        default:
            QMessageBox::warning(this, "错误", "未知错误", QMessageBox::Ok);
        }
    }
}
