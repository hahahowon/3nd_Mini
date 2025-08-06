// normalorderform.h

#ifndef NORMALORDERFORM_H
#define NORMALORDERFORM_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class NormalOrderForm;
}

class NormalOrderForm : public QWidget {
    Q_OBJECT

public:
    explicit NormalOrderForm(QWidget *parent = nullptr);
    ~NormalOrderForm();
    int getOrderCount();
    void increaseOrderCount();
    void decreaseOrderCount();

private slots:
    void on_toolBox_currentChanged(int index);
    void onItemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::NormalOrderForm *ui;

    // 사용자가 orderWidget에 아이템을 추가/삭제 할 때마다 변경될 예정
    // 최초는 1개의 행만 가짐
    int orderCount = 0;
};

#endif // NORMALORDERFORM_H
