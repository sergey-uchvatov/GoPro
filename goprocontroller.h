#ifndef GOPROCONTROLLER_H
#define GOPROCONTROLLER_H

#include <QString>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>


class GoproController : public QObject
{
Q_OBJECT

public:
    static GoproController* getInstance();
    explicit GoproController(QObject *parent = 0);

    void cameraOn();
    void cameraOff();
    void recordOn();
    void recordOff();

    void modeVideo();
    void modeStill();

    bool cameraAvailable();

private:
    QNetworkReply *reply;

    QString _ip,
         _password,
         _device,
         _command,
         _app;

    QUrl makeUrl(QString command, QString value);
    void getStatus(QString command);

    void setIp(QString ip);
    void setPassword(QString password);
    void setCommand(QString command);


    QNetworkAccessManager httpManager;

private slots:
    void statusFinished();
    void statusError(QNetworkReply::NetworkError error);

};

//'http://<ip>/<device>/<app>?t=<password>&p=<command>'
#endif // GOPROCONTROLLER_H
