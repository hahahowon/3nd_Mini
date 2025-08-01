// exsql을 철저히 Model로 사용하고자 분리
#include "exsql.h"

ExSql::ExSql() {}

bool ExSql::connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // mysql 사용할 거니까

    db.setHostName("localhost"); // 내가 첨부터 지정한 in mysql
    db.setPort(3306); // 기본으로 설정된 포트임
    db.setUserName("root"); // 역시 mysql 첨 만들 때 기본으로 설정
    db.setPassword("0000"); // 비번 0000 설정
    db.setDatabaseName("testdb"); // 내가 만든 mysql 데베 이름

    if(!db.open()){
        qDebug() << "안열림" << db.lastError().text();
        return false; // db 열기 안 된 경우
    }

    return true; // 그 외에는 db 열기 된 거니까
}

void ExSql::printUsers()
{
    QSqlQuery query("SELECT id, name FROM users");

    if(!query.exec()) return; // 쿼리가 동작을 안하면

    while(query.next()){
        // 다음 사용자로 쿼리할 만한 게 있으면
        int id = query.value(0).toInt(); // 0번 열(id) 값을 int로 변환
        QString name = query.value(1).toString(); // 1번 열(name) 값을 QString으로 변환
    }
}
