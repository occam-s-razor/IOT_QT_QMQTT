#include "uarttest.h"
#include <qtextedit.h>
#include <qprogressbar.h>
#include <qtimer.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qstringlist.h>

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>
#include <termio.h>
uarttest::uarttest()
{
    m_fd = openSerialPort();
    if (m_fd < 0) {
          //  QMessageBox::warning(this, tr("Error"), tr("Fail to open serial port!"));
            return ;
    }

    m_notifier = new QSocketNotifier(m_fd, QSocketNotifier::Read, this);
    connect (m_notifier, SIGNAL(activated(int)), this, SLOT(remoteDataIncoming()));
}
uarttest::~uarttest()
{
    if (m_notifier) {
            delete m_notifier;
            m_notifier = 0;
        }

        if (m_fd >= 0) {
            ::close(m_fd);
            m_fd = -1;
        }
}
int uarttest::openSerialPort()
{
        int fd = -1;
        const char *devName = "/dev/ttySAC3";
        fd = ::open(devName, O_RDWR|O_NONBLOCK);
        if (fd < 0) {
                return -1;
        }
        termios serialAttr;
        memset(&serialAttr, 0, sizeof serialAttr);
        serialAttr.c_iflag = IGNPAR;
        serialAttr.c_cflag = B115200 | HUPCL | CS8 | CREAD | CLOCAL;
        serialAttr.c_cc[VMIN] = 1;
        if (tcsetattr(fd, TCSANOW, &serialAttr) != 0) {
                return -1;
        }
        return fd;
}

void uarttest::remoteDataIncoming()
{
        char c;
        if (read(m_fd, &c, sizeof c) != 1) {
      //          QMessageBox::warning(this, tr("Error"), tr("Receive error!"));
                return;
        }
        emit uart_coming(c);
       // ui->m_receive->setText(ui->m_receive->toPlainText()+c);
}
void uarttest::uart_send(QString msg)
{

    if(msg.isEmpty()){
        return;
    }
    ::write(m_fd,msg.data(),2*msg.length());
 //   QString text( ui->m_send->toPlainText());
 //   if (text.isEmpty()) {
   //         return ;
 //   }
 //   ::write(m_fd, text.data(), 2*text.length());// 经实验  得读取到的长度乘2才能收得全
    //ui->m_sendEdit->setText("");
  //  stringToUnicode(a)
}
