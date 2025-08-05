#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QJsonObject>

class Product
{
private:
    QString productId;
    QString productName;
    QString category;
    double price;

public:
    Product();
    Product(const QString& id, const QString& name, const QString& cat, double price);

    QString getProductId() const;
    QString getProductName() const;
    QString getCategory() const;
    double getPrice() const;

    void setProductId(const QString& id);
    void setProductName(const QString& name);
    void setCategory(const QString& category);
    void setPrice(double price);

    QJsonObject toJson() const;
    static Product fromJson(const QJsonObject& obj);
};

#endif // PRODUCT_H
