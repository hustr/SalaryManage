#ifndef QUERYINFO_H
#define QUERYINFO_H

#include <QWidget>
#include "header.h"
#include "showinfo.h"

namespace Ui {
class QueryInfo;
}

class QueryInfo : public QWidget
{
    Q_OBJECT

public:
    explicit QueryInfo(QWidget *parent = nullptr);
    ~QueryInfo();

private slots:
    void on_query_btn_clicked();

private:
    Ui::QueryInfo *ui;
};

#endif // QUERYINFO_H
