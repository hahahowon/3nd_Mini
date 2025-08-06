#include "adminproductform.h"
#include "ui_adminproductform.h"

AdminProductForm::AdminProductForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminProductForm) {
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(6);
    ui->stackedWidget->setCurrentIndex(6);

    QStringList headers;
    headers << "상품명" << "상품ID" << "가격" << "카테고리";
    ui->allWidget->setColumnCount(headers.size());
    ui->allWidget->setHorizontalHeaderLabels(headers);
    ui->beverageWidget->setColumnCount(headers.size());
    ui->beverageWidget->setHorizontalHeaderLabels(headers);
    ui->snackWidget->setColumnCount(headers.size());
    ui->snackWidget->setHorizontalHeaderLabels(headers);
    ui->instantWidget->setColumnCount(headers.size());
    ui->instantWidget->setHorizontalHeaderLabels(headers);
    ui->milkiceWidget->setColumnCount(headers.size());
    ui->milkiceWidget->setHorizontalHeaderLabels(headers);
    ui->drinkWidget->setColumnCount(headers.size());
    ui->drinkWidget->setHorizontalHeaderLabels(headers);
    ui->neceWidget->setColumnCount(headers.size());
    ui->neceWidget->setHorizontalHeaderLabels(headers);

    ui->allWidget->setColumnWidth(0, 250);
    ui->beverageWidget->setColumnWidth(0, 250);
    ui->snackWidget->setColumnWidth(0, 250);
    ui->instantWidget->setColumnWidth(0, 250);
    ui->milkiceWidget->setColumnWidth(0, 250);
    ui->drinkWidget->setColumnWidth(0, 250);
    ui->neceWidget->setColumnWidth(0, 250);
}

AdminProductForm::~AdminProductForm() {
    delete ui;
}
