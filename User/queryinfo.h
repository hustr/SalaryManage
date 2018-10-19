#ifndef QUERYINFO_H
#define QUERYINFO_H

#include <QWidget>
#include "user.h"


namespace Ui {
class QueryInfo;
}

class QueryInfo : public QWidget
{
    Q_OBJECT

public:
    explicit QueryInfo(const User &user, QWidget *parent = nullptr);
    ~QueryInfo();

private:
    Ui::QueryInfo *ui;
};

#endif // QUERYINFO_H
