#ifndef NORMALORDERVERIFYFORM_H
#define NORMALORDERVERIFYFORM_H

#include <QWidget>
#include <QTableWidgetItem>
#include "raspiconnector.h"
namespace Ui {
class NormalOrderVerifyForm;
}

class NormalOrderVerifyForm : public QWidget
{
    Q_OBJECT

public:
    explicit NormalOrderVerifyForm(QWidget *parent = nullptr);
    ~NormalOrderVerifyForm();


    int getOrderCount();
    void decreaseOrderCount();
    void increaseOrderCount();

public slots:
    void updateOrderList();
    void appendLog(const QString& msg);
    void updateQrProductData();

private slots:
    void on_toolBox_currentChanged(int index);



    void on_disconnect_clicked();

    void on_connect_clicked();

private:
    Ui::NormalOrderVerifyForm *ui;
};

#endif // NORMALORDERVERIFYFORM_H
