#include "mainwidget.h"
#include <QApplication>
#include <QMessageBox>
#include "logindialog.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    LoginDialog login;
    if (login.exec()== QDialog::Accepted) {
        w.set_login_account(&login);
        w.show();
        return a.exec();
    }

    return 0;
}
