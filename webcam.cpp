#include "webcam.h"

const int FPS = 30;
const int WIDTH = 640;
const int HEIGHT = 480;

Webcam::Webcam(QGraphicsPixmapItem *toDisplay, int width, int height, int fps, QObject *parent) :
    QObject(parent)
{
    this->toDisplay = toDisplay;
    this->width = width;
    this->height = height;
    this->fps = fps;

    timer = new QTimer(this);
    timer->setInterval(1000 / fps);

    cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);
    cam.set(CV_CAP_PROP_FPS, fps);

    finalIm = NULL;

}

Webcam::~Webcam() {
    if(isCapturing) {
        stopCapture();
    }
    delete timer;
    delete finalIm;
}

void Webcam::startCapture() {
    cam.open(0);
    if(!cam.isOpened()) {
        //cam error
    }
    else {
        connect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
        timer->start();
        isCapturing = true;
    }
}

void Webcam::showFrame() {
    Mat fromCam;
    cam.read(fromCam);
    cvtColor(fromCam, fromCam, CV_BGR2RGB);
    QImage disp(fromCam.data, fromCam.cols, fromCam.rows, fromCam.step, QImage::Format_RGB888);
    toDisplay->setPixmap(QPixmap::fromImage(disp));
}

Mat Webcam::capture() {
    Mat finalIm;
    cam.read(finalIm);
    cvtColor(finalIm, finalIm, CV_BGR2RGB);
    QImage *image =  new QImage(finalIm.data, finalIm.cols, finalIm.rows, finalIm.step, QImage::Format_RGB888);
    toDisplay->setPixmap(QPixmap::fromImage(*image));
    stopCapture();
    return finalIm;
}

void Webcam::stopCapture() {
    cam.release();
    isCapturing = false;
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
}
