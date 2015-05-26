#ifndef VERJSON_H
#define VERJSON_H

#include "util/utama.h"

class verjson
{
public:
    verjson();

    void json_lastpos(int id_ship, QString lat, QString lng);
    QString get_lat(float lat, QString slat);
    QString get_lng(float lng, QString slng);

    QString json_daily(int id_ship, QString js, QString append);
    QString get_time_data(QString time, QString type);
    QString get_data_per_type(QString js, float df, QString type);
    QString amplop(QString data, int id_ship, QString mobile_id);
};

#endif // VERJSON_H
