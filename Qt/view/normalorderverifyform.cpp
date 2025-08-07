#include "normalorderverifyform.h"
#include "ui_normalorderverifyform.h"
#include "productmanager.h"

NormalOrderVerifyForm::NormalOrderVerifyForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderVerifyForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);


    // 상품 관리자 인스턴스 호출 및 상품 카탈로그 QMap 형태의 상품 리스트 호출
    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, OrderedProduct*> productCatalog = productManager.getOrderedProductMap();


    // QTableWidget 설정
    QStringList headers;
    headers << "상품명" << "상품ID" << "가격" << "카테고리" << "개수";
    // 전체 위젯
    ui->allWidget->setColumnCount(headers.size());
    ui->allWidget->setHorizontalHeaderLabels(headers);
    // 음료 위젯
    ui->beverageWidget->setColumnCount(headers.size());
    ui->beverageWidget->setHorizontalHeaderLabels(headers);
    // 스낵 위젯
    ui->snackWidget->setColumnCount(headers.size());
    ui->snackWidget->setHorizontalHeaderLabels(headers);
    // 즉석식품 위젯
    ui->instantWidget->setColumnCount(headers.size());
    ui->instantWidget->setHorizontalHeaderLabels(headers);
    // 유제품/아이스크림 위젯
    ui->milkiceWidget->setColumnCount(headers.size());
    ui->milkiceWidget->setHorizontalHeaderLabels(headers);
    // 주류 위젯
    ui->drinkWidget->setColumnCount(headers.size());
    ui->drinkWidget->setHorizontalHeaderLabels(headers);
    // 생필품 위젯
    ui->neceWidget->setColumnCount(headers.size());
    ui->neceWidget->setHorizontalHeaderLabels(headers);

    // 사용자 장바구니 위젯
    QStringList orderHeaders;
    orderHeaders << "상품명" << "상품ID" << "가격" << "카테고리" << "개수";
    ui->orderWidget->setColumnCount(orderHeaders.size());
    ui->orderWidget->setHorizontalHeaderLabels(orderHeaders);

    // 호출된 상품 리스트의 개수에 맞게 각 카테고리별 위젯의 행 개수 설정
    ui->allWidget->setRowCount(productCatalog.size());
    ui->beverageWidget->setRowCount(productCatalog.size());
    ui->snackWidget->setRowCount(productCatalog.size());
    ui->instantWidget->setRowCount(productCatalog.size());
    ui->milkiceWidget->setRowCount(productCatalog.size());
    ui->drinkWidget->setRowCount(productCatalog.size());
    ui->neceWidget->setRowCount(productCatalog.size());

    // 제목에 해당하는 각 위젯 열 크기 조절
    ui->allWidget->setColumnWidth(0, 200);
    ui->beverageWidget->setColumnWidth(0, 200);
    ui->snackWidget->setColumnWidth(0, 200);
    ui->instantWidget->setColumnWidth(0, 200);
    ui->milkiceWidget->setColumnWidth(0, 200);
    ui->drinkWidget->setColumnWidth(0, 200);
    ui->neceWidget->setColumnWidth(0, 200);
    ui->orderWidget->setColumnWidth(0, 200);

}

void NormalOrderVerifyForm::updateOrderList() {
    // qDebug() << "hello";
    // 상품 목록을 담은 QMap 호출
    // increaseOrderCount();
    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, OrderedProduct*> productCatalog = productManager.getOrderedProductMap();

    ui->allWidget->setRowCount(productCatalog.size());
    //orderCount = productCatalog.size();
    auto it = productCatalog.constBegin();
    for (int row = 0; it!=productCatalog.constEnd(); ++row, ++it) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
        QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
        QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
        QTableWidgetItem *quantityItem = new QTableWidgetItem(QString::number(it.value()->getProductQauntity()));

        ui->allWidget->setItem(row, 0, nameItem);
        ui->allWidget->setItem(row, 1, idItem);
        ui->allWidget->setItem(row, 2, priceItem);
        ui->allWidget->setItem(row, 3, categoryItem);
        ui->allWidget->setItem(row, 4, quantityItem);
    }
    qDebug() << productCatalog.constBegin().key();
    qDebug() << productCatalog.constBegin().value()->getProductQauntity();
}

NormalOrderVerifyForm::~NormalOrderVerifyForm() {
    delete ui;
}

int NormalOrderVerifyForm::getOrderCount() {
    return orderCount;
}

void NormalOrderVerifyForm::increaseOrderCount() {
    orderCount++;
}

void NormalOrderVerifyForm::decreaseOrderCount() {
    orderCount--;
}
