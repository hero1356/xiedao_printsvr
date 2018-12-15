#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>

class AppConfig : public QObject
{
    Q_OBJECT

    QString m_printer1;
    QString m_printer2;
    QString m_printer3;
    QString m_printer4;
    QString m_printer5;
public:
    explicit AppConfig(QObject *parent = 0);

    bool load();
    bool jsonParse(QString strResult);

    QString printer1() {return m_printer1; }
    QString printer2() {return m_printer2;}
    QString printer3() {return m_printer3;}
    QString printer4() {return m_printer4;}
    QString printer5() {return m_printer5;}

};

#endif // APPCONFIG_H
