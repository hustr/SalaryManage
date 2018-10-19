#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QWidget>
#include <QMessageBox>
#include "operation.h"

namespace Ui {
class ChangePass;
}

class ChangePass : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePass(QString &pass, QWidget *parent = nullptr);
    ~ChangePass();
    void set_id(const QString &id);


private slots:
    void on_new0_edit_textChanged(const QString &);

    void on_new1_edit_textChanged(const QString &);

    void on_change_btn_clicked();

private:
    Ui::ChangePass *ui;
    QString &new_pass;
    QString id;
};

#endif // CHANGEPASS_H
