// productmanager.h

#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include <QString>
#include <QObject>
#include <QMap>
#include "product.h"
#include "orderedproduct.h"
#include "qrproduct.h"
class ProductManager :public QObject {
    Q_OBJECT
signals:
    void updateQrMap();
public:
    static ProductManager& getInstance();

    bool removeProduct(const QString& productID);
    bool registerProduct(Product* product, const QString& productID);
    bool registerOrderedProducts(OrderedProduct* product, const QString& productID);
    bool registerQrProducts(QrProduct* product, const QString& productID);

    Product* findProductByCategory(const QString& productCategory);
    Product* findProductByName(const QString& productName);
    Product* findProductByID(const QString& productId);

    const QMap<QString, Product*>& getProductMap() const;
    const QMap<QString, OrderedProduct*>& getOrderedProductMap() const;
    const QMap<QString, QrProduct*>& getQrProductMap() const;

    void receiveQrData(const QByteArray& Qrdata);


private:
    // 싱글턴 구현을 위한 생성자/소멸자의 private 접근제한
    ProductManager();
    ~ProductManager();

    // 싱글턴 구현을 위한 복사 생성자 및 대입 연산자 삭제
    ProductManager(const ProductManager&) = delete;
    ProductManager& operator=(const ProductManager&) = delete;


    QMap<QString, Product*> productsByID;
    QMap<QString, OrderedProduct*> orderedProducts;
    QMap<QString, QrProduct*> qrProduct;
};

#endif // PRODUCTMANAGER_H
