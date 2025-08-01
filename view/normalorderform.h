#ifndef NORMALORDERFORM_H
#define NORMALORDERFORM_H

#include <QWidget>

namespace Ui {
class NormalOrderForm;
}

class NormalOrderForm : public QWidget {
    Q_OBJECT

public:
    explicit NormalOrderForm(QWidget *parent = nullptr);
    ~NormalOrderForm();

private:
    Ui::NormalOrderForm *ui;
};

#endif // NORMALORDERFORM_H
