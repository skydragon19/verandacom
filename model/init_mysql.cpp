#include "init_mysql.h"

struct global glo;

init_mysql::init_mysql()
{
    glo.db = connect_db();
}

QSqlDatabase init_mysql::connect_db(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("marine_1");
    db.setUserName("root");
    db.setPassword("rqi");

    if(!db.open()){
        printf("::Database Connection                                                    [FAIL]\n");
    }
    else{
        printf("::Database Connection                                                    [DONE]\n");
    }

    return (QSqlDatabase) db;
}
