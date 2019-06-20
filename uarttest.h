#ifndef UART_H
#define UART_H

#include <QDialog>
#include <qsocketnotifier.h>
class uarttest: public QObject
{
    Q_OBJECT

public:
    uarttest();
    ~uarttest();
    void uart_send(QString msg);
private:
        int openSerialPort();
        QString unicodeToString(QString str);

        QString stringToUnicode(QString str);

private slots:

        void remoteDataIncoming();

private:
        int m_fd;
        QSocketNotifier *m_notifier;
signals:
       void uart_coming(char chr);


};

#endif // UART_H
