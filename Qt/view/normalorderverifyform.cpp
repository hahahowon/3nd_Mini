#include "normalorderverifyform.h"
#include "ui_normalorderverifyform.h"
#include "productmanager.h"

NormalOrderVerifyForm::NormalOrderVerifyForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderVerifyForm)
{
    ui->setupUi(this);


    // 상품 관리자 인스턴스 호출 및 상품 카탈로그 QMap 형태의 상품 리스트 호출
    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, OrderedProduct*> productCatalog = productManager.getOrderedProductMap();
    productCatalog = productManager.getOrderedProductMap();



    // QTableWidget 설정
    QStringList headers;
    headers << "상품명" << "상품ID" << "가격" << "카테고리";
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
    ui->allWidget->setColumnWidth(0, 250);
    ui->beverageWidget->setColumnWidth(0, 250);
    ui->snackWidget->setColumnWidth(0, 250);
    ui->instantWidget->setColumnWidth(0, 250);
    ui->milkiceWidget->setColumnWidth(0, 250);
    ui->drinkWidget->setColumnWidth(0, 250);
    ui->neceWidget->setColumnWidth(0, 250);
    //ui->orderWidget->setColumnWidth(0, 200);

}

void NormalOrderVerifyForm::updateOrderList(){

    // 상품 목록을 담은 QMap 호출
    qDebug() << "hello";
    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, OrderedProduct*> productCatalog = productManager.getOrderedProductMap();

    qDebug() << productCatalog.constBegin().key();
    qDebug() << productCatalog.constBegin().value()->getProductQauntity();

}
NormalOrderVerifyForm::~NormalOrderVerifyForm()
{
    delete ui;
}
