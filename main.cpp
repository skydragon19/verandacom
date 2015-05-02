#include <QCoreApplication>
#include <QtCore/QCoreApplication>

#include <model/init_mysql.h>
#include <model/init_memory.h>

#include <controller/worker.h>

#include <util/utama.h>

extern struct utama marine;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    printf("VERANDA PARSER - MANUAL RECORD DATA\n");
    printf("Version    : 1.0\n");
    printf("Release    : \n");
    printf("Develop by : Design Dept. - PT. Daunbiru Engineering\n\n");

    printf("System Initialization . . .\n\n");

    init_mysql mysql;
    init_memory memory;
    Worker work;

    return a.exec();
}
