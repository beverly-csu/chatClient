#ifndef CLIENT_H
#define CLIENT_H

#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>


class Client : public QObject{
Q_OBJECT
private:
    QString _username = "username";
    QTcpSocket* _socket;

public:
    Client(QString, QString, quint16);
    Client(QString, quint64);
    void sendMsgToClient(const QString &msg);


};

#endif // CLIENT_H
