#ifndef WEBCAM_H
#define WEBCAM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QImage>
#include <QThread>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Webcam : public QObject
{
    Q_OBJECT
public:
    Webcam(QGraphicsPixmapItem *toDisplay, int width, int height, int fps, QObject *parent = 0);
    ~Webcam();

    Mat capture();
    void stopCapture();
    void startCapture();

private:
    QGraphicsPixmapItem *toDisplay;
    QTimer *timer;
    VideoCapture cam;
    bool isCapturing;

    int width;
    int height;
    int fps;

    Mat *finalIm;

signals:

public slots:
    void showFrame();

};

#endif // WEBCAM_H
