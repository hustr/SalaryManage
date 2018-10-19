#include "querysalary.h"
#include "ui_querysalary.h"

QuerySalary::QuerySalary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuerySalary)
{
    ui->setupUi(this);
    setFixedSize(this->width(), this->height());
    // 设置最大时间，以本月为准
    QDate month;
    QDate now = QDate::currentDate();
    month.setDate(now.year(), now.month(), now.day());
    ui->end_edit->setMaximumDate(now);
    // 设置两个日期都是现在这个月
    ui->end_edit->setDate(now);
    ui->start_edit->setDate(now);
    // 当结束时间变换时需要保证开始时间不能大于它
    connect(ui->end_edit, &QDateEdit::dateChanged, [&](){
        ui->start_edit->setMaximumDate(ui->end_edit->date());
    });
    // 设置表头
    model = new QStandardItemModel();
    model->setHorizontalHeaderItem(0, new QStandardItem("年月"));
    model->setHorizontalHeaderItem(1, new QStandardItem("基本工资"));
    model->setHorizontalHeaderItem(2, new QStandardItem("奖金"));
    model->setHorizontalHeaderItem(3, new QStandardItem("罚款"));
    model->setHorizontalHeaderItem(4, new QStandardItem("结算工资"));
    model->sort(0, Qt::DescendingOrder); // 按照时间降序排列
    ui->table->setModel(model);
    ui->table->verticalHeader()->hide();
}

QuerySalary::~QuerySalary()
{
    delete ui;
    // 清理内存
    delete model;
}

void QuerySalary::set_id(const QString &id)
{
    this->id = id;
}

void QuerySalary::update_table(QStandardItemModel *model, const std::vector<Salary> &salaries) {
    // 先清理所有的已有数据
    model->removeRows(0, model->rowCount());
    // 写入获取的数据
    int idx = 0;
    for (const auto &sala : salaries) {
        QString date("%1/%2");
        date = date.arg(sala.year, 4, 10, QChar('0')).arg(sala.month, 2, 10, QChar('0'));
        model->setItem(idx, 0, new QStandardItem(date));
        model->setItem(idx, 1, new QStandardItem(QString::number(sala.base)));
        model->setItem(idx, 2, new QStandardItem(QString::number(sala.bonus)));
        model->setItem(idx, 3, new QStandardItem(QString::number(sala.fine)));
        model->setItem(idx, 4, new QStandardItem(QString::number(sala.salary)));
        idx++;
    }
}

void QuerySalary::on_pushButton_clicked()
{
    std::vector<Salary> result;
    int code = query_salary(ui->start_edit->date(), ui->end_edit->date(), id, result);
    qDebug() << "statue code in salary " << code;
    switch (code) {
        case OK:
            QMessageBox::information(this, "查询结果", "查询成功", QMessageBox::Ok);
            update_table(model, result);
            break;
        case NETWORK_ERR:
            QMessageBox::warning(this, "错误", "网络错误", QMessageBox::Ok);
            break;
        default:
            QMessageBox::warning(this, "错误", "未知错误", QMessageBox::Ok);
    }
}
