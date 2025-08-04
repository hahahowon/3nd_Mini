#include "database.h"

Database& Database::getInstance() {
    static Database instance;
    return instance;
}

Database::Database() {
    qDebug() << "Created Database Loader";
}

Database::~Database() {
    qDebug() << "Destroyed Database Loader";
}

bool Database::connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");        // MySQL 서버 주소
    db.setDatabaseName("shopdb");       // 데이터베이스 이름
    db.setUserName("root");             // 사용자 이름
    db.setPassword("0808Shinedays!");   // 비밀번호
    db.setPort(3306);                   // MySQL 포트 (기본값)

    if (!db.open()) {
        qDebug() << "데이터베이스 연결 실패:" << db.lastError().text();
        return false;
    }

    qDebug() << "데이터베이스 연결 성공!";
    return true;
}
