#include "adminproductform.h"
#include "ui_adminproductform.h"

AdminProductForm::AdminProductForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminProductForm) {
    ui->setupUi(this);
}

AdminProductForm::~AdminProductForm() {
    delete ui;
}
