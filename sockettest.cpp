#include "sockettest.h"
#include <iostream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <QVariant>
#include <QDebug>


SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("127.0.0.1", 8080);

    if(socket->waitForConnected(3000))
        qDebug() << "Connected!";
    else
        qDebug() << "Not connected!";
    chat();
    socket->close();
}

void SocketTest::chat()
{


//    qDebug() << "Msg ";
    std::cout << "Enter values\n" ;
    std::string str;
    std::getline(std::cin, str);
    QString qString(str.c_str());

    socket->write(qString.toLocal8Bit());
    socket->waitForBytesWritten(1000);
    socket->waitForReadyRead(3000);

    qDebug() << "Reading: " << socket->bytesAvailable();

    QByteArray responseBytes =  socket->readAll();

    /* QString val= QString(responseBytes);
        QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());

        QJsonObject sett2 = d.object();
        QJsonValue nom = sett2.value(QString("nom"));
        QJsonValue age = sett2.value(QString("age"));
        QJsonValue value = sett2.value(QString("list"));*/

    qDebug() << responseBytes;
    /*  qDebug() << nom.toString();
        qDebug() << age.toString();
        qDebug() << value.toArray();

        QJsonArray test = value.toArray();
        qDebug() << test[1];
        qDebug() << test[2];
        qDebug() << test[0];*/


}
