#include "changepass.h"
#include "ui_changepass.h"

ChangePass::ChangePass(QString &pass, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePass),
    new_pass(pass)
{
    ui->setupUi(this);
    ui->pass_diff->hide();
    ui->change_btn->setEnabled(false);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->pass_diff->setStyleSheet("color:red");
}

ChangePass::~ChangePass()
{
    delete ui;
}

void ChangePass::set_id(const QString &id)
{
    this->id = id;
}

void ChangePass::on_new0_edit_textChanged(const QString &str)
{
    if (str != ui->new1_edit->text()) {
        ui->pass_diff->show();
        ui->change_btn->setEnabled(false);
    } else if (!str.isEmpty()){
        ui->pass_diff->hide();
        ui->change_btn->setEnabled(true);
    } else {
        ui->change_btn->setEnabled(false);
    }
}

void ChangePass::on_new1_edit_textChanged(const QString &str)
{
    if (str != ui->new0_edit->text()) {
        ui->pass_diff->show();
        ui->change_btn->setEnabled(false);
    } else if (!str.isEmpty()){
        ui->pass_diff->hide();
        ui->change_btn->setEnabled(true);
    } else {
        ui->change_btn->setEnabled(false);
    }
}

void ChangePass::on_change_btn_clicked()
{
    int select = QMessageBox::warning(this, "警告", "确认修改密码？", QMessageBox::Ok, QMessageBox::Cancel);
    if (select == QMessageBox::Ok) {
        // 逻辑可以保证点击change时的两个新密码框数据相同
        QString my_new_pass = ui->new0_edit->text();
        QString old_pass = ui->old_edit->text();
        int status = change_pass(id, old_pass, my_new_pass);
        switch (status) {
        case OK:
            QMessageBox::information(this, "", "密码修改成功", QMessageBox::Ok);
            new_pass = my_new_pass;
            break;
        case NETWORK_ERR:
            QMessageBox::warning(this, "错误", "网络错误", QMessageBox::Ok);
            break;
        case NAME_PASS_ERR:
            QMessageBox::warning(this, "错误", "旧密码错误", QMessageBox::Ok);
            break;
        case NO_USER:
            QMessageBox::warning(this, "错误", "无此用户", QMessageBox::Ok);
            break;
        default:
            QMessageBox::warning(this, "错误", "未知错误", QMessageBox::Ok);
            break;
        }
    }
}
