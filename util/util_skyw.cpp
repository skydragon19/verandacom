#include "util_skyw.h"

util_skyw::util_skyw(QObject *parent) :
    QObject(parent)
{
}

void util_skyw::readShip_SkyWave(QSqlDatabase db, QString xml_read, int SIN, int MIN, int id_ship)
{
#if 1
    int cnt = 0;
    int cnt_tu = 0;

    int epochtime;
    QString date_time;
    QString MessageUTC;

    int sin_xml;
    int min_xml;
    QString name_xml;

    QXmlStreamReader xml;
    QSqlQuery q(db);

    xml.clear();
    xml.addData(xml_read);

    while(!xml.atEnd() &&  !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();
        if(token == QXmlStreamReader::StartElement) {
            if (xml.name() == "MessageUTC"){
                MessageUTC = xml.readElementText();
                printf("\n\n MessageUTC     : %s", MessageUTC.toLocal8Bit().data());
            }
            if (xml.name() == "SIN"){
                sin_xml = xml.readElementText().toInt();
                printf("\n SIN            : %d", sin_xml);
            }
            if (xml.name() == "MobileID"){
                printf("\n MobileID       : %s", xml.readElementText().toLocal8Bit().data());
            }
            if (xml.name() == "Payload"){
                QXmlStreamAttributes attribute = xml.attributes();
                name_xml = attribute.value("Name").toString();
                sin_xml  = attribute.value("SIN").toString().toInt();
                min_xml  = attribute.value("MIN").toString().toInt();
            }

            if (sin_xml == SIN){
            /* isatdatapro */
                if (name_xml == "PesanCijolang" && sin_xml == SIN && min_xml == MIN){
                    if (xml.name() == "Fields"){
                        cnt = 0;
                        cnt_tu = 0;
                    }
                    if (xml.name() == "Field"){
                        QXmlStreamAttributes attributes = xml.attributes();
                        int value = attributes.value("Value").toString().toInt();
                        QString name = attributes.value("Name").toString();

                        float data_f = *(float *) &value;

                        if (cnt == 0){
                            epochtime = (int) data_f;

                            const QDateTime time = QDateTime::fromTime_t((int)data_f);
                            date_time = time.toString("yyyy-MM-dd hh:mm:ss").toLocal8Bit().data();

                            printf("\n                waktu  : %s [%s]", date_time.toLocal8Bit().data(), name.toLocal8Bit().data());
                            cnt = 1;
                        }
                        else{
                            cnt_tu++;
                            int id_tu = get.id_tu_ship(db, id_ship, cnt_tu);

                            if (id_tu != 0){
                                QString type = get.type_data(db, id_tu);
                                printf("\n                 %d   : %.2f [%s]", id_tu, data_f, type.toLocal8Bit().data());

                                save.data(db, data_f, id_tu, 0, epochtime, date_time);
                            }
                        }
                    }
                }
                /* m2prime */
                if (xml.name() == "RawPayload"){
                    QString decode = parse.decode_base64(xml.readElementText());
                    QString bin = parse.hex_to_bin_conversion(decode);
                    QString f_5c32g = parse.format_5cut_32get(bin);
                    parse.read_data(db, f_5c32g, id_ship);
                }
            }
        }
    }
#endif
}
