#ifndef PROCESSIMAGE_H
#define PROCESSIMAGE_H

#include <QtGui>
#include "videodevice.h"
#include <QObject>
#include <QMessageBox>
class ProcessImage : public QObject
{
    Q_OBJECT
public:
    ProcessImage();
    ~ProcessImage();
    void paintEvent(uchar *ppout);
    VideoDevice *vd;
private:
   // QPainter *painter;
   // QLabel *label;
   // QImage *frame;
    //QPixmap *frame;
   // QTimer *timer;
    int rs;
    uchar *pp;//rgb格式数据
    uchar * p;//yuv格式数据
    unsigned int len;
    int convert_yuv_to_rgb_pixel(int y, int u, int v);
    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);


private slots:

    void display_error(QString err);


};

#endif
