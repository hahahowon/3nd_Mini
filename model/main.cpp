#include "login.h"
#include "logincontroller.h"
#include "database.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // DB Class의 생성자 호출 및 QMap 형태의 List 호출하여 로그인 로직 구현
    /***************************************************************/
    Database& db = Database::getInstance();
    db.connectToDatabase();
    /***************************************************************/

    // 국제화 로직 구현
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "QT25_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    // Login 화면 우선 출력: 이후 Login.cpp에서 분기점 형성
    Login w;
    LoginController *controller = new LoginController();
    controller->setView(&w);
    w.setController(controller);
    w.show();

    return a.exec();
}
