#ifndef NORMALCHATFORM_H
#define NORMALCHATFORM_H

#include <QWidget>

namespace Ui {
class NormalChatForm;
}

class NormalChatForm : public QWidget {
    Q_OBJECT

public:
    explicit NormalChatForm(QWidget *parent = nullptr);
    ~NormalChatForm();

private:
    Ui::NormalChatForm *ui;
};

#endif // NORMALCHATFORM_H
