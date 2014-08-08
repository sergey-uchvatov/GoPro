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

    status["bacpac/se"]["power"]          = getSection(18, 2, {
                                                   {"00", "Off"},
                                                   {"01", "On"}
                                               });

    status["camera/se"]["batt1"]          = getSection(38, 2, {});

    status["camera/sx"]["mode"]           = getSection(2, 2, {
                                                  {"00", "video"},
                                                  {"01", "still"},
                                                  {"02", "burst"},
                                                  {"03", "timer"},
                                                  {"07", "settings"}
                                              });

    status["camera/sx"]["fov"]            = getSection(14, 2, {
                                                 {"00", "170"},
                                                 {"01", "127"},
                                                 {"02", "90"}
                                             });

    status["camera/sx"]["picres"]         = getSection(17, 1, {
                                                    {"3", "5MP med"},
                                                    {"6", "7MP med"},
                                                    {"4", "7MP wide"},
                                                    {"5", "12MP wide"}
                                                });

    status["camera/sx"]["vidres"]         = getSection(100, 2, {
                                                    {"00", "WVGA"},
                                                    {"01", "720p"},
                                                    {"02", "960p"},
                                                    {"03", "1080p"},
                                                    {"04", "1440p"},
                                                    {"05", "2.7K"},
                                                    {"06", "2.7KCin"},
                                                    {"07", "4K"},
                                                    {"08", "4KCin"}

                                                });

    status["camera/sx"]["fps"]            = getSection(102, 2, {
                                                    {"00", "12"},
                                                    {"01", "15"},
                                                    {"02", "24"},
                                                    {"03", "25"},
                                                    {"04", "30"},
                                                    {"05", "48"},
                                                    {"06", "50"},
                                                    {"07", "60"},
                                                    {"08", "100"},
                                                    {"09", "120"},
                                                    {"10", "240"}
                                                });

    status["camera/sx"]["secselapsed"]    = getSection(26, 4, {});

    status["camera/sx"]["orientation"]    = getSection(37, 1, {
                                                         {"0", "up"},
                                                         {"4", "down"}
                                                     });

    status["camera/sx"]["charging"]       = getSection(39, 1, {
                                                      {"3", "no"},
                                                      {"4", "yes"}
                                                  });

    status["camera/sx"]["mem"]            = getSection(42, 4, {});
    status["camera/sx"]["npics"]          = getSection(46, 4, {});
    status["camera/sx"]["minsremaining"]  = getSection(50, 4, {});
    status["camera/sx"]["nvids"]          = getSection(54, 4, {});
    status["camera/sx"]["batt2"]          = getSection(90, 2, {});

    status["camera/sx"]["charging"]       = getSection(60, 2, {
                                                      {"05", "on"},
                                                      {"04", "off"}
                                                  });

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
    if(cameraAvailable()) {
        reply = httpManager.get(QNetworkRequest(makeUrl(command)));

        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(statusError(QNetworkReply::NetworkError)));
        connect(reply, SIGNAL(finished()), this, SLOT(statusFinished()));
    }

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

GoproController::Section GoproController::getSection(int startByte, int length, QMap<QString, QString> translate){
    Section temp;
    temp.startByte = startByte;
    temp.length = length;
    temp.translate = translate;
    return temp;
}


