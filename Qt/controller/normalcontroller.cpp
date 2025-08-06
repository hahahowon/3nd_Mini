#include "normalcontroller.h"


NormalController::NormalController(QObject *parent) {
    qDebug() << "Normal Sequence Started";
}

NormalController::~NormalController() {
}

void NormalController::setNormalView(Normal *normal) {
    m_normal = normal;
    m_normalChatForm = normal->m_normalChatForm;
    m_normalOrderForm = normal->m_normalOrderForm;
}

