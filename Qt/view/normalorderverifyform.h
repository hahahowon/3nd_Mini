#ifndef NORMALORDERVERIFYFORM_H
#define NORMALORDERVERIFYFORM_H

#include <QWidget>
#include <QTableWidgetItem>
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
    void increaseOrderCount();
    void decreaseOrderCount();


public slots:
    void updateOrderList();

private:
    Ui::NormalOrderVerifyForm *ui;


    // 사용자가 orderWidget에 아이템을 추가/삭제 할 때마다 변경될 예정
    // 최초는 1개의 행만 가짐
    int orderCount = 0;
};

#endif // NORMALORDERVERIFYFORM_H
