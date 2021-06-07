#include "stringGenerator.h"
#include "QString"
#include "QException"
#include "exception"


QString stringGenerator::labelString(int hour, int minutes, int seconds, QString &string){
    string.clear();


        if(hour < 10){
            string.append(QString::number(0));
            string.append(QString::number(hour));
        }
        else{
            string.append(QString::number(hour));
        }


        string.append(":");

        if(minutes <10){
            string.append(QString::number(0));
            string.append(QString::number(minutes));
        }
        else{
            string.append(QString::number(minutes));
        }
        string.append(":");
        if(seconds<10){
            string.append(QString::number(0));
            string.append(QString::number(seconds));
        }
        else{
            string.append(QString::number(seconds));

    }
    return string;
}
