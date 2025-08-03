#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Admin) {
    ui->setupUi(this);

    // 제목 표시줄 설정 : 관리자모드
    //setWindowTitle(tr("QT25 관리자 시스템: %1").arg(member.begin().key()));
    setWindowTitle(tr("QT25 관리자 시스템"));

    m_adminInfoForm = new AdminInfoForm(this);
    m_adminChatForm = new AdminChatForm(this);
    m_adminProductForm = new AdminProductForm(this);
    m_adminOrderListForm = new AdminOrderListForm(this);

    // tab에 객체 추가
    ui->tabWidget->addTab(m_adminInfoForm, tr("고객정보"));
    ui->tabWidget->addTab(m_adminChatForm, tr("채팅서버"));
    ui->tabWidget->addTab(m_adminProductForm, tr("상품관리"));
    ui->tabWidget->addTab(m_adminOrderListForm, tr("발주목록"));
}

Admin::~Admin() {
    delete ui;
}

void Admin::setController(AdminController *adminController) {
    m_adminController = adminController;
    // connect 함수 나열
    /***************************************************************/
    //
    //
    //
    /***************************************************************/
}
