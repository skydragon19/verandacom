#include "verjson.h"

extern struct utama marine;

verjson::verjson()
{
}


void verjson::json_lastpos(int id_ship, QString lat, QString lng){
    QString out;

    out.sprintf("{'success':true,'posisi':[{'id':'%d',%s,%s}]}",id_ship, lat.toLocal8Bit().data(), lng.toLocal8Bit().data());

    QString redis;

    redis.sprintf("redis-cli set marine.%s_lastPost %c%s%c", marine.kapal[id_ship-1].modem_id, '"', out.toLocal8Bit().data(), '"');

    system(redis.toLocal8Bit());
}

QString verjson::get_lat(float lat, QString slat){
    QString out;

    out.sprintf("'%s':'%f'", slat.toLocal8Bit().data(), lat);
    return (QString) out;

}

QString verjson::get_lng(float lng, QString slng){
    QString out;

    out.sprintf("'%s':'%f'", slng.toLocal8Bit().data(), lng);
    return (QString) out;

}

/* ===================================================================================================================== */

QString verjson::json_daily(int id_ship, QString js, QString append){
    QString out;
    QString redis;

    if (js == ""){
        return (QString) "";
    }
    else{
        out.sprintf("%s%s", js.toLocal8Bit().data(), append.toLocal8Bit().data());

        redis.sprintf("redis-cli set marine.%s_dailyRecord %c{'success':true,'detail_ship':[%s]}%c", marine.kapal[id_ship-1].modem_id, '"', out.toLocal8Bit().data(), '"');
        system(redis.toLocal8Bit());

        out = ","+out;
        return (QString) out;
    }
}

QString verjson::get_time_data(QString time, QString type){
    QString out;
    out.sprintf("'%s':'%s'", type.toLocal8Bit().data(), time.toLocal8Bit().data());

    return (QString) out;
}

QString verjson::get_data_per_type(QString js, float df, QString type){
    QString out;
    out.sprintf("%s,'%s':'%f'",
                js.toLocal8Bit().data(), type.toLocal8Bit().data(), df);

    return (QString) out;
}

QString verjson::amplop(QString data, int id_ship, QString mobile_id){
    QString out;
    out.sprintf("{%s,'kapal':'%d'','modem':'%s'}",
                data.toLocal8Bit().data(), id_ship, mobile_id.toLocal8Bit().data());

    return (QString) out;
}
