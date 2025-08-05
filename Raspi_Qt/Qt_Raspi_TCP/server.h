#ifndef SERVER_H
#define SERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
class Server : public QObject
{
    Q_OBJECT
signals:
    void logMessage(const QString& msg);
    void QRcodeData(const QJsonDocument doc);

public:
    //싱글턴 인스턴스 getter
    static Server* getInstance();
    void startServer(qint16 port = 12345);
    void stopServer();~Server();


    //복사생성자, 대입 연산자 막기 위한 싱글턴
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

private:
    //생성자 프라이빗
    explicit Server(QObject *parent = nullptr);
    //인스턴스 선언
    static Server* instance;
    //서버객체 생성을 위해 헤더에 선언
    QTcpServer *tcpServer;
    // 새로운 연결 처리
    void newConnection();
    void onReadyRead();

};

#endif // SERVER_H
