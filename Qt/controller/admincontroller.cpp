#include "admincontroller.h"
#include "normalorderform.h"
#include "normalorderverifyform.h"
AdminController::AdminController(QObject *parent) {
    qDebug() << "Admin Sequence Started";
}

AdminController::~AdminController() {
}

void AdminController::setAdminView(Admin *admin) {
    m_admin = admin;
    m_adminInfo = admin->m_adminInfoForm;
    m_adminChat = admin->m_adminChatForm;
    m_adminProduct = admin->m_adminProductForm;
    m_adminOrderList = admin->m_adminOrderListForm;
}
