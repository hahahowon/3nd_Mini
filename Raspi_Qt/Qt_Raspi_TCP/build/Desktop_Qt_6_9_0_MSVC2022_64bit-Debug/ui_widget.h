/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_Server_Start;
    QPushButton *btn_Server_Stop;
    QTextEdit *te_log;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_Save;
    QTableWidget *tw_product;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(508, 324);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btn_Server_Start = new QPushButton(Widget);
        btn_Server_Start->setObjectName("btn_Server_Start");

        horizontalLayout->addWidget(btn_Server_Start);

        btn_Server_Stop = new QPushButton(Widget);
        btn_Server_Stop->setObjectName("btn_Server_Stop");

        horizontalLayout->addWidget(btn_Server_Stop);


        verticalLayout->addLayout(horizontalLayout);

        te_log = new QTextEdit(Widget);
        te_log->setObjectName("te_log");

        verticalLayout->addWidget(te_log);


        horizontalLayout_2->addLayout(verticalLayout);

        line = new QFrame(Widget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        btn_Save = new QPushButton(Widget);
        btn_Save->setObjectName("btn_Save");

        verticalLayout_2->addWidget(btn_Save);

        tw_product = new QTableWidget(Widget);
        tw_product->setObjectName("tw_product");

        verticalLayout_2->addWidget(tw_product);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_Server_Start->setText(QCoreApplication::translate("Widget", "\354\204\234\353\262\204\354\213\234\354\236\221", nullptr));
        btn_Server_Stop->setText(QCoreApplication::translate("Widget", "\354\204\234\353\262\204\354\242\205\353\243\214", nullptr));
        btn_Save->setText(QCoreApplication::translate("Widget", "\354\240\200\354\236\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
