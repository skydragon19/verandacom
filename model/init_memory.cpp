#include "init_memory.h"

extern struct global glo;
struct utama marine;

init_memory::init_memory()
{
    this->set_memory_for_ship();
}

void init_memory::set_memory_for_ship(){
    QSqlQuery q(glo.db);
    int i = 0;

    q.prepare("SELECT s.id_ship, s.name, s.modem_id, s.access_id, s.password, s.SIN, s.MIN, g.url, s.status FROM ship s join gateway g on g.id = s.gateway");
    if(!q.exec()){
        printf("::Memmory Allocation                                                      [FAIL]\n");
        printf("EXIT PROGRAM!!\n");
    }
    else{
        while(q.next()){
            if (q.value(2).toString().size() == 15){
                marine.kapal[i].id_ship = q.value(0).toInt();
                strcpy(marine.kapal[i].name, q.value(1).toString().toLatin1());
                strcpy(marine.kapal[i].modem_id, q.value(2).toString().toLatin1());
                strcpy(marine.kapal[i].access_id, q.value(3).toString().toLatin1());
                strcpy(marine.kapal[i].password, q.value(4).toString().toLatin1());
                marine.kapal[i].SIN = q.value(5).toInt();
                marine.kapal[i].MIN = q.value(6).toInt();
                strcpy(marine.kapal[i].gateway, q.value(7).toString().toLatin1());
                marine.kapal[i].status = q.value(8).toInt();

                i++;
            }
        }
        marine.total = i;
        printf("::Memmory Allocation                                                     [DONE]\n");
    }
}
