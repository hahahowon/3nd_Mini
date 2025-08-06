// productmanager.cpp

#include "productmanager.h"

ProductManager& ProductManager::getInstance() {
    static ProductManager instance;
    return instance;
}

ProductManager::ProductManager() {
    qDebug() << QObject::tr("ProductManager created.");
}

ProductManager::~ProductManager() {
    for (auto it = productsByID.begin(); it != productsByID.end(); ++it) {
        QString productID = it.key();
        Product* product = it.value();
        qDebug() << QObject::tr("Deleting product: %1 %2").arg(product->getProductName()).arg(product->getProductID());
        delete product; // Product 객체의 메모리 해제
    }
    productsByID.clear(); // 맵 비우기
    qDebug() << QObject::tr("ProductManager destroyed.");
}

bool ProductManager::registerProduct(Product* product, const QString& productID) {
    if (productsByID.count(productID)) {
        qDebug() << QObject::tr("Error: Already exist Product");
        return false;
    }
    productsByID[productID] = product;
    qDebug() << QObject::tr("Product registered: %1 %2").arg(product->getProductName()).arg(product->getProductID());
    return true;
}

bool ProductManager::registerOrderedProducts(OrderedProduct* product, const QString& productID) {
    if (orderedProducts.count(productID)) {
        qDebug() << QObject::tr("Error: Already exist Product");
        return false;
    }
    orderedProducts[productID] = product;
    qDebug() << QObject::tr("Product ordered: %1 %2").arg(product->getProductName()).arg(product->getProductID());
    return true;
}

bool ProductManager::removeProduct(const QString& productID) {
    // 맵에서 이름으로 상품 찾기
    auto it = productsByID.find(productID);
    if (it == productsByID.end()) {
        qDebug() << QObject::tr("Error: Product with Name %1").arg(productID) << " not found for removal.";
        return false; // 해당 상품이 없으면 삭제 실패
    }

    // 찾은 Product 객체의 메모리 해제
    delete it.value();

    // 맵에서 해당 상품 제거
    productsByID.erase(it);
    qDebug() << QObject::tr("Product removed: %1").arg(productID);
    return true; // 탈퇴 성공
}

Product* ProductManager::findProductByCategory(const QString& productCategory) {
    auto it = productsByID.find(productCategory);
    if (it != productsByID.end()) {
        return it.value();
    }
    return nullptr;
}

Product* ProductManager::findProductByName(const QString& productName) {
    auto it = productsByID.find(productName);
    if (it != productsByID.end()) {
        return it.value();
    }
    return nullptr;
}

const QMap<QString, Product*>& ProductManager::getProductMap() const {
    return productsByID;
}
const QMap<QString, OrderedProduct*>& ProductManager::getOrderedProductMap() const {
    return orderedProducts;
}
