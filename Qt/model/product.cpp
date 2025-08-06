// product.cpp

#include "product.h"

Product::Product(QString productID, QString productName, int productPrice, QString productCategory) :
    m_productID(productID), m_productName(productName), m_productPrice(productPrice), m_productCategory(productCategory) {
}

Product::~Product() {
}

QString Product::getProductID() {
    return m_productID;
}

QString Product::getProductName() {
    return m_productName;
}

int Product::getProductPrice() {
    return m_productPrice;
}

QString Product::getProductCategory() {
    return m_productCategory;
}
