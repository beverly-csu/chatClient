#include "client.hpp"

Client::Client(QString username, QString address, quint16 port)
{
    QHostAddress* ip = new QHostAddress(address);
    _socket = new QTcpSocket(this);
    _socket->connectToHost(*ip, port);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead_slot()));
    sendMsg(username);
}

Client::Client(QString address, quint64 port)
{
    QHostAddress* ip = new QHostAddress(address);
    _socket = new QTcpSocket(this);
    _socket->connectToHost(*ip, port);
    connect(_socket, SIGNAL(readyRead()), this, SLOT(readyRead_slot()));
    sendMsg(_username);
}

void Client::sendMsg(const QString &msg) {
    _socket->write(msg.toUtf8());
}

QAbstractSocket::SocketState Client::isConnected()
{
    return _socket->state();
}

void Client::readyRead_slot()
{
    _socket = (QTcpSocket*)sender();
    QByteArray data = _socket->readAll();

    QString str(data);

    qDebug() << str;
}

MessageThread::MessageThread(QString threadName, Client *client) : name(threadName)
{
    run(client);
}

void MessageThread::run(Client *client)
{
    QTextStream stdStream(stdin);
    QString msg;

    while (msg != "q") {
        msg = stdStream.readLine();
        qDebug() << "MSG READ";
        client->sendMsg(msg);
    }
}
