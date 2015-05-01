#ifndef COMMAND_H
#define COMMAND_H

#include <util/utama.h>

class commandos
{
public:
    commandos();

    void line_command();
    void help_command();
    void unknwon_command();

    void ship_list_command();
    void download_single_ship();
    void download_all_ship();

    void ship_list();

    int check_id();
    QString check_startdatetime();
    QString check_enddatetime();
};

#endif // COMMAND_H
