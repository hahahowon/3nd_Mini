#include "adminchatform.h"
#include "ui_adminchatform.h"

AdminChatForm::AdminChatForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdminChatForm) {
    ui->setupUi(this);
}

AdminChatForm::~AdminChatForm() {
    delete ui;
}
