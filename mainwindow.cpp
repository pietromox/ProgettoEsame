
#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include "QTimer"
#include "QTime"
#include "QTimeEdit"
#include "QMainWindow"
#include "stringGenerator.h"

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


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::updateHour()
{
    if(!amPm){
        ui->displayedTime->setText(QTime::currentTime().toString("hh:mm:ss"));
        ui->amPmLabel->setText("");
    }
    else{

        ui->displayedTime->setText(QTime::currentTime().toString("hh:mm:ss ap"));
        if(QTime::currentTime().hour()<=12){
            ui->amPmLabel->setText("AM");
        }
        else
        {
            ui->amPmLabel->setText("PM");
        }

    }
}





void MainWindow::updateLabel(int hour, int minutes, int seconds){

    ui->timer->setText(stringGenerator::labelString(hour, minutes, seconds, timeEditLabel));

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

    if(stopButton==false){
        if(!timerStarted){
            updateTimeVariables();
        }
        timerStarted = true;
        ui->timerButton->setText("STOP");
        timer2->start(1000);
        stopButton = true;
        startTimer();
    }
    else{
        timer2->stop();
        stopButton = false;
        ui->timerButton->setText("START");
        return;
    }



}

void MainWindow::updateTimeVariables(){
    hour = ui->timeEdit->time().hour();
    minutes = ui->timeEdit->time().minute();
    seconds = ui->timeEdit->time().second();
}

void MainWindow::on_timeEdit_timeChanged()
{
    updateLabel(ui->timeEdit->time().hour(), ui->timeEdit->time().minute(), ui->timeEdit->time().second());
    updateTimeVariables();
}



void MainWindow::on_pushButton_clicked()
{
    updateLabel();
    timer2->stop();
    updateTimeVariables();
    seconds++;
    timerStarted = false;
    stopButton = false;
    ui->timerButton->setText("START");

}

void MainWindow::on_changeTimeFormat_clicked()
{
    if(!amPm){
        amPm = true;
        ui->changeTimeFormat->setText("24h");
    }
    else{
        ui->changeTimeFormat->setText("AM/PM");
        amPm = false;
    }


}

void MainWindow::on_dateFormat_clicked()
{
    switch(formatStatus){
    case format::EUROPEAN:
        formatStatus = format::AMERICAN;
        ui->date->setText(QDate::currentDate().toString("MM:dd:yyyy"));
        ui->dateFormat->setText("passa al formato ISO");
        break;
    case format::AMERICAN:
        formatStatus= format::ISO;
        ui->date->setText(QDate::currentDate().toString("yyyy:MM:dd"));

        ui->dateFormat->setText("passa al formato standard");
        break;
    case format::ISO:
        formatStatus= format::EUROPEAN;
        ui->date->setText(QDate::currentDate().toString("dd.MM.yy"));
        ui->dateFormat->setText("passa al formato americano");
        break;
    }
}

