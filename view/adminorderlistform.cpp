#include "adminorderlistform.h"
#include "ui_adminorderlistform.h"

AdminOrderListForm::AdminOrderListForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminOrderListForm)
{
    ui->setupUi(this);
}

AdminOrderListForm::~AdminOrderListForm()
{
    delete ui;
}
