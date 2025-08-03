#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H

#include <QObject>
#include "admin.h"
#include "admininfoform.h"
#include "adminchatform.h"
#include "adminproductform.h"
#include "adminorderlistform.h"

class AdminController : public QObject {
    Q_OBJECT

public:
    explicit AdminController(QObject *parent = nullptr);
    ~AdminController();
    void setAdminView(Admin *view);

private:
    Admin *m_admin;
    AdminInfoForm *m_adminInfo;
    AdminChatForm *m_adminChat;
    AdminProductForm *m_adminProduct;
    AdminOrderListForm *m_adminOrderList;
};

#endif // ADMINCONTROLLER_H
