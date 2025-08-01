#ifndef ADMINCHATFORM_H
#define ADMINCHATFORM_H

#include <QWidget>

namespace Ui {
class AdminChatForm;
}

class AdminChatForm : public QWidget {
    Q_OBJECT

public:
    explicit AdminChatForm(QWidget *parent = nullptr);
    ~AdminChatForm();

private:
    Ui::AdminChatForm *ui;
};

#endif // ADMINCHATFORM_H
