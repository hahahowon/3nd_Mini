#ifndef EXSQL_H
#define EXSQL_H

#include <QSqlDatabase> // DB 연결 용
#include <QSqlQuery> // 쿼리 문법 사용용
#include <QSqlError>

class ExSql
{
public:
    ExSql();

    static bool connectDB(); // DB 연결
    static void printUsers(); // mysql에서 만든 데이터 출력
};

#endif // EXSQL_H
