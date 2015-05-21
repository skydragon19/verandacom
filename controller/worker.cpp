#include "worker.h"

extern struct utama marine;
extern struct global glo;

Worker::Worker(QObject *parent) : QObject(parent){
    cnt_id = 0;
    this->line_command();
}

void Worker::sedot_data_kapal(int id_ship, QString startUTC, QString endUTC){
    this->request_data_kapal(id_ship, startUTC, endUTC);
}

void Worker::sedot_data_semuanya(QString startUTC, QString endUTC){
    StartUTCs = startUTC;
    EndUTCs = endUTC;

    this->request_data_semuanya(startUTC, endUTC);
}

void Worker::request_data_semuanya(QString startUTC, QString endUTC){
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(allreplyFinished(QNetworkReply*)));

    QNetworkRequest request;

    SIN = marine.kapal[cnt_id].SIN;
    MIN = marine.kapal[cnt_id].MIN;

    printf("\n>> URL :\n");
    urls.sprintf("%s/get_return_messages.xml/?access_id=%s&password=%s&start_utc=%s&end_utc=%s&mobile_id=%s",
                 marine.kapal[cnt_id].gateway, marine.kapal[cnt_id].access_id, marine.kapal[cnt_id].password,
                 startUTC.toLocal8Bit().data(), endUTC.toLocal8Bit().data(), marine.kapal[cnt_id].modem_id);

    printf("%s", urls.toLocal8Bit().data());

    QUrl url =  QUrl::fromEncoded(urls.toLocal8Bit().data());
    request.setUrl(url);
    manager->get(request);
}

void Worker::request_data_kapal(int id_ship, QString startUTC, QString endUTC){
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply *)));

    QNetworkRequest request;

    id_s = id_ship;

    SIN = marine.kapal[id_ship-1].SIN;
    MIN = marine.kapal[id_ship-1].MIN;

    printf("\n>> URL :\n");
    urls.sprintf("%s/get_return_messages.xml/?access_id=%s&password=%s&start_utc=%s&end_utc=%s&mobile_id=%s",
                 marine.kapal[id_ship-1].gateway, marine.kapal[id_ship-1].access_id, marine.kapal[id_ship-1].password,
                 startUTC.toLocal8Bit().data(), endUTC.toLocal8Bit().data(), marine.kapal[id_ship-1].modem_id);

    printf("%s", urls.toLocal8Bit().data());

    QUrl url =  QUrl::fromEncoded(urls.toLocal8Bit().data());
    request.setUrl(url);
    manager->get(request);
}

void Worker::replyFinished(QNetworkReply* reply){
    printf("\nreplied");

    QString readAll = reply->readAll();
    read->readShip_SkyWave(glo.db, readAll, SIN, MIN, id_s);

    printf("\n\nEnd of Data\n");
    this->line_command();
}

void Worker::allreplyFinished(QNetworkReply *reply){
    printf("\nreplied");

    QString readAll = reply->readAll();
    read->readShip_SkyWave(glo.db, readAll, SIN, MIN, marine.kapal[cnt_id].id_ship);
    printf("\n\nEnd of Data\n");

    cnt_id++;

    if(cnt_id < marine.total){
        this->request_data_semuanya(StartUTCs, EndUTCs);
    }
    else{
        cnt_id = 0;
        this->line_command();
    }
}

/*-----------------------------------------------------------------------------------------------*/
/*                                       COMMAND FUNCTION                                        */
/*-----------------------------------------------------------------------------------------------*/
void Worker::line_command(){
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString command ="";

    printf("\n$marine.veranda : ");
    //cin >> command;
    command = cin.readLine();

    if (command == "help"){
        this->help_command();
    }
    else if (command == "download" || command == "download "){
        this->download_single_ship();
    }
    else if (command == "download all" || command == "download all "){
        this->download_all_ship();
    }
    else if (command == "show ship" || command == "show ship "){
        this->ship_list();
        this->line_command();
    }
    else if(command == "clear" || command == "clear "){
        this->clear_screen();
    }
    else if(command == "exit" || command == "exit "){
        this->exit();
    }
    else if(command == ""){
        this->line_command();
    }
    else{
        printf("\nWrong command, type 'help' to show available command\n");
        this->line_command();
    }
}

void Worker::help_command(){
    printf("\nCommand Help :\n");;
    printf(" show ship    -- Show available ship\n");
    printf(" download     -- Download singgle ship data\n");
    printf(" download all -- Download all ship data\n");

    this->line_command();
}

void Worker::ship_list_command(){
    this->ship_list();
    this->line_command();
}

void Worker::download_single_ship(){
    QTextStream cin(stdin);
    QString id;

    QString date, time, StartUTC, EndUTC;
    int id_ship;

    this->ship_list();

    printf("\nSelect ID     :  ");
    cin >> id;
    id_ship = id.toInt();

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nStart UTC     :  ");
    cin >> date >> time;
    StartUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nEnd UTC       :  ");
    cin >> date >> time;
    EndUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());

    this->sedot_data_kapal(id_ship, StartUTC, EndUTC);
}

void Worker::download_all_ship(){
    QTextStream cin(stdin);

    QString date, time, StartUTC, EndUTC;

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nStart UTC     :  ");
    cin >> date >> time;
    StartUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());

    printf("\nInsert DateTime [yyyy-MM-dd hh:mm:ss]");
    printf("\nEnd UTC       :  ");
    cin >> date >> time;
    EndUTC.sprintf("%s %s", date.toLocal8Bit().data(), time.toLocal8Bit().data());

    this->sedot_data_semuanya(StartUTC, EndUTC);
}

void Worker::ship_list(){
    printf("\nAvailable Ship :\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("    ID   |     Status    |        Mobile ID      |          Ship Name          \n");
    printf("-------------------------------------------------------------------------------\n");

    for (int i = 0; i < marine.total; i++){
        if (i < 9){
            printf("    %d    |       %d       |    %s    |   %s \n", i+1, marine.kapal[i].status, marine.kapal[i].modem_id, marine.kapal[i].name);
        }
        else{
            printf("    %d   |       %d       |    %s    |   %s \n", i+1, marine.kapal[i].status, marine.kapal[i].modem_id, marine.kapal[i].name);
        }
    }
}

void Worker::clear_screen(){
    system("clear");
    this->line_command();
}

void Worker::exit(){
    system("exit");
    this->line_command();
}
