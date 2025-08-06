#include "normalodercheckerform.h"
#include "ui_normalodercheckerform.h"

NormalOderCheckerForm::NormalOderCheckerForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalOderCheckerForm)
{
    ui->setupUi(this);
}

NormalOderCheckerForm::~NormalOderCheckerForm()
{
    delete ui;
}
