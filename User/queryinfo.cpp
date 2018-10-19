#include "queryinfo.h"
#include "ui_queryinfo.h"

QueryInfo::QueryInfo(const User &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryInfo)
{
    ui->setupUi(this);
    // 设置人的信息
    ui->name->setText(QString::fromStdString(user.name));
    ui->id->setText(QString::fromStdString(user.id));
    ui->contact->setText(QString::fromStdString(user.contact));
    ui->section->setText(QString::fromStdString(user.section));
    ui->age->setText(QString::number(user.age));
    setAttribute(Qt::WA_DeleteOnClose);
}

QueryInfo::~QueryInfo()
{
    delete ui;
}
