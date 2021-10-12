#include "client.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client("sUser", "127.0.0.1", 5005);
//    while (true) {
//        if (client.isConnected() == QAbstractSocket::SocketState()) {
//            MessageThread thread("msg", &client);
//            thread.start();
//            break;
//        }
//    }

    return a.exec();
}
