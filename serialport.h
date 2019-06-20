#ifndef SERIALPORT_H
#define SERIALPORT_H
#include <QObject>
#include <QtSerialPort>

class serialport:public QObject
{
public:
    serialport();
    void wirte(QByteArray commond);
private slots:
    void read();
private:
    QSerialPort *serial;
};

#endif // SERIALPORT_H
