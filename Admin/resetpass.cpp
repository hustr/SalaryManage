#include "resetpass.h"
#include "ui_resetpass.h"

ResetPass::ResetPass(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResetPass)
{
    ui->setupUi(this);
    ui->reset_btn->setEnabled(false);
    ui->pass_diff->setStyleSheet("color:red");
    ui->pass_diff->hide();
}

ResetPass::~ResetPass()
{
    delete ui;
}

void ResetPass::on_reset_btn_clicked()
{
    int select = QMessageBox::warning(this, "警告", "确认重置密码？", QMessageBox::Ok, QMessageBox::Cancel);
    if (select == QMessageBox::Ok) {
        // 逻辑可以保证点击change时的两个新密码框数据相同，并且三个框都不为空
        QString pass = ui->pass0_edit->text();
        QString id = ui->id_edit->text();
        int status = reset_pass(id, pass);
        switch (status) {
        case OK:
            QMessageBox::information(this, "成功", "密码重置成功！", QMessageBox::Ok);
            break;
        case NETWORK_ERR:
            QMessageBox::warning(this, "错误", "网络错误", QMessageBox::Ok);
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

void ResetPass::on_pass0_edit_textChanged(const QString &)
{
    QString id = ui->id_edit->text();
    QString pass0 = ui->pass0_edit->text();
    QString pass1 = ui->pass1_edit->text();
    if (!id.isEmpty() && !pass0.isEmpty() && pass0 == pass1) {
        ui->reset_btn->setEnabled(true);
    } else {
        ui->reset_btn->setEnabled(false);
    }
    if (pass0 != pass1) {
        ui->pass_diff->show();
    } else {
        ui->pass_diff->hide();
    }
}

void ResetPass::on_pass1_edit_textChanged(const QString &)
{
    QString id = ui->id_edit->text();
    QString pass0 = ui->pass0_edit->text();
    QString pass1 = ui->pass1_edit->text();
    if (!id.isEmpty() && !pass0.isEmpty() && pass0 == pass1) {
        ui->reset_btn->setEnabled(true);
    } else {
        ui->reset_btn->setEnabled(false);
    }
    if (pass0 != pass1) {
        ui->pass_diff->show();
    } else {
        ui->pass_diff->hide();
    }
}
