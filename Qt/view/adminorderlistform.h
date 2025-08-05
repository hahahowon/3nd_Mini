#ifndef ADMINORDERLISTFORM_H
#define ADMINORDERLISTFORM_H

#include <QWidget>

namespace Ui {
class AdminOrderListForm;
}

class AdminOrderListForm : public QWidget {
    Q_OBJECT

public:
    explicit AdminOrderListForm(QWidget *parent = nullptr);
    ~AdminOrderListForm();

private:
    Ui::AdminOrderListForm *ui;
};

#endif // ADMINORDERLISTFORM_H
