#include "normalorderform.h"
#include "ui_normalorderform.h"

NormalOrderForm::NormalOrderForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOrderForm) {
    ui->setupUi(this);
}

NormalOrderForm::~NormalOrderForm()
{
    delete ui;
}
