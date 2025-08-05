#ifndef NORMALCONTROLLER_H
#define NORMALCONTROLLER_H

#include <QObject>
#include "normal.h"
#include "normalchatform.h"
#include "normalorderform.h"

class NormalController : public QObject {
    Q_OBJECT

public:
    explicit NormalController(QObject *parent = nullptr);
    ~NormalController();
    void setNormalView(Normal *view);

private:
    Normal *m_normal;
    NormalChatForm *m_normalChatForm;
    NormalOrderForm *m_normalOrderForm;
};

#endif // NORMALCONTROLLER_H
