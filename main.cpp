#include "client.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client("sUser", "192.168.0.107", 7777);
    client.sendMsgToClient("FUCK THIS WORLD!");

    return a.exec();
}
