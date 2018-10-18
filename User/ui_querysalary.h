/********************************************************************************
** Form generated from reading UI file 'querysalary.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYSALARY_H
#define UI_QUERYSALARY_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuerySalary
{
public:
    QTableView *table;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *start;
    QDateEdit *start_edit;
    QLabel *end;
    QDateEdit *end_edit;
    QPushButton *pushButton;

    void setupUi(QWidget *QuerySalary)
    {
        if (QuerySalary->objectName().isEmpty())
            QuerySalary->setObjectName(QStringLiteral("QuerySalary"));
        QuerySalary->setWindowModality(Qt::NonModal);
        QuerySalary->resize(571, 341);
        QuerySalary->setAutoFillBackground(false);
        QuerySalary->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        table = new QTableView(QuerySalary);
        table->setObjectName(QStringLiteral("table"));
        table->setGeometry(QRect(24, 62, 521, 261));
        table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table->setSortingEnabled(true);
        widget = new QWidget(QuerySalary);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 20, 434, 33));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start = new QLabel(widget);
        start->setObjectName(QStringLiteral("start"));

        horizontalLayout->addWidget(start);

        start_edit = new QDateEdit(widget);
        start_edit->setObjectName(QStringLiteral("start_edit"));
        start_edit->setAlignment(Qt::AlignCenter);
        start_edit->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        start_edit->setDate(QDate(2018, 1, 1));

        horizontalLayout->addWidget(start_edit);

        end = new QLabel(widget);
        end->setObjectName(QStringLiteral("end"));

        horizontalLayout->addWidget(end);

        end_edit = new QDateEdit(widget);
        end_edit->setObjectName(QStringLiteral("end_edit"));
        end_edit->setAlignment(Qt::AlignCenter);
        end_edit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        end_edit->setMaximumDate(QDate(2018, 10, 31));
        end_edit->setCalendarPopup(false);
        end_edit->setDate(QDate(2018, 1, 1));

        horizontalLayout->addWidget(end_edit);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(QuerySalary);
        QObject::connect(QuerySalary, SIGNAL(destroyed()), QuerySalary, SLOT(deleteLater()));

        QMetaObject::connectSlotsByName(QuerySalary);
    } // setupUi

    void retranslateUi(QWidget *QuerySalary)
    {
        QuerySalary->setWindowTitle(QApplication::translate("QuerySalary", "\345\267\245\350\265\204\346\237\245\350\257\242", nullptr));
        start->setText(QApplication::translate("QuerySalary", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", nullptr));
        start_edit->setDisplayFormat(QApplication::translate("QuerySalary", "yyyy/MM", nullptr));
        end->setText(QApplication::translate("QuerySalary", "\347\273\223\346\235\237\346\227\266\351\227\264\357\274\232", nullptr));
        end_edit->setDisplayFormat(QApplication::translate("QuerySalary", "yyyy/MM", nullptr));
        pushButton->setText(QApplication::translate("QuerySalary", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuerySalary: public Ui_QuerySalary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYSALARY_H
