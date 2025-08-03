#include "normalchatform.h"
#include "ui_normalchatform.h"

NormalChatForm::NormalChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NormalChatForm) {
    ui->setupUi(this);
}

NormalChatForm::~NormalChatForm() {
    delete ui;
}
