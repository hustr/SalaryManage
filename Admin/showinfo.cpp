#include "showinfo.h"
#include "ui_showinfo.h"

ShowInfo::ShowInfo(const User &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowInfo)
{
    ui->setupUi(this);
    // 设置人的信息
    ui->name->setText(QString::fromStdString(user.name));
    ui->id->setText(QString::fromStdString(user.id));
    ui->contact->setText(QString::fromStdString(user.contact));
    ui->section->setText(QString::fromStdString(user.section));
    ui->age->setText(QString::number(user.age));
    ui->position->setText(QString::fromStdString(user.position));
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(this->width(), this->height());
}

ShowInfo::~ShowInfo()
{
    delete ui;
}
