#include "command.h"

struct commands com;
extern struct global glo;
extern struct utama marine;

commandos::commandos()
{
    this->line_command();
}

void commandos::line_command(){
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString command;

    printf("\n$marine.veranda : ");
    cin >> command;

    if(command == "help"){
        this->help_command();
    }
    else if(command == "show_ship"){
        this->ship_list_command();
    }
    else if(command == "download_all_ship"){

    }
    else if(command == "download_single_ship"){
        this->download_single_ship();
    }
    else{
        printf("Wrong command, type 'help' to show available command");
        this->line_command();
    }
}

void commandos::help_command(){
    printf("\nCommand Help :\n");
    printf("show_ship                  -- Show available ship\n");
    printf("download_all_ship          -- Download all ship on database\n");
    printf("download_single_ship       -- Download one ship on database\n");
    printf("read_ship_data             -- Show data from one ship (not storing to database\n");

    this->line_command();
} 

void commandos::ship_list_command(){
    this->ship_list();
    this->line_command();
}

void commandos::download_single_ship(){
    QTextStream cin(stdin);
    QString id;

    QString date, time, StartUTC, EndUTC;
    int id_ship;

    this->ship_list();

    printf("\nSelect ID     :  ");
    cin >> id;
    id_ship = id.toInt();
    com.id_ship = id_ship;

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nStart UTC     :  ");
    cin >> date >> time;
    StartUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());
    strcpy(com.startutc, StartUTC.toLatin1());

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nEnd UTC       :  ");
    cin >> date >> time;
    EndUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());
    strcpy(com.endutc, EndUTC.toLatin1());
}

void commandos::ship_list(){
    printf("\nAvailable Ship :\n");
    printf("------------------------------------------------------------------------------\n");
    printf("    ID   |        Mobile ID          |                Ship Name               \n");
    printf("------------------------------------------------------------------------------\n");

    for (int i = 0; i < marine.total; i++){
        printf("    %d    | %s           | %s \n", i+1, marine.kapal[i].modem_id, marine.kapal[i].name);
    }
}

QString commandos::check_startdatetime(){
    QTextStream cin(stdin);
    QString date, time, datetime;

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nStart UTC     :  ");
    cin >> date >> time;

    datetime.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());

    char dtime[datetime.size()+1];
    strcpy(dtime, datetime.toLatin1());

    if (date.size() != 10 || time.size() != 8){

        this->check_startdatetime();
    }
    else{
        for(int i = 0; i < datetime.size(); i++){
            if (i < 4 || (i > 4 && i < 7) || (i > 7 && i < 10) || (i > 10 && i < 13) || (i > 13 && i < 16) || (i > 16)){
                if (dtime[i] != '0' || dtime[i] != '1' || dtime[i] != '2' || dtime[i] != '3' || dtime[i] != '4' ||
                    dtime[i] != '5' || dtime[i] != '6' || dtime[i] != '7' || dtime[i] != '8' || dtime[i] != '9'){
                    this->check_startdatetime();
                }
            }
            if (i == 5 || i == 8 ){
                if (dtime[i] != '-'){
                    this->check_startdatetime();
                }
            }
            if (i == 10){
                if (dtime[i] != ' '){
                    this->check_startdatetime();
                }
            }
            if (i == 13 || i == 16){
                if (dtime[i] != ':'){
                    this->check_startdatetime();
                }
            }
        }
        return (QString) datetime;
    }
}
