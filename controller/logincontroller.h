#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QObject>
#include "login.h"

class LoginController : public QObject {
    Q_OBJECT

public:
    explicit LoginController(QObject *parent = nullptr);
    ~LoginController();
    void setView(Login *view);

public slots:
    void processLogin(const QString &username, const QString &password);

private:
    Login *m_view;

signals:
    // 로그인 결과를 알리는 시그널
    void loginSuccess(const QString &username, bool isAdmin);
    void loginFailed(const QString &errorMessage);
};

#endif // LOGINCONTROLLER_H
