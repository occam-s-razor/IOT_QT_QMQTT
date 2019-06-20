#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHostAddress>
#include "gateway.h"
#include <QTextEdit>
#include <QLabel>
#include "uarttest.h"
#include <QtMqtt/QMqttClient>
//#include "processImage.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    gateway *sendjson;
    gateway *tranjson;
private slots:
    void on_pushButton_clicked();
    void display_send(QString msg,QString topic);
    void play_video();
    void uart_display(char str);
    void on_pushButton_2_clicked();
    void messageReceived(QString msg,QString topic);

private:
    Ui::MainWindow *ui;
    uarttest *uart;
    QMqttClient *mqtt;
    QTextEdit *fan;
    QTextEdit *light;
    QTextEdit *light1;
    QLabel *video;
    QImage *frame;
    uchar *ppout;
    QTimer *timer_video;

    //ProcessImage *processimage;
};

#endif // MAINWINDOW_H
