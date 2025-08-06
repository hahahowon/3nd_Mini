// product.h

#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>

class Product {
public:
    Product(QString productID, QString productName, int productPrice, QString productCategory);
    ~Product();
    QString getProductName();
    QString getProductID();
    int getProductPrice();
    QString getProductCategory();

private:
    QString m_productName;
    QString m_productID;
    int m_productPrice;
    QString m_productCategory;
};

#endif // PRODUCT_H
