#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QtMqtt/QMqttClient>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ppout = (unsigned char *)malloc(640 * 480 * 3 * sizeof(char));/*QWidget::width()*QWidget::height()*///每一帧RGB数据
    fan=ui->fan;
    light=ui->light;
    light1=ui->light1;
    sendjson=new gateway();
    tranjson=new gateway();
    mqtt = new QMqttClient(this);
    mqtt->setHostname("119.23.61.148");
    mqtt->setPort(61613);
    mqtt->setUsername("admin");
    mqtt->setPassword("password");

    mqtt->connectToHost();



//    mqtt = new mqttClient(this);
  //  mqtt->MqttClientInit("119.23.61.148",61613,"2016110201_conversation","gateway_conversation","admin","password");
    auto subscription = mqtt->subscribe(QMqttTopicFilter("gateway_conversation"));
    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
    connect(mqtt,SIGNAL(messageReceived(QString,QString)),this,SLOT(display_send(QString,QString)));


   // uart=new uarttest();
    //connect(uart,SIGNAL(uart_coming(char)),this,SLOT(uart_display(char)));

    /*processimage=new ProcessImage();
    video=ui->video;
    frame = new QImage(ppout,640,452,QImage::Format_RGB888);//QImage类主要用于I/O和直接逐像素访问,display image...采集的图像应该是RGB888格式
    timer_video=new QTimer(this);
    connect(timer_video,SIGNAL(timeout()),this,SLOT(play_video()));
    timer_video->start(30);*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::play_video(){
  //  processimage->paintEvent(ppout);
  //  frame->loadFromData((uchar *)ppout,/*len*/640 * 480 * 3 * sizeof(char));
   // video->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));
  //  processimage->vd->unget_frame();
}
void MainWindow::uart_display(char str){
    ui->UARTGET->setText(ui->UARTGET->toPlainText()+str);

}
void MainWindow::on_pushButton_clicked()
{
     QString strjson=sendjson->getJsonString();
     mqtt->publish(QMqttTopicName("gateway_conversation"),strjson.toUtf8(),0,false);
}
void MainWindow::display_send(QString msg,QString topic){
     if(QString::compare(topic,"2016110201_conversation")==0){
         if(tranjson->parseJson(msg.toUtf8())==true){
              fan->setText(QString::number(tranjson->fan));
              if(tranjson->light1==true){
                  light1->setText("ON");
              }else{
                  light1->setText("OFF");
              }
              if(tranjson->light2==true){
                  light->setText("ON");
              }else{
                  light->setText("OFF");
              }
         }

     }


}

void MainWindow::messageReceived(QString msg,QString topic)
{
   // qDebug()<<"msg"<<msg<<endl<<"topic"<<topic<<endl;
   qDebug()<<"recrived ok"<<endl;

}

void MainWindow::on_pushButton_2_clicked()
{
    uart->uart_send("hello");
}
