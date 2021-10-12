#ifndef CLIENT_H
#define CLIENT_H

#include <QCoreApplication>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>
#include <QThread>


class Client : public QObject{
Q_OBJECT
private:
    QString _username = "username";
    QTcpSocket* _socket;

public:
    Client(QString, QString, quint16);
    Client(QString, quint64);
    void sendMsg(const QString &msg);
    QAbstractSocket::SocketState isConnected();

public slots:
    void readyRead_slot();
};

class MessageThread : public QThread
{
public:
    explicit MessageThread(QString threadName, Client *client);
    void run(Client *client);
private:
    QString name;
};

#endif // CLIENT_H
