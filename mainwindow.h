#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum format{
    EUROPEAN,
    AMERICAN,
    ISO
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void updateHour();    
    void on_timerButton_clicked();
    void updateLabel(int hour=0, int minutes=0, int seconds=0);
    void startTimer();
    void updateTimeVariables();
    void on_timeEdit_timeChanged();
    void on_pushButton_clicked();
    void on_changeTimeFormat_clicked();
    void on_dateFormat_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;
    int hour, minutes, seconds;
    bool timerStarted = false;
    bool stopButton = false;
    bool amPm = false;
    format formatStatus = EUROPEAN;
    QString timeEditLabel;


};


#endif // MAINWINDOW_H
