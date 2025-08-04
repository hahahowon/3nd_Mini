#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Database : public QObject {
public:
    static Database& getInstance();
    bool connectToDatabase();

private:
    // 싱글턴 구현을 위한 생성자/소멸자의 private 접근제한
    Database();
    ~Database();

    // 싱글턴 구현을 위한 복사 생성자 및 대입 연산자 삭제
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

#endif // DATABASE_H
