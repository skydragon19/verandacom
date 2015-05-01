#ifndef GET_DB_H
#define GET_DB_H

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>


class get_db
{
public:
    get_db();

    int sum_ship(QSqlDatabase db);
    int id_tu_ship(QSqlDatabase db, int id_ship, int urutan);

    QString type_data(QSqlDatabase db, int id_tu);
};

#endif // GET_DB_H
