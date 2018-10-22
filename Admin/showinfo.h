#ifndef SHOWINFO_H
#define SHOWINFO_H

#include <QWidget>
#include "header.h"

namespace Ui {
class ShowInfo;
}

class ShowInfo : public QWidget
{
    Q_OBJECT

public:
    explicit ShowInfo(const User &user, QWidget *parent = nullptr);
    ~ShowInfo();

private:
    Ui::ShowInfo *ui;
};

#endif // SHOWINFO_H
