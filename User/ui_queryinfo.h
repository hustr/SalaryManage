/********************************************************************************
** Form generated from reading UI file 'queryinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYINFO_H
#define UI_QUERYINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryInfo
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_0;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *lable_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *name;
    QLabel *id;
    QLabel *contact;
    QLabel *section;
    QLabel *postion;
    QLabel *age;

    void setupUi(QWidget *QueryInfo)
    {
        if (QueryInfo->objectName().isEmpty())
            QueryInfo->setObjectName(QStringLiteral("QueryInfo"));
        QueryInfo->resize(307, 227);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QueryInfo->sizePolicy().hasHeightForWidth());
        QueryInfo->setSizePolicy(sizePolicy);
        widget = new QWidget(QueryInfo);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 31, 77, 164));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_0 = new QLabel(widget);
        label_0->setObjectName(QStringLiteral("label_0"));
        label_0->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_0);

        label_1 = new QLabel(widget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_5);

        lable_4 = new QLabel(widget);
        lable_4->setObjectName(QStringLiteral("lable_4"));
        lable_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lable_4);

        widget1 = new QWidget(QueryInfo);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(130, 31, 131, 164));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name = new QLabel(widget1);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout_2->addWidget(name);

        id = new QLabel(widget1);
        id->setObjectName(QStringLiteral("id"));

        verticalLayout_2->addWidget(id);

        contact = new QLabel(widget1);
        contact->setObjectName(QStringLiteral("contact"));

        verticalLayout_2->addWidget(contact);

        section = new QLabel(widget1);
        section->setObjectName(QStringLiteral("section"));

        verticalLayout_2->addWidget(section);

        postion = new QLabel(widget1);
        postion->setObjectName(QStringLiteral("postion"));

        verticalLayout_2->addWidget(postion);

        age = new QLabel(widget1);
        age->setObjectName(QStringLiteral("age"));

        verticalLayout_2->addWidget(age);


        retranslateUi(QueryInfo);

        QMetaObject::connectSlotsByName(QueryInfo);
    } // setupUi

    void retranslateUi(QWidget *QueryInfo)
    {
        QueryInfo->setWindowTitle(QApplication::translate("QueryInfo", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label_0->setText(QApplication::translate("QueryInfo", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_1->setText(QApplication::translate("QueryInfo", "\345\267\245\345\217\267\357\274\232", nullptr));
        label_2->setText(QApplication::translate("QueryInfo", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        label_3->setText(QApplication::translate("QueryInfo", "\351\203\250\351\227\250\357\274\232", nullptr));
        label_5->setText(QApplication::translate("QueryInfo", "\350\201\214\344\275\215\357\274\232", nullptr));
        lable_4->setText(QApplication::translate("QueryInfo", "\345\271\264\351\276\204\357\274\232", nullptr));
        name->setText(QApplication::translate("QueryInfo", "1", nullptr));
        id->setText(QApplication::translate("QueryInfo", "2", nullptr));
        contact->setText(QApplication::translate("QueryInfo", "3", nullptr));
        section->setText(QApplication::translate("QueryInfo", "4", nullptr));
        postion->setText(QApplication::translate("QueryInfo", "6", nullptr));
        age->setText(QApplication::translate("QueryInfo", "5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryInfo: public Ui_QueryInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYINFO_H
