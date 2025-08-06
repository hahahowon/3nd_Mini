#ifndef NORMALODERCHECKERFORM_H
#define NORMALODERCHECKERFORM_H

#include <QWidget>

namespace Ui {
class NormalOderCheckerForm;
}

class NormalOderCheckerForm : public QWidget
{
    Q_OBJECT

public:
    explicit NormalOderCheckerForm(QWidget *parent = nullptr);
    ~NormalOderCheckerForm();

private:
    Ui::NormalOderCheckerForm *ui;
};

#endif // NORMALODERCHECKERFORM_H
