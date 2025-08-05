#ifndef ADMIN_H
#define ADMIN_H

#include "adminchatform.h"
#include "admininfoform.h"
#include "adminproductform.h"
#include "adminorderlistform.h"

#include <QMainWindow>
class AdminController;

namespace Ui {
class Admin;
}

class Admin : public QMainWindow {
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

    void setController(AdminController *adminController);

    AdminInfoForm *m_adminInfoForm;
    AdminChatForm *m_adminChatForm;
    AdminProductForm *m_adminProductForm;
    AdminOrderListForm *m_adminOrderListForm;

private:
    Ui::Admin *ui;
    AdminController *m_adminController;

};

#endif // ADMIN_H
