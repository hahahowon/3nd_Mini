#ifndef DATABASE_H
#define DATABASE_H
#include <QCoreApplication>
#include <QObject>
#include <QHttpServer>
#include <QTcpServer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QtSql>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

class Database : public QObject {
public:
    static Database& getInstance();
    bool connectToDatabase();
    QJsonArray getAllUsers();
    QJsonArray getAllProducts();
    QJsonArray getAllOrderLists();

private:
    // 싱글턴 구현을 위한 생성자/소멸자의 private 접근제한
    Database();
    ~Database();

    QSqlDatabase db;
    QHttpServer server;

    // 싱글턴 구현을 위한 복사 생성자 및 대입 연산자 삭제
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

#endif // DATABASE_H
