#include "mqttclient.h"
#include <QDebug>

mqttClient::mqttClient(QObject *parent) : QObject(parent)
{
    subscriber_ = NULL;
    publisher_ = NULL;
    TimeCount = 0;
}
mqttClient::~mqttClient(){}
//参数依次为 mqtt服务器IP---mqtt服务器端口---订阅主题---发布主题---用户名---用户名对应的密码
void mqttClient::MqttClientInit(QString mqttHostName, int port, QString sub, QString pub, QString userName, QString userPwd)
{
    QHostAddress RemoteHost(mqttHostName);//IP
    subscriber_ = new Subscriber(RemoteHost,port,sub,userName,userPwd);//订阅消息
    publisher_ = new Publisher(RemoteHost,port,pub,userName,userPwd);//发布消息
    subscriber_->connectToHost();
    publisher_->connectToHost();

    connect(subscriber_,SIGNAL(messageReceived(QString,QString)),this,SLOT(messageReceived(QString,QString)));//连接订阅后接收到消息的槽函数

    Timer= new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(TimeHandle()));//
    Timer->start(1000);//1s

}

//定义20s发布一次信息
void mqttClient::TimeHandle()
{
    TimeCount++;
    if(TimeCount>=2)
    {
        TimeCount = 0;
     //   this->PublishMessage("aaaa","gateway_conversation");
        qDebug()<<"****************************"<<endl;
    }
}

//mqtt客户端接收数据触发的槽函数
void mqttClient::messageReceived(QString msg,QString topic)
{
   // qDebug()<<"msg"<<msg<<endl<<"topic"<<topic<<endl;
   qDebug()<<"recrived ok"<<endl;

}

//mqtt发布信息
void mqttClient::PublishMessage(QString msg, QString topic)
{
    publisher_->publishTopic(topic,msg);
}
