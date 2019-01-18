#ifndef MYPRINTERINFO_H
#define MYPRINTERINFO_H

#include <QObject>

class myPrinterInfo : public QObject
{
    Q_OBJECT
public:
    explicit myPrinterInfo(QObject *parent = 0);

signals:

public slots:
};

#endif // MYPRINTERINFO_H