#ifndef CENTER_H
#define CENTER_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

using namespace cv;

class Center
{
public:
    Center();
    Center(Vec3b);
    Vec3b getCenterPoint();
    bool recalculate();
    void setCluster(Vec3b);

    friend bool operator== (Center &c1, Center &c2);

private:
    Vec3b centerPoint;
    Vec3b oldCenter;
    long sumL;
    long sumA;
    long sumB;
    int n;


};

#endif // CENTER_H
