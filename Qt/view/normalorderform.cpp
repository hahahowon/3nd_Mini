// normalorderform.cpp

#include "normalorderform.h"
#include "ui_normalorderform.h"
#include "productmanager.h"
// #include "normalcontroller.h"
NormalOrderForm::NormalOrderForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    // 각 위젯에 대한 헤더 설정 및 컬럼 개수 설정
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

    // 상품 관리자 인스턴스 호출 및 상품 카탈로그 QMap 형태의 상품 리스트 호출
    ProductManager& productManager = ProductManager::getInstance();
    QMap<QString, Product*> productCatalog;
    productCatalog = productManager.getProductMap();

    // 호출된 상품 리스트의 개수에 맞게 각 카테고리별 위젯의 행 개수 설정
    ui->allWidget->setRowCount(productCatalog.size());
    ui->beverageWidget->setRowCount(productCatalog.size());
    ui->snackWidget->setRowCount(productCatalog.size());
    ui->instantWidget->setRowCount(productCatalog.size());
    ui->milkiceWidget->setRowCount(productCatalog.size());
    ui->drinkWidget->setRowCount(productCatalog.size());
    ui->neceWidget->setRowCount(productCatalog.size());
    ui->orderWidget->setRowCount(orderCount);

    // 제목에 해당하는 각 위젯 열 크기 조절
    ui->allWidget->setColumnWidth(0, 250);
    ui->beverageWidget->setColumnWidth(0, 250);
    ui->snackWidget->setColumnWidth(0, 250);
    ui->instantWidget->setColumnWidth(0, 250);
    ui->milkiceWidget->setColumnWidth(0, 250);
    ui->drinkWidget->setColumnWidth(0, 250);
    ui->neceWidget->setColumnWidth(0, 250);
    ui->orderWidget->setColumnWidth(0, 200);

    // 이터레이터 선언 및 각 카테고리별 행 변수 선언
    auto it = productCatalog.constBegin();
    int beverageRow = 0;
    int snackRow = 0;
    int instantRow = 0;
    int milkRow = 0;
    int drinkRow = 0;
    int neceRow = 0;

    // 일단 모든 상품 목록을 전체 카테고리 위젯에 출력
    for (int row=0; row<productCatalog.size(); ++row, ++it) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
        QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
        QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
        QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
        ui->allWidget->setItem(row, 0, nameItem);
        ui->allWidget->setItem(row, 1, idItem);
        ui->allWidget->setItem(row, 2, priceItem);
        ui->allWidget->setItem(row, 3, categoryItem);
    }

    // 카테고리가 "음료" 인 경우
    // 음료 테이블 위젯에 음료만 출력
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "음료") {
            QTableWidgetItem *beverageName = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *beverageID = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *beveragePrice = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *beverageCategory = new QTableWidgetItem(it.value()->getProductCategory());
            ui->beverageWidget->setItem(beverageRow, 0, beverageName);
            ui->beverageWidget->setItem(beverageRow, 1, beverageID);
            ui->beverageWidget->setItem(beverageRow, 2, beveragePrice);
            ui->beverageWidget->setItem(beverageRow, 3, beverageCategory);
            beverageRow++;
        }
    }

    // 카테고리가 "스낵" 인 경우
    // 스낵 테이블 위젯에 스낵만 출력
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "스낵") {
            QTableWidgetItem *snackName = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *snackID = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *snackPrice = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *snackCategory = new QTableWidgetItem(it.value()->getProductCategory());
            ui->snackWidget->setItem(snackRow, 0, snackName);
            ui->snackWidget->setItem(snackRow, 1, snackID);
            ui->snackWidget->setItem(snackRow, 2, snackPrice);
            ui->snackWidget->setItem(snackRow, 3, snackCategory);
            snackRow++;
        }
    }

    // 카테고리가 "즉석식품" 인 경우
    // 즉석식품 테이블 위젯에 즉석식품만 출력
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "즉석식품") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->instantWidget->setItem(instantRow, 0, nameItem);
            ui->instantWidget->setItem(instantRow, 1, idItem);
            ui->instantWidget->setItem(instantRow, 2, priceItem);
            ui->instantWidget->setItem(instantRow, 3, categoryItem);
            instantRow++;
        }
    }

    // 카테고리가 "유제품/아이스크림" 인 경우
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "유제품/아이스크림") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->milkiceWidget->setItem(milkRow, 0, nameItem);
            ui->milkiceWidget->setItem(milkRow, 1, idItem);
            ui->milkiceWidget->setItem(milkRow, 2, priceItem);
            ui->milkiceWidget->setItem(milkRow, 3, categoryItem);
            milkRow++;
        }
    }

    // 카테고리가 "주류" 인 경우
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "주류") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->drinkWidget->setItem(drinkRow, 0, nameItem);
            ui->drinkWidget->setItem(drinkRow, 1, idItem);
            ui->drinkWidget->setItem(drinkRow, 2, priceItem);
            ui->drinkWidget->setItem(drinkRow, 3, categoryItem);
            drinkRow++;
        }
    }

    // 생활용품
    for (it = productCatalog.constBegin(); it!=productCatalog.constEnd(); ++it) {
        if (it.value()->getProductCategory() == "생활용품") {
            QTableWidgetItem *nameItem = new QTableWidgetItem(it.value()->getProductName());
            QTableWidgetItem *idItem = new QTableWidgetItem(it.value()->getProductID());
            QTableWidgetItem *priceItem = new QTableWidgetItem(QString::number(it.value()->getProductPrice()));
            QTableWidgetItem *categoryItem = new QTableWidgetItem(it.value()->getProductCategory());
            ui->neceWidget->setItem(neceRow, 0, nameItem);
            ui->neceWidget->setItem(neceRow, 1, idItem);
            ui->neceWidget->setItem(neceRow, 2, priceItem);
            ui->neceWidget->setItem(neceRow, 3, categoryItem);
            neceRow++;
        }
    }

    // 출력된 각 카테고리별 행 수에 맞게 행 개수 재조정
    ui->beverageWidget->setRowCount(beverageRow);
    ui->snackWidget->setRowCount(snackRow);
    ui->instantWidget->setRowCount(instantRow);
    ui->milkiceWidget->setRowCount(milkRow);
    ui->drinkWidget->setRowCount(drinkRow);
    ui->neceWidget->setRowCount(neceRow);

    // 점주 입장에서는 상품 카테고리의 수정권이 없다.
    // 본사에서 제공하는 내용이기 때문.
    ui->allWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->beverageWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->snackWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->instantWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->milkiceWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->drinkWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->neceWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 프로그램 시작 시, 전체 카테고리를 default(6번째 툴바/위젯)로 표시할 것.
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    // 각 상품 리스트의 아이템을 더블클릭할 경우, 시그널 슬롯 연결
    connect(ui->allWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->beverageWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->snackWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->instantWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->milkiceWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->drinkWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);
    connect(ui->neceWidget, &QTableWidget::itemDoubleClicked, this, &NormalOrderForm::onItemDoubleClicked);




}

NormalOrderForm::~NormalOrderForm() {
    delete ui;
}

void NormalOrderForm::on_toolBox_currentChanged(int index) {
    ui->stackedWidget->setCurrentIndex(index);
    //qDebug() << tr("QToolBox 페이지 변경됨 -> 인덱스:") << index << tr(", QStackedWidget 페이지 변경됨.");
}

void NormalOrderForm::onItemDoubleClicked(QTableWidgetItem *item) {
    int row = item->row();
    int rowCount = ui->orderWidget->rowCount();
    bool isItem = false;
    QTableWidgetItem *nameItem = new QTableWidgetItem();
    QTableWidgetItem *idItem = new QTableWidgetItem();
    QTableWidgetItem *priceItem = new QTableWidgetItem();
    QTableWidgetItem *quantityItem = new QTableWidgetItem();
    QTableWidgetItem *categoryItem = new QTableWidgetItem();

    // 더블클릭 된 상품의 각 정보를 복사
    nameItem->setText(item->tableWidget()->item(row, 0)->text());
    idItem->setText(item->tableWidget()->item(row, 1)->text());
    priceItem->setText(item->tableWidget()->item(row, 2)->text());
    categoryItem->setText(item->tableWidget()->item(row, 3)->text());

    for (int i=0; i<rowCount; i++) {
        if (idItem->text() == ui->orderWidget->item(i, 1)->text()) {
            isItem = true;
            quantityItem = ui->orderWidget->item(i, 4);
            QVariant data = quantityItem->data(Qt::EditRole);
            if (data.canConvert<double>()) {
                double value = data.toDouble();
                value++;
                quantityItem->setData(Qt::EditRole, value);
            }
        }
    }

    if (!isItem) {
        double value = 1;
        quantityItem->setData(Qt::EditRole, value);

        // 장바구니의 행 개수 추가
        increaseOrderCount();
        ui->orderWidget->setRowCount(getOrderCount());
        qDebug() << getOrderCount();

        // 해당 행에 더블클릭되었던 상품 정보 입력
        ui->orderWidget->setItem(getOrderCount()-1, 0, nameItem);
        ui->orderWidget->setItem(getOrderCount()-1, 1, idItem);
        ui->orderWidget->setItem(getOrderCount()-1, 2, priceItem);
        ui->orderWidget->setItem(getOrderCount()-1, 3, categoryItem);
        ui->orderWidget->setItem(getOrderCount()-1, 4, quantityItem);
    }

    // 디버깅 메시지
    qDebug() << nameItem->text() << idItem->text() << priceItem->text() << categoryItem->text() << quantityItem->text();
}

int NormalOrderForm::getOrderCount() {
    return orderCount;
}

void NormalOrderForm::increaseOrderCount() {
    orderCount++;
}

void NormalOrderForm::decreaseOrderCount() {
    orderCount--;
}

void NormalOrderForm::on_orderButton_clicked() {
    ProductManager& productManager = ProductManager::getInstance();
    int rowCount = ui->orderWidget->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem* idItem = ui->orderWidget->item(row, 0);        // 상품ID
        QTableWidgetItem* nameItem = ui->orderWidget->item(row, 1);      // 상품명
        QTableWidgetItem* priceItem = ui->orderWidget->item(row, 2);     // 가격
        QTableWidgetItem* categoryItem = ui->orderWidget->item(row, 3);  // 카테고리
        QTableWidgetItem* quantityItem = ui->orderWidget->item(row, 4);  // 개수

        if (idItem && nameItem && priceItem && categoryItem && quantityItem) {
            QString id = idItem->text();
            QString name = nameItem->text();
            int price = priceItem->data(Qt::EditRole).toInt();  // 숫자형 데이터로 변환
            QString category = categoryItem->text();
            int quantity = quantityItem->data(Qt::EditRole).toInt();

            // Product 객체 생성
            OrderedProduct* product = new OrderedProduct(name, id, price, category, quantity);

            // QMap에 삽입 (상품ID를 키로 사용)
            productManager.registerOrderedProducts(product, id);

        }
    }
    emit orderUpdate();

    qDebug() << "발주 버튼 클릭됨. emit 호출 객체 주소:" << this;
}

