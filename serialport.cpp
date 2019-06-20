#include "serialport.h"

serialport::serialport()
{
        serial = new QSerialPort;
        serial->close();
        serial->setPortName("ttyS0");
        serial->open(QIODevice::ReadWrite);
        serial->setBaudRate(115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        connect(serial,&QSerialPort::readyRead,this,&serialport::read);
}
void serialport::wirte(QByteArray commond)
{
    QByteArray a = QByteArray("\n");
    a.append(commond[0]);
    a.append(commond[1]);
    serial->write(a);
}

void serialport::read()
{
    QByteArray buf;
    buf = serial->readAll();
    qDebug() << buf;
    QString a = QString(buf);

}
