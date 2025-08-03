#include "login.h"
#include "ui_login.h"
#include "logincontroller.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_cancelButton_clicked() {
    QApplication::quit();
}

void Login::setController(LoginController *controller) {
    m_controller = controller;

    // Controller의 시그널을 View의 슬롯에 연결
    connect(m_controller, &LoginController::loginSuccess,
            this, &Login::handleLoginSuccess);
    connect(m_controller, &LoginController::loginFailed,
            this, &Login::handleLoginFailed);
}

void Login::on_logInButton_clicked() {
    if (m_controller) {
        qDebug() << "clicked";
        QString userID = ui->idEdit->text();
        QString userPW = ui->pwEdit->text();

        // Controller에게 로그인 처리 요청
        m_controller->processLogin(userID, userPW);
    }
}

