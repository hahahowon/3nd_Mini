#include <QMessageBox>
#include "logincontroller.h"
#include "admincontroller.h"
#include "normalcontroller.h"
#include "admin.h"
#include "normal.h"
#include "membermanager.h"

LoginController::LoginController(QObject *parent) {
    //connect(ui->logInButton, &QPushButton::clicked, this, &LoginController::onLoginButtonClicked);
    qDebug() << "Login Sequence Started";
}

LoginController::~LoginController() {
}

void LoginController::setView(Login *view) {
    m_view = view;
}

void LoginController::processLogin(const QString &username, const QString &password) {
    // username, userpassword에 의해 사용자 판단 로직
    // login 로직 구현
    //***************************************************************/
    bool logged_in = false;
    bool managerFlag = false;
    MemberManager& memberManager = MemberManager::getInstance();
    QString userid = username;
    QString userpw = password;
    QMap<QString, Member*> temp;
    temp = memberManager.getMemberMap();
    for (auto it = temp.constBegin(); it!=temp.constEnd(); ++it) {
        if (it.key() == userid && it.value()->getMemberPW() == userpw) {
            if (it.value()->isManager()==true){
                QMap<QString, Member*> loginMember;
                loginMember.insert(it.key(), it.value());
                memberManager.setLoggedInMember(loginMember);
                logged_in = true;
                managerFlag = true;
                //Admin *admin = new Admin;
                //admin->show();
                //this->close();
            } else {
                QMap<QString, Member*> loginMember;
                loginMember.insert(it.key(), it.value());
                memberManager.setLoggedInMember(loginMember);
                logged_in = true;
                managerFlag = false;
                qDebug() << "normal";
                //Normal *normal = new Normal;
                //normal->show();
                //this->close();
            }
            if (logged_in && managerFlag) {         // Admin일 경우
                emit loginSuccess(username, true);
                break;
            } else if (logged_in && !managerFlag) { // Normal일 경우
                emit loginSuccess(username, false);
                break;
            }
        }
    }
    // 오류 처리
    if (!logged_in) {
        emit loginFailed(tr("아이디 또는 비밀번호가 잘못되었습니다"));
    }
}

void Login::handleLoginSuccess(const QString &username, bool isAdmin) {
    qDebug() << "Login::setController() 함수 호출됨.";
    if (m_controller == nullptr) {
        qDebug() << "경고: LoginController 포인터가 nullptr입니다.";
    }

    // 로그인 성공 처리
    if (isAdmin) {
        // 관리자용 Form 열기
        //emit openAdminForm(username);
        qDebug() << "로그인";
        Admin *m_admin = new Admin;
        AdminController *adminController = new AdminController();
        adminController->setAdminView(m_admin);
        m_admin->setController(adminController);
        m_admin->show();
    } else {
        // 일반 사용자용 Form 열기
        //emit openUserForm(username);
        Normal *m_normal = new Normal;
        NormalController *normalController = new NormalController();
        m_normal->setController(normalController);
        normalController->setNormalView(m_normal);
        m_normal->show();
    }

    // 현재 로그인 창 닫기 (필요에 따라)
    this->close();
}

void Login::handleLoginFailed(const QString &errorMessage) {
    // 로그인 실패 메시지 표시 (예: QMessageBox 사용)
    QMessageBox::warning(this, "로그인 오류", errorMessage);
    qDebug() << "로그인 오류";
}

// void LoginController::onLoginButtonClicked() {
//     // ui의 id, pw 가져오기
//     QString id = ui->idEdit->text();
//     QString pw = ui->pwEdit->text();

//     qDebug() << "Login Button Clicked";
//     // login 로직 구현
//     /***************************************************************/
//     //
//     //
//     //
//     /***************************************************************/
//     Admin *admin = new Admin;
//     admin->show();
//     delete ui;
// }
