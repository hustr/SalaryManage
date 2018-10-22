#include "queryinfo.h"
#include "ui_queryinfo.h"

QueryInfo::QueryInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryInfo)
{
    ui->setupUi(this);
}

QueryInfo::~QueryInfo()
{
    delete ui;
}

void QueryInfo::on_query_btn_clicked()
{
    QString id = ui->id_edit->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "错误", "请输入要查询的ID！", QMessageBox::Ok);
        return;
    }
    User user;
    int status = query_info(id, user);
    if (status == OK) {
        QMessageBox::information(this, "查询结果", "查询员工信息成功！", QMessageBox::Ok);
        ShowInfo *show = new ShowInfo(user);
        show->setAttribute(Qt::WA_DeleteOnClose);
        show->show();
    } else {
        switch (status) {
        case NETWORK_ERR:
            QMessageBox::warning(this, "错误", "网络错误！", QMessageBox::Ok);
            break;
        case NO_USER:
            QMessageBox::warning(this, "错误", "无此员工！", QMessageBox::Ok);
            break;
        default:
            QMessageBox::warning(this, "错误", "未知错误！",QMessageBox::Ok);
            break;
        }
    }
}
