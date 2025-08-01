#include "viewcontroller.h"

ViewController::ViewController() {
    qDebug() << "ViewController initiated";
}

void ViewController::AdminViewHandler() {
    m_adminInfoForm = new AdminInfoForm(nullptr);
    m_adminChatForm = new AdminChatForm(nullptr);
    m_adminProductForm = new AdminProductForm(nullptr);
    m_adminOrderListForm = new AdminOrderListForm(nullptr);
}

void ViewController::NormalViewHandler() {
    m_normalChatForm = new NormalChatForm(nullptr);
    m_normalOrderForm = new NormalOrderForm(nullptr);
}
