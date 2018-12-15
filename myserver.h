#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>
#include <QHashIterator>
#include <QString>
#include <QMutex>
#include <QJsonObject>
#include <QJsonDocument>
#include "myclient.h"

#include <QTextDocument>
#include <QTextFrame>
#include <QTextBlock>
#include <QTextEdit>
#include <QPrinterInfo>
#include <QDebug>
#include "JsonParse.h"
#include <QDateTime>
#include <QFont>

// JSON LATER
#define PRINTER_NAME_ONE     "printer1"
#define PRINTER_NAME_TWO     "printer2"
#define PRINTER_NAME_THREE   "printer3"
#define PRINTER_NAME_FOUR    "printer4"

#define PRINTER_ONE     0
#define PRINTER_TWO     1
#define PRINTER_THREE   2
#define PRINTER_FOUR    3
#define PRINTER_FIVE    4
#define PRINTER_X       PRINTER_ONE

#define COM1            101
#define COM2            102
#define COM3            103
#define COM4            104
#define COM5            105


class MyServer : public QObject
{
    Q_OBJECT

private:
    QTcpServer *server;
    QHash<QTcpSocket*, MyClient*> clientsList;
    QHash<QTcpSocket*, MyClient*>::iterator i;
    QMutex mutex;

    int seqno;

    QString m_printer1;
    QString m_printer2;
    QString m_printer3;
    QString m_printer4;
    QString m_printer5;



public:
    explicit MyServer(QObject *parent = 0);
    void runServer(QHostAddress address, int port);


    int getseqno();
    QString InitAck_cmd_send();
    QString AuthAck_cmd_send();
    QString pong_cmd_send();
    QString PrintAck_cmd_send(score_info_st score_info);
    QString make_checkSum(QString & str);
    unsigned char LongHToAscii(unsigned char* SrcBuff,unsigned char* DataBuff,unsigned int Len);


    void PrintDataProcess(MyClient* clientSocket, QString recvStr);
    void paiban(score_info_st score_info);
    void do_the_print(QPrinterInfo info, QTextEdit *edit, QString name);

signals:
    void signalReceiveDate(QString str);

public slots:
    void newConnection();
    void closedConnection();
    void ReceiveDataProcess();
};

#endif // MYSERVER_H
