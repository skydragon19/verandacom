#ifndef UTIL_SKYW_H
#define UTIL_SKYW_H

#include <QObject>
#include <QXmlStreamReader>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>

#include <model/get_db.h>
#include <model/save_db.h>
#include <model/json/verjson.h>

#include <util/parsing_fuction.h>
#include <util/utama.h>

class util_skyw : public QObject
{
    Q_OBJECT
public:
    explicit util_skyw(QObject *parent = 0);
    void readShip_SkyWave(QSqlDatabase db, QString xml_read, int SIN, int MIN, int id_ship);

signals:
    
public slots:

private:
    get_db get;
    save_db save;
    parsing_function parse;
    verjson vjson;

};

#endif // UTIL_SKYW_H
