#include "server.h"
Server* Server::instance = nullptr; //싱글턴 instance 초기화

Server* Server::getInstance(){
    if (!instance)
        instance = new Server();

    return instance;
}

Server::Server(QObject *parent) : QObject (parent)
{
    tcpServer = new QTcpServer(this); //TCP 서버 객체 생성
    //newConnetion 들어오면 onNewConnection 수행 : 슬롯 연결
    connect (tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
}




 void Server::startServer(qint16 port){

    if (tcpServer->isListening()){ //이미 열려있으면 알려주는 용도
        qDebug() << "Server is already running on port" << tcpServer->serverPort();
        return;
    }
    if (tcpServer->listen(QHostAddress::Any, port)){
        qDebug() << "[Server] ▶️ Server started on port " << port; // 수신대기
    } else{
        qDebug() << "[Server] ❌ Server failed " << tcpServer->errorString(); //연결 실패
    }
}

 void Server::stopServer() {
     if (tcpServer->isListening()) {
         tcpServer->close();
         qDebug() << "[Server]️ Server stopped.";
     } else {
         qDebug() << "[Server] Server was not running.";
     }
 }

void Server::newConnection(){

    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();
    qDebug() << "[Server] 🔌 클라이언트 접속:" << clientSocket->peerAddress().toString() << ":" << clientSocket->peerPort();
    qDebug().noquote() << QString("[Server] 🔌 새 연결 수신 - IP: %1, Port: %2")
                              .arg(clientSocket->peerAddress().toString())
                              .arg(clientSocket->peerPort());
    emit logMessage(QString("🔌 클라이언트 접속: %1:%2")
                        .arg(clientSocket->peerAddress().toString())
                        .arg(clientSocket->peerPort()));

    connect (clientSocket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(clientSocket, &QTcpSocket::disconnected, this, [=]() {
        clientSocket->deleteLater();     // 메모리 정리
        qDebug() << "[Server] Client disconnected.";
    });
}

void Server::onReadyRead() {
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    QByteArray data = socket->readAll();
    emit logMessage("[Server] 📥 수신 데이터: " + QString::fromUtf8(data));

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError || !doc.isObject()) return;

    emit QRcodeData(doc);
}
//json데이터로 받아서  리스트에 담아서 중복되는 이름이면 카운트 올려서 숫자 올리고, 서버는 제품아이디에 맞는 제품 내용 출력해주고
//현재 db는 완성 안되어있으니까 서버를 통해서 로컬에 json 파일 저장하는 형식으로 로직을 가져가야한다.]
//라즈베리파이는 led 와 스위치를 어떻게 해야할까.
//추가는 어렵지 않음 와이어링 파이로 제어 가능한 수준.
//스위치 버튼을 누르면 인식 시작으로 바꿀까으으으으어어어어ㅓ어어어어

Server::~Server()
{
    if (tcpServer) {
        if (tcpServer->isListening())
            tcpServer->close();
        tcpServer->deleteLater();
        tcpServer = nullptr;
    }
    qDebug() << "[Server] ✅ 소멸자 호출됨 (리소스 정리 완료)";
}
