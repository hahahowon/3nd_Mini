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
public slots:
    void updateOrderList();


private:
    Ui::NormalOrderVerifyForm *ui;
};

#endif // NORMALORDERVERIFYFORM_H
