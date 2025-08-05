#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "product.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);~Widget();
public slots:
    void appendProductQuantity(const QJsonDocument& doc) ;
    void appendLog(const QString& msg);
    void productQMap(const QJsonDocument productCatalog);
private slots:
    void on_btn_Server_Start_clicked();
    void on_btn_Server_Stop_clicked();

    void on_btn_Save_clicked();

private:

    Ui::Widget *ui;
    QMap<QString, Product> productMap;
};
#endif // WIDGET_H
