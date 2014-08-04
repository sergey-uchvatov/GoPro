#include "goprocontroller.h"
#include <QtCore/QCoreApplication>
#include <QtNetwork>


GoproController* GoproController::getInstance()
{
    static GoproController * singleton = new GoproController();
    return singleton;
}

GoproController::GoproController(QObject *parent)
    : QObject(parent)
{
    setIp("10.5.5.9");
    setPassword("12345678");
}

QUrl GoproController::makeUrl(QString command, QString value = "")
{
    QString url = "http://"+_ip+"/";
    url += command;
    url += "?t="+_password;
    if (!value.isEmpty()) url += "&p="+value;

    return QUrl(url);
}


void GoproController::setIp(QString ip)
{
    _ip = ip;
}

void GoproController::setPassword(QString password)
{
    _password = password;
}

bool GoproController::cameraAvailable() {
    int exitCode = QProcess::execute("ping", QStringList() << "-c1" << _ip);
    if (0 == exitCode) {
        return true;
    }

    return false;
}

void GoproController::getStatus(QString command) {

    reply = httpManager.get(QNetworkRequest(makeUrl(command)));
    qDebug() << makeUrl(command);

    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(statusError(QNetworkReply::NetworkError)));
    connect(reply, SIGNAL(finished()), this, SLOT(statusFinished()));
}
void GoproController::statusError(QNetworkReply::NetworkError error)
{
    qDebug() << reply->errorString();
}

void GoproController::statusFinished()
{
    QByteArray content= reply->readAll();
//    QTextCodec *codec = QTextCodec::codecForName("cp1251");

    qDebug() << content.toHex().mid(18, 2);
}

void GoproController::cameraOn()
{
    getStatus("bacpac/se");
    httpManager.get(QNetworkRequest(makeUrl("bacpac/PW", "%01")));

//    qDebug() << codec->toUnicode(content.data());
//    qDebug() << getStatus("bacpac/PW");

}

void GoproController::cameraOff()
{
    QNetworkReply *reply = httpManager.get(QNetworkRequest(makeUrl("bacpac/PW", "%00")));
    QByteArray content= reply->readAll();
    QTextCodec *codec = QTextCodec::codecForName("cp1251");

    qDebug() << codec->toUnicode(content.data());


}

void GoproController::recordOn()
{


}

void GoproController::recordOff()
{

}

void GoproController::modeVideo()
{

}

void GoproController::modeStill()
{

}
