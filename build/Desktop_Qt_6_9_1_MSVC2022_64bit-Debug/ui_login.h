/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *logInButton;
    QGroupBox *logInGroupBox;
    QLabel *idLabel;
    QLabel *pwLabel;
    QLineEdit *idEdit;
    QLineEdit *pwEdit;
    QPushButton *signUpButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(380, 140);
        logInButton = new QPushButton(Login);
        logInButton->setObjectName("logInButton");
        logInButton->setGeometry(QRect(284, 7, 81, 81));
        logInGroupBox = new QGroupBox(Login);
        logInGroupBox->setObjectName("logInGroupBox");
        logInGroupBox->setGeometry(QRect(10, 7, 261, 81));
        idLabel = new QLabel(logInGroupBox);
        idLabel->setObjectName("idLabel");
        idLabel->setGeometry(QRect(18, 13, 62, 20));
        pwLabel = new QLabel(logInGroupBox);
        pwLabel->setObjectName("pwLabel");
        pwLabel->setGeometry(QRect(10, 47, 62, 20));
        idEdit = new QLineEdit(logInGroupBox);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(50, 10, 201, 28));
        pwEdit = new QLineEdit(logInGroupBox);
        pwEdit->setObjectName("pwEdit");
        pwEdit->setGeometry(QRect(50, 44, 201, 28));
        signUpButton = new QPushButton(Login);
        signUpButton->setObjectName("signUpButton");
        signUpButton->setGeometry(QRect(181, 99, 88, 29));
        cancelButton = new QPushButton(Login);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(280, 100, 88, 29));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        logInButton->setText(QCoreApplication::translate("Login", "\353\241\234\352\267\270\354\235\270", nullptr));
        logInGroupBox->setTitle(QString());
        idLabel->setText(QCoreApplication::translate("Login", "ID :", nullptr));
        pwLabel->setText(QCoreApplication::translate("Login", "PW :", nullptr));
        signUpButton->setText(QCoreApplication::translate("Login", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        cancelButton->setText(QCoreApplication::translate("Login", "\354\267\250 \354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
