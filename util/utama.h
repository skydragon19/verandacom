#ifndef UTAMA_H
#define UTAMA_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#include <iostream>
#include <stdio.h>
#include <QTextStream>

#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

struct global{
    QSqlDatabase db;
};

struct ship{
    int  id_ship;
    char name[64];
    char modem_id[64];
    char access_id[64];
    char password[64];
    int  SIN;
    int  MIN;
    char gateway[128];
    int  status;
};

struct utama{
    int  total;
    struct ship kapal[50]; /* masih hardoce untuk alokasi 50 kapal */
};

#endif // UTAMA_H
