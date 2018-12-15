#include "myclient.h"
#include <QTextCodec>
#include <QStringList>
#include <QDateTime>

MyClient::MyClient(QObject *parent) :
    QObject(parent)
{
}

void MyClient::sendMsg(QString msg)
{
    QString time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
    qDebug()<<time<<"-- send --"<<msg;
    socket->write(msg.toLocal8Bit().constData());
    socket->flush();
}

int MyClient::availableMsg()
{
    while (socket->bytesAvailable())
    {
        temp = socket->readAll();
    }
    QTextCodec* pCodec = QTextCodec::codecForName("gbk");
    if(!pCodec) return false;
    QString qstr = pCodec->toUnicode(temp);

//    qDebug() << "Socket->readAll Origin Msg: "<<qstr;
    int count = searchFrame(qstr);
//    qDebug() << "Socket->readAll SearchFrame Count: " << count;

    return count;
}

int MyClient::searchFrame(QString msg)
{
    msg_list.clear();
    msg_list = msg.split('$',QString::SkipEmptyParts);

    return msg_list.count();
}
