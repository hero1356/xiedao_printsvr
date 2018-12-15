#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

#define MAX_SOCKET_READ_SIZE 64*1024*1024

class MyClient : public QObject
{
    Q_OBJECT
public:

    QStringList msg_list;

    explicit MyClient(QObject *parent = 0);

    QTcpSocket *socket;

    void sendMsg(QString msg);

    int searchFrame(QString msg);

    int availableMsg();

private:
    QByteArray temp;


};

#endif // MYCLIENT_H
