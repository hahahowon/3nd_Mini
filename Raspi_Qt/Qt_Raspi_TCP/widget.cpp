#include "widget.h"
#include "ui_widget.h"
#include "server.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(Server::getInstance(), &Server::logMessage, this, &Widget::appendLog);
    connect(Server::getInstance(),&Server::QRcodeData ,this, &Widget::appendProductQuantity);
    QStringList headers = {"제품ID", "제품이름", "가격", "카테고리", "수량"};
    ui->tw_product->setColumnCount(headers.size());
    ui->tw_product->setHorizontalHeaderLabels(headers);
    ui->tw_product->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_product->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_product->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_Server_Start_clicked()
{
    Server::getInstance()->startServer(12345);


    //테스트용 코드 버튼 누르면 json 파일 가져오는걸로 해보자

    QFile file("productCatalog.json");
    if(file.open(QIODevice::ReadOnly)){
        QByteArray jsonData = file.readAll();
        QJsonDocument productCatalog = QJsonDocument::fromJson(jsonData);
        qDebug()<< "jsonOpen Test :\n" << productCatalog;
        file.close();
        productQMap(productCatalog);
    }
}

void Widget::productQMap(const QJsonDocument productCatalog)
{
    if (!productCatalog.isArray()) {
        qWarning() << "[ERROR] JSON 최상위 구조가 배열이 아닙니다.";
        return;
    }

    QJsonArray jsonArray = productCatalog.array();

    for (const QJsonValue& val : jsonArray) {
        if (!val.isObject()) continue;

        QJsonObject obj = val.toObject();

        QString id = obj["productId"].toString();
        QString name = obj["productName"].toString();
        QString category = obj["category"].toString();
        double price = obj["price"].toDouble();

        Product p;
        p.setProductId(id);
        p.setProductName(name);
        p.setCategory(category);
        p.setPrice(price);

        productMap.insert(id, p);
    }
    qDebug() << "✅ productMap 저장 완료. 총 개수:" << productMap.size();
}


void Widget::on_btn_Server_Stop_clicked()
{
    Server::getInstance()->stopServer();
}


void Widget::appendLog(const QString& msg){
    ui->te_log->append(msg);
}


void Widget::appendProductQuantity(const QJsonDocument& doc) {
    const QJsonObject obj = doc.object();
    const QString id = obj.value("productId").toString();
    const int quantity = 1;

    if (!productMap.contains(id)) {
        qWarning() << "[ERROR] productMap에 없는 ID:" << id;
        return;
    }

    const Product& p = productMap[id];
    const int rowCount = ui->tw_product->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QTableWidgetItem* idItem = ui->tw_product->item(row, 0);
        if (idItem && idItem->text() == id) {
            QTableWidgetItem* qtyItem = ui->tw_product->item(row, 4);
            const int currentQty = qtyItem->text().toInt();
            qtyItem->setText(QString::number(currentQty + quantity));
            qDebug() << "[INFO] 수량 증가:" << id << ", 총 수량:" << currentQty + quantity;
            return;
        }
    }

    // 신규 항목 추가
    const int newRow = rowCount;
    ui->tw_product->insertRow(newRow);

    ui->tw_product->setItem(newRow, 0, new QTableWidgetItem(p.getProductId()));
    ui->tw_product->setItem(newRow, 1, new QTableWidgetItem(p.getProductName()));
    ui->tw_product->setItem(newRow, 2, new QTableWidgetItem(QString::number(p.getPrice())));
    ui->tw_product->setItem(newRow, 3, new QTableWidgetItem(p.getCategory()));
    ui->tw_product->setItem(newRow, 4, new QTableWidgetItem(QString::number(quantity)));

    qDebug() << "[INFO] 신규 제품 추가:" << id;

}






void Widget::on_btn_Save_clicked()
{
    int rowCount = ui->tw_product->rowCount();
    int columnCount = ui->tw_product->columnCount();

    QJsonArray jsonArray;

    for (int row = 0; row < rowCount; ++row) {
        QJsonObject jsonRow;

        QString productId   = ui->tw_product->item(row, 0)->text();
        QString productName = ui->tw_product->item(row, 1)->text();
        QString priceStr    = ui->tw_product->item(row, 2)->text();
        QString category    = ui->tw_product->item(row, 3)->text();
        QString qtyStr      = ui->tw_product->item(row, 4)->text();

        jsonRow["productId"]   = productId;
        jsonRow["productName"] = productName;
        jsonRow["price"]       = priceStr.toDouble();
        jsonRow["category"]    = category;
        jsonRow["quantity"]    = qtyStr.toInt();

        jsonArray.append(jsonRow);
    }

    QJsonDocument doc(jsonArray);
    qDebug().noquote() << "실물 수량 확인" << doc.toJson(QJsonDocument::Indented);
}

