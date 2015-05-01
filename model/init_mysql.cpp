#include "init_mysql.h"

struct global glo;

init_mysql::init_mysql()
{
    glo.db = connect_db();
}

QSqlDatabase init_mysql::connect_db(){
    QString pth = "veranda_set.ini";
    QSettings sett(pth, QSettings::IniFormat);

    QString host = sett.value("hostname").toString();
    QString dbname = sett.value("databasename").toString();
    QString user = sett.value("username").toString();
    QString password = sett.value("password").toString();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(host);
    db.setDatabaseName(dbname);
    db.setUserName(user);
    db.setPassword(password);

    if(!db.open()){
        printf("::Database Connection                                                    [FAIL]\n");
    }
    else{
        printf("::Database Connection                                                    [DONE]\n");
    }

    return (QSqlDatabase) db;
}
