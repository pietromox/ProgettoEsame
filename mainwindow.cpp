#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include "QTimer"
#include "QTime"
#include "QTimeEdit"
#include "QMainWindow"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);


    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateHour()));

    timer->start(1000);

    timer2 = new QTimer(this);
    QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(startTimer()));

    ui->date->setText(QDate::currentDate().toString("dd.MM.yy"));


}


//VARIABILI GLOBALI
int hour, minutes, seconds;
bool timerStarted = false;
//

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::updateHour()
{
    ui->displayedTime->setText(QTime::currentTime().toString("hh:mm:ss"));
}




void MainWindow::updateLabel(int hour, int minutes, int seconds){
    QString string;
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
    ui->timer->setText(string);

}

void MainWindow::startTimer(){
    timerStarted = true;
    if(hour == 0 && minutes == 0 && seconds == 0){
        timerStarted=false;
        timer2->stop();
        updateLabel(0,0,0);
        return;
    }
    if(seconds==0 && minutes==0){
        updateLabel(hour-1, minutes, seconds);
        hour=hour-1;
        minutes = 60;


    }
    if(seconds ==0){
        seconds = 60;

        updateLabel(hour, minutes, seconds-1);
        minutes = minutes-1;

    }

    updateLabel(hour, minutes, seconds-1);
     seconds = seconds-1;
    timer2->start(1000);


}


void MainWindow::on_timerButton_clicked()
{
if(timerStarted==false){
    updateStaticVariables();
    startTimer();
}
else
    return;


}

void MainWindow::updateStaticVariables(){
    hour = ui->timeEdit->time().hour();
    minutes = ui->timeEdit->time().minute();
    seconds = ui->timeEdit->time().second();
}

void MainWindow::on_timeEdit_timeChanged()
{
    updateLabel(ui->timeEdit->time().hour(), ui->timeEdit->time().minute(), ui->timeEdit->time().second());
   updateStaticVariables();
}



void MainWindow::on_pushButton_clicked()
{
    updateLabel();
    timer2->stop();
    updateStaticVariables();
    seconds++;
    timerStarted = false;

}
