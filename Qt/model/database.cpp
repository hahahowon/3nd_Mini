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
    db.setDatabaseName("qt25");         // 데이터베이스 이름
    db.setUserName("root");             // 사용자 이름
    db.setPassword("0000");             // 비밀번호
    db.setPort(3306);                   // MySQL 포트 (기본값)

    if (!db.open()) {
        qDebug() << "데이터베이스 연결 실패:" << db.lastError().text();
        return false;
    }

    qDebug() << "데이터베이스 연결 성공!";
    return true;
}

QJsonArray Database::getAllUsers() {
    QJsonArray usersArray;

    if (!db.isOpen() && !connectToDatabase()) {
        return usersArray;
    }

    QSqlQuery query;
    query.prepare("SELECT id, isManager, name, password FROM users");

    if (!query.exec()) {
        qDebug() << "쿼리 실행 실패: " << query.lastError().text();
        return usersArray;
    }

    while (query.next()) {
        QJsonObject userObject;
        userObject["id"] = query.value(0).toString();
        userObject["isManager"] = query.value(1).toBool();
        userObject["name"] = query.value(2).toString();
        userObject["password"] = query.value(3).toString();

        usersArray.append(userObject);
        qDebug() << userObject;
    }

    return usersArray;
}
