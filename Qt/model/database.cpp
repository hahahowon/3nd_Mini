#include "database.h"
#include "membermanager.h"
#include "productmanager.h"

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
    db.setUserName("manager");             // 사용자 이름
    db.setPassword("1234");             // 비밀번호+
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
    MemberManager& memberManager = MemberManager::getInstance();

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

        QJsonObject memberObj = userObject;
        QString id = memberObj["id"].toString();
        QString password = memberObj["password"].toString();
        QString name = memberObj["name"].toString();
        Member* member = new Member(id, name, password);

        // 관리자 계정일 경우, 관리자 flag 설정
        if (memberObj["isManager"]==true) {
            member->setManager(true);
        }
        memberManager.registerMember(member, id);

        //usersArray.append(userObject);
        // 확인을 위한 qDebug Line
        qDebug() << member->getMemberID() << "registered.";
        //qDebug() << userObject;
    }

    return usersArray;
}

QJsonArray Database::getAllProducts() {
    QJsonArray productsArray;
    ProductManager& productManager = ProductManager::getInstance();

    if (!db.isOpen() && !connectToDatabase()) {
        return productsArray;
    }

    QSqlQuery query;
    query.prepare("SELECT productId, productName, price, category FROM products");

    if (!query.exec()) {
        qDebug() << "쿼리 실행 실패: " << query.lastError().text();
        return productsArray;
    }

    while (query.next()) {
        QJsonObject productObject;
        productObject["productId"] = query.value(0).toString();
        productObject["productName"] = query.value(1).toString();
        productObject["price"] = query.value(2).toInt();
        productObject["category"] = query.value(3).toString();

        QString productId = productObject["productId"].toString();
        QString productName = productObject["productName"].toString();
        int price = productObject["price"].toInt();
        QString category = productObject["category"].toString();
        Product* product = new Product(productId, productName, price, category);

        productManager.registerProduct(product, productId);

        //productsArray.append(userObject);
        // 확인을 위한 qDebug Line
        qDebug() << product->getProductID() << "registered.";
        //qDebug() << productObject;
    }

    return productsArray;
}
