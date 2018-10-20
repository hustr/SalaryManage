/********************************************************************************
** Form generated from reading UI file 'changepass.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPASS_H
#define UI_CHANGEPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePass
{
public:
    QLabel *pass_diff;
    QPushButton *change_btn;
    QSplitter *splitter;
    QLabel *old_pass;
    QLineEdit *old_edit;
    QSplitter *splitter_2;
    QLabel *new0_pass;
    QLineEdit *new0_edit;
    QSplitter *splitter_3;
    QLabel *new1_pass;
    QLineEdit *new1_edit;

    void setupUi(QWidget *ChangePass)
    {
        if (ChangePass->objectName().isEmpty())
            ChangePass->setObjectName(QStringLiteral("ChangePass"));
        ChangePass->resize(393, 266);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChangePass->sizePolicy().hasHeightForWidth());
        ChangePass->setSizePolicy(sizePolicy);
        pass_diff = new QLabel(ChangePass);
        pass_diff->setObjectName(QStringLiteral("pass_diff"));
        pass_diff->setGeometry(QRect(140, 170, 105, 22));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        pass_diff->setFont(font);
        change_btn = new QPushButton(ChangePass);
        change_btn->setObjectName(QStringLiteral("change_btn"));
        change_btn->setGeometry(QRect(270, 210, 80, 30));
        splitter = new QSplitter(ChangePass);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(70, 50, 202, 30));
        splitter->setOrientation(Qt::Horizontal);
        old_pass = new QLabel(splitter);
        old_pass->setObjectName(QStringLiteral("old_pass"));
        splitter->addWidget(old_pass);
        old_edit = new QLineEdit(splitter);
        old_edit->setObjectName(QStringLiteral("old_edit"));
        old_edit->setEchoMode(QLineEdit::Password);
        splitter->addWidget(old_edit);
        splitter_2 = new QSplitter(ChangePass);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(70, 88, 202, 30));
        splitter_2->setOrientation(Qt::Horizontal);
        new0_pass = new QLabel(splitter_2);
        new0_pass->setObjectName(QStringLiteral("new0_pass"));
        splitter_2->addWidget(new0_pass);
        new0_edit = new QLineEdit(splitter_2);
        new0_edit->setObjectName(QStringLiteral("new0_edit"));
        new0_edit->setEchoMode(QLineEdit::Password);
        splitter_2->addWidget(new0_edit);
        splitter_3 = new QSplitter(ChangePass);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(70, 126, 202, 30));
        splitter_3->setOrientation(Qt::Horizontal);
        new1_pass = new QLabel(splitter_3);
        new1_pass->setObjectName(QStringLiteral("new1_pass"));
        splitter_3->addWidget(new1_pass);
        new1_edit = new QLineEdit(splitter_3);
        new1_edit->setObjectName(QStringLiteral("new1_edit"));
        new1_edit->setEchoMode(QLineEdit::Password);
        splitter_3->addWidget(new1_edit);

        retranslateUi(ChangePass);

        QMetaObject::connectSlotsByName(ChangePass);
    } // setupUi

    void retranslateUi(QWidget *ChangePass)
    {
        ChangePass->setWindowTitle(QApplication::translate("ChangePass", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        pass_diff->setText(QApplication::translate("ChangePass", "\344\270\244\346\254\241\345\257\206\347\240\201\344\270\215\344\270\200\350\207\264", nullptr));
        change_btn->setText(QApplication::translate("ChangePass", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        old_pass->setText(QApplication::translate("ChangePass", "\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        old_edit->setPlaceholderText(QApplication::translate("ChangePass", "\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201", nullptr));
        new0_pass->setText(QApplication::translate("ChangePass", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        new0_edit->setPlaceholderText(QApplication::translate("ChangePass", "\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", nullptr));
        new1_pass->setText(QApplication::translate("ChangePass", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        new1_edit->setPlaceholderText(QApplication::translate("ChangePass", "\345\206\215\350\276\223\345\205\245\344\270\200\346\254\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePass: public Ui_ChangePass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPASS_H
