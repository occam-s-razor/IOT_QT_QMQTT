#ifndef GATEWAY_H
#define GATEWAY_H
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
/*
 * {
    "type": "dashboard",
    "gateway_id": "123761354321",
    "vlues": {
        "temperature": "26.3",
        "humidity": "60",
        "fan": "69",
        "beam": "56",
        "light": {
            "light1": "on",
            "light2": "off"
        }
    }
}
*/
class gateway
{
public:
    gateway();  
    bool light1;
    bool light2;
    int fan;
private:

    QString type;
    QString gateway_id;
    double temperature;
    int humidity;
    //int fan;
    int beam;
   // bool light1;
   // bool light2;
    QJsonObject jsonobject;
    QJsonDocument jsondocument;

public:
    double getTemperature() {
            return temperature;
        }
    void setTemperature(double temp) {
            temperature = temp;
        } 
    int getHumidity() {
            return humidity;
        }
    void setHumidity(int hum) {
            humidity = hum;
        }
    int getFan() {
            return fan;
        }
    void setFan(int fa) {
            fan = fa;
        }
    int getBeam() {
            return beam;
        }
    void setBeam(int bea) {
            beam = bea;
        }
    bool getLight1() {
            return light1;
        }
    void setLight1(bool l1) {
            light1 = l1;
        }
    bool getLight2() {
            return light2;
        }
    void setLight2(bool l2) {
            light2 = l2;
        }
    QJsonObject getJsonObject()
    {//构建json对象

        // 构建 Json 对象 - vlues
        QJsonObject vluesObject;
        vluesObject.insert("temperature", QString::number(getTemperature()));
        vluesObject.insert("humidity", QString::number(getHumidity()));
        vluesObject.insert("fan",QString::number(getFan()));
        vluesObject.insert("beam",QString::number(getBeam()));
        vluesObject.insert("light1", getLight1()?"true":"false");
        vluesObject.insert("light2", getLight2()?"true":"false");

        // 构建 Json 对象 - json
        jsonobject.insert("type",type);
        jsonobject.insert("gateway_id",gateway_id);
        jsonobject.insert("sensors_value",QJsonValue(vluesObject));

        return jsonobject;

    }

   QJsonDocument getJsonDocument()
   {// 构建json文档
       jsondocument.setObject(getJsonObject());
       return jsondocument;
   }

   QString getJsonString()
   {//返回json字符串
       jsondocument = getJsonDocument();
       QByteArray byteArray = jsondocument.toJson(QJsonDocument::Compact);
       QString strJson(byteArray);
       return strJson;
   }

   bool parseJson(QByteArray byteArray)
   {
       QJsonParseError jsonError;
       QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
       if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
           if (doucment.isObject()) { // JSON 文档为对象
               QJsonObject object = doucment.object();  // 转化为对象
               if (object.contains("type")) {  // 包含指定的 key
                   QJsonValue value = object.value("type");  // 获取指定 key 对应的 value
                   if (value.isString()) {  // 判断 value 是否为字符串
                       QString strtype = value.toString();  // 将 value 转化为字符串
                       if(QString::compare(strtype,"client_control")!=0)
                       {
                           return false;
                       }
                   }
               }
               if (object.contains("fan")) {
                   QJsonValue value = object.value("fan");
                   if (value.isString()) {
                       int fan1 = value.toString().toInt();
                       setFan(fan1);
                       //风扇调速代码
                   }
               }
               if (object.contains("light1")) {
                   QJsonValue value = object.value("light1");
                   if (value.isString()) {
                       QString strlight1 = value.toString();
                       if(QString::compare(strlight1,"on")==0)
                       {
                           setLight1(true);
                          //开灯代码
                       }
                       if(QString::compare(strlight1,"off")==0)
                       {
                           setLight1(false);
                           //关灯代码
                       }
                   }
               }
               if (object.contains("light2")) {
                   QJsonValue value = object.value("light2");
                   if (value.isString()) {
                       QString strlight2= value.toString();
                       if(QString::compare(strlight2,"on")==0)
                       {
                           setLight2(true);
                           //开灯代码
                       }
                       if(QString::compare(strlight2,"off")==0)
                       {
                           setLight2(false);
                           //关灯代码
                       }
                   }
               }
               return true;
           }// JSON 文档为对象
           else {
               return false;
           }
       }// 解析未发生错误
       else {
           return false;
       }
   }
};

#endif // GATEWAY_H
