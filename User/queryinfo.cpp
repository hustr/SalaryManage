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
    ui->postion->setText(QString::fromStdString(user.position));
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(this->width(), this->height());
}

QueryInfo::~QueryInfo()
{
    delete ui;
}
