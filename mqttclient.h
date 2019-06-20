#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H


#include <QObject>
#include <QTimer>


#include "publisher.h"
#include "subscriber.h"

class mqttClient : public QObject
{
    Q_OBJECT
public:
    explicit mqttClient(QObject *parent = NULL);
    void MqttClientInit(QString mqttHostName, int port, QString sub, QString pub, QString userName, QString userPwd);//初始化MQTT连接
    void PublishMessage(QString msg, QString topic);//mqtt发布信息
    ~mqttClient();
    Subscriber *subscriber_;
signals:



public slots:
    void messageReceived(QString msg,QString topic);//mqtt接收信息

    void TimeHandle();//定时时间到执行的槽函数


protected:

   Publisher *publisher_;
   QTimer *Timer;
   int TimeCount;

};

#endif // MQTTCLIENT_H
