#ifndef QUERYSALA_H
#define QUERYSALA_H

#include <QWidget>
#include "header.h"
#include <QStandardItemModel>
#include <vector>

namespace Ui {
class QuerySala;
}

class QuerySala : public QWidget
{
    Q_OBJECT

public:
    explicit QuerySala(QWidget *parent = nullptr);
    ~QuerySala();  
private slots:
    void on_query_btn_clicked();

private:
    Ui::QuerySala *ui;
    QStandardItemModel *model;

    void update_table(const std::vector<Salary> &salaries);
};

#endif // QUERYSALA_H
