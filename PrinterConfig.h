#ifndef PRINTERCONFIG_H
#define PRINTERCONFIG_H

#include <QObject>

class PrinterConfig : public QObject
{
    Q_OBJECT
public:
    explicit PrinterConfig(QObject *parent = 0);

signals:

public slots:
};

#endif // PRINTERCONFIG_H