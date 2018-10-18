/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *query_sala_btn;
    QPushButton *quary_info_btn;
    QPushButton *change_pass_btn;
    QPushButton *logout_btn;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(449, 200);
        query_sala_btn = new QPushButton(MainWidget);
        query_sala_btn->setObjectName(QStringLiteral("query_sala_btn"));
        query_sala_btn->setGeometry(QRect(61, 51, 80, 30));
        quary_info_btn = new QPushButton(MainWidget);
        quary_info_btn->setObjectName(QStringLiteral("quary_info_btn"));
        quary_info_btn->setGeometry(QRect(183, 51, 80, 30));
        change_pass_btn = new QPushButton(MainWidget);
        change_pass_btn->setObjectName(QStringLiteral("change_pass_btn"));
        change_pass_btn->setGeometry(QRect(305, 51, 80, 30));
        logout_btn = new QPushButton(MainWidget);
        logout_btn->setObjectName(QStringLiteral("logout_btn"));
        logout_btn->setGeometry(QRect(311, 137, 80, 30));

        retranslateUi(MainWidget);
        QObject::connect(logout_btn, SIGNAL(clicked()), MainWidget, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "\346\223\215\344\275\234\347\225\214\351\235\242", nullptr));
        query_sala_btn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242\345\267\245\350\265\204", nullptr));
        quary_info_btn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242\344\277\241\346\201\257", nullptr));
        change_pass_btn->setText(QApplication::translate("MainWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        logout_btn->setText(QApplication::translate("MainWidget", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
