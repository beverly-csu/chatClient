#include "client.hpp"

Client::Client(QString username, QString address, quint16 port)
{
    _username = username;
    QHostAddress* ip = new QHostAddress(address);
    _socket = new QTcpSocket(this);
    _socket->connectToHost(*ip, port);
    qDebug() << "Sock: " << _socket->isOpen();

}

Client::Client(QString address, quint64 port)
{
    qDebug() << address << ":" << port;
}

void Client::sendMsgToClient(const QString &msg) {
    QByteArray byteArray;
    QDataStream outcomingStream(&byteArray, QIODevice::WriteOnly);
    outcomingStream.setVersion(QDataStream::Qt_6_0);
    outcomingStream << msg;
    _socket->write(byteArray);
}
