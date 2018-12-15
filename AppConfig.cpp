#include "AppConfig.h"
#include <QFile>
#include <QDataStream>
#include <QApplication>
#include <QByteArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QMessageBox>
#include <QDebug>

AppConfig::AppConfig(QObject *parent) : QObject(parent)
{
    load();
}
bool AppConfig::load()
{
    bool ret = true;

    QString path = QApplication::applicationDirPath() + "/config.json";

    QFile file(path);

    if(file.open(QIODevice::ReadOnly))
    {

        QString configJson = file.readAll();

        if(!jsonParse(configJson))
        {
            ret = false;
            QMessageBox::critical(0,"错误","读取配置文件失败！",QMessageBox::Ok);
        }

        file.close();
    }

    return ret;
}

bool AppConfig::jsonParse(QString strResult)
{
    bool ret = true;
    QString str = "default";
    QString buf = strResult;
    QByteArray data = buf.toUtf8();

    QJsonParseError jsonError;//Qt5新类
    QJsonDocument json = QJsonDocument::fromJson(data, &jsonError);//Qt5新类
    if (jsonError.error == QJsonParseError::NoError)
    {
        if (json.isObject())
        {
            QJsonObject rootObj = json.object();
            //是否含有key  printer1
            if(rootObj.contains("printer1"))
            {
                QJsonValue value = rootObj.value("printer1");
                //判断是否是string类型
                if (value.isString())
                {
                    m_printer1 = value.toString();
                    str = "ok";
                }
            }

            //是否含有key  port
            if(rootObj.contains("printer2"))
            {
                QJsonValue value = rootObj.value("printer2");
                if (value.isString())
                {
                    m_printer2 = value.toString();
                    str = "ok";
                }
            }
            //是否含有key  port
            if(rootObj.contains("printer3"))
            {
                QJsonValue value = rootObj.value("printer3");
                if (value.isString())
                {
                    m_printer3 = value.toString();
                    str = "ok";
                }
            }
            //是否含有key  port
            if(rootObj.contains("printer4"))
            {
                QJsonValue value = rootObj.value("printer4");
                if (value.isString())
                {
                    m_printer4 = value.toString();
                    str = "ok";
                }
            }
            if(rootObj.contains("printer5"))
            {
                QJsonValue value = rootObj.value("printer5");
                if (value.isString())
                {
                    m_printer5 = value.toString();
                    str = "ok";
                }
            }

        }else{
            str = "json is not object";
            ret = false;
        }
    }
    qDebug() << str;
    return ret;
}

