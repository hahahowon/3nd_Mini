#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin) {
    ui->setupUi(this);

    // 제목 표시줄 설정 : 관리자모드
    //setWindowTitle(tr("QT25 관리자 시스템: %1").arg(member.begin().key()));
    setWindowTitle(tr("QT25 관리자 시스템"));
}

Admin::~Admin()
{
    delete ui;
}
