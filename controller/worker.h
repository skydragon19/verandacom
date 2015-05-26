#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QProcess>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QXmlStreamReader>
#include <QSqlQuery>

#include "util/util_skyw.h"
#include "util/utama.h"

#include "model/get_db.h";
#include "model/init_mysql.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    QXmlStreamReader xml;

    void sedot_data_kapal(int id_ship, QString startUTC, QString endUTC);
    void sedot_data_semuanya(QString startUTC, QString endUTC);

signals:
    
public slots:

private slots:
    void replyFinished(QNetworkReply* reply);
    void allreplyFinished(QNetworkReply* reply);

    void request_data_kapal(int id_ship, QString startUTC, QString endUTC);
    void request_data_semuanya(QString startUTC, QString endUTC);

    void line_command();
    void help_command();
    void ship_list_command();
    void download_all_ship();
    void download_single_ship();
    void ship_list();

    void clear_screen();
    void exit();

private:
    QTimer timer;
    util_skyw *read;
    get_db *get;

    //commandos cmd;

    int idx_ship;
    int sum_ship;
    int cek_replay;

    int ship_count;
    int count;

    QString urls;

    int xml_ver;

    QSqlDatabase db;

    void get_modem_info();

    int SIN;
    int MIN;

    int id_s;

    int cnt_id;
    QString StartUTCs;
    QString EndUTCs;
};

#endif // TIMER_H
