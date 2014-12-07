#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QVector>
#include <QtMath>
#include <QImage>
#include <QDebug>
#include <QTime>
#include <center.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Image : public QObject
{
    Q_OBJECT
public:
    explicit Image(QObject *parent = 0);
    Mat getOriginal();
    Mat getSegmented();

    static const int MAX_ITER;
    static const int N;

private:
    Mat original;
    Mat source;
    Mat destinaton;

    int distance(Vec3b, Vec3b);
    void generateCenterPoints(QVector<Center *> *center, int groups);
    int randInt(int, int);

    bool isRunning;

signals:

public slots:
    void readImage(Mat);
    void colorSegment(int);
    void cancelSegment();

signals:
    void segmentFinished(Mat);
    void segmentFinished(bool);
    void finished();
    void updateIter(int);
    void segmentStatus(QString);

};

#endif // IMAGE_H
