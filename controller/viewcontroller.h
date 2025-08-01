#ifndef VIEWCONTROLLER_H
#define VIEWCONTROLLER_H
#include "admininfoform.h"
#include "adminchatform.h"
#include "adminorderlistform.h"
#include "adminproductform.h"
#include "normalchatform.h"
#include "normalorderform.h"

class AdminInfoForm;
class AdminChatForm;
class AdminOrderListForm;
class AdminProductForm;

class NormalChatForm;
class NormalOrderForm;

class ViewController {
public:
    ViewController();
    void AdminViewHandler();
    void NormalViewHandler();
private:
    AdminInfoForm *m_adminInfoForm;
    AdminChatForm *m_adminChatForm;
    AdminOrderListForm *m_adminOrderListForm;
    AdminProductForm *m_adminProductForm;
    NormalChatForm *m_normalChatForm;
    NormalOrderForm *m_normalOrderForm;
};

#endif // VIEWCONTROLLER_H
