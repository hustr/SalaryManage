#ifndef QUERYSALARY_H
#define QUERYSALARY_H

#include <QWidget>
#include <QMessageBox>
#include <QDate>
#include <QDateEdit>
#include "operation.h"
#include <QTableView>
#include <QStandardItemModel>
#include <vector>
#include "salary.h"

namespace Ui {
class QuerySalary;
}

class QuerySalary : public QWidget
{
    Q_OBJECT

public:
    explicit QuerySalary(QWidget *parent = nullptr);
    ~QuerySalary();
    void set_id(const QString &id);

private slots:
    void on_pushButton_clicked();

private:
    Ui::QuerySalary *ui;
    QStandardItemModel *model;
    QString id;
};

#endif // QUERYSALARY_H
