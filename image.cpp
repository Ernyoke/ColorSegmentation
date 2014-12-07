#include "image.h"

const int Image::N = 255;
const int Image::MAX_ITER = 50;

Image::Image(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType<cv::Mat>("Mat");
    isRunning = false;
}

void Image::readImage(Mat src) {
    original = src;
    cvtColor(original, source, CV_RGB2Lab);
    cvtColor(original, destinaton, CV_RGB2Lab);
}

void Image::colorSegment(int groups) {
    int it = N / groups;
    int i = 0;
    QVector<Center*> centers;
    QVector<Center*> prevCenters;
    generateCenterPoints(&centers, groups);
    for(int i = 0; i < groups; ++i) {
        prevCenters.append(centers.at(i));
    }

    bool isEnd = false;
    if(!isRunning) {
        isRunning =  true;
        for(i = 0; i < MAX_ITER && !isEnd; ++i) {
            if(isRunning) {
                emit updateIter(i + 1);
                isEnd = true;
            }
            isEnd = true;
            int min;
            int poz;
            Size size = source.size();
            for(int x = 0; x < size.height; ++x) {
                for(int y = 0; y < size.width; ++y) {
                    min = N;
                    Vec3b pix = source.at<Vec3b>(x, y);
                    for(int iter = 0; iter < groups; ++iter) {
                        Center *currentCP = centers.at(iter);
                        int dist = distance(pix, currentCP->getCenterPoint());
                        if(dist < min) {
                            min = dist;
                            poz = iter;
                        }
                    }
                    Center *newCP = centers.at(poz);
                    newCP->setCluster(pix);
                    destinaton.at<Vec3b>(x, y) = newCP->getCenterPoint();
    //                qDebug() << poz;
                }
            }
            for(QVector<Center*>::iterator it = centers.begin(); it != centers.end(); ++it) {
                if(!(*it)->recalculate()) {
                    isEnd = false;
                }
                Center *c = (*it);
    //            qDebug() << c->getCenterPoint()[0] << " " << c->getCenterPoint()[1] << " " << c->getCenterPoint()[2];
                if(isRunning) {
                    QString status = "Center point: " + QString::number(c->getCenterPoint()[0]) + " " + QString::number(c->getCenterPoint()[1]) + " " + QString::number(c->getCenterPoint()[2]);
                    emit segmentStatus(status);
                }
                else {
                    isEnd = true;
                }

            }
        }
    }
    cvtColor(destinaton, destinaton, CV_Lab2RGB);
    emit segmentFinished(destinaton);
    emit segmentFinished(isRunning);
    isRunning = false;

}

int Image::distance(Vec3b a, Vec3b b) {
    int result = qPow(a[0] - b[0], 2) + qPow(a[1] - b[1], 2) + qPow(a[2] - b[2], 2);
    return qSqrt(result);
}

Mat Image::getOriginal() {
    return original;
}

Mat Image::getSegmented() {
    Mat res = destinaton;
    cvtColor(destinaton, res, CV_Lab2RGB);
    return res;
}

void Image::generateCenterPoints(QVector<Center*> *center, int groups) {
    QTime time = QTime::currentTime();
    Size imagesize = source.size();
    qsrand((uint)time.msec());
    for(int i = 0; i < groups; ++i) {
        int x = randInt(0, imagesize.height);
        int y = randInt(0, imagesize.width);
        Vec3b pix = source.at<Vec3b>(x, y);
        Center *newCenter = new Center(pix);

        //check if selected pixel is already in the vector
        bool isIn = false;
        for(QVector<Center*>::iterator it = center->begin(); it != center->end(); ++it) {
            Center *current = *it;
            if(*current == *newCenter) {
                isIn = true;
                break;
            }
        }
        if(!isIn) {
            center->append(newCenter);
        }
        else {
            i--;
        }
    }
}

int Image::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void Image::cancelSegment() {
    if(isRunning) {
        isRunning =  false;
    }
}

