#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
class LoginController;

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    void setController(LoginController *controller);

private slots:
    void on_cancelButton_clicked();
    void on_logInButton_clicked();

    void handleLoginSuccess(const QString &username, bool isAdmin);
    void handleLoginFailed(const QString &errorMessage);

private:
    Ui::Login *ui;
    LoginController *m_controller;
};
#endif // LOGIN_H
