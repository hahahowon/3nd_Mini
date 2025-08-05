#include "product.h"

Product::Product() {}

Product::Product(const QString& id, const QString& name, const QString& cat, double price)
    : productId(id), productName(name), category(cat), price(price) {}

QString Product::getProductId() const { return productId; }
QString Product::getProductName() const { return productName; }
QString Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }

void Product::setProductId(const QString& id) { productId = id; }
void Product::setProductName(const QString& name) { productName = name; }
void Product::setCategory(const QString& cat) { category = cat; }
void Product::setPrice(double p) { price = p; }

QJsonObject Product::toJson() const {
    QJsonObject obj;
    obj["productId"] = productId;
    obj["productName"] = productName;
    obj["category"] = category;
    obj["price"] = price;
    return obj;
}

Product Product::fromJson(const QJsonObject& obj) {
    return Product(
        obj["productId"].toString(),
        obj["productName"].toString(),
        obj["category"].toString(),
        obj["price"].toDouble()
        );
}
