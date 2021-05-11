#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    void updateStaticVariables();
    void on_timeEdit_timeChanged();




    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer2;


};
#endif // MAINWINDOW_H
