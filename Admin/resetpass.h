#ifndef RESETPASS_H
#define RESETPASS_H

#include <QWidget>
#include "header.h"

namespace Ui {
class ResetPass;
}

class ResetPass : public QWidget
{
    Q_OBJECT

public:
    explicit ResetPass(QWidget *parent = nullptr);
    ~ResetPass();

private slots:
    void on_reset_btn_clicked();

    void on_pass0_edit_textChanged(const QString &arg1);

    void on_pass1_edit_textChanged(const QString &arg1);

private:
    Ui::ResetPass *ui;
};

#endif // RESETPASS_H
