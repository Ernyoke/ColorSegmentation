#include "center.h"

Center::Center() {
    this->sumA = 0;
    this->sumB = 0;
    this->sumL = 0;
    this->n = 0;
}

Center::Center(Vec3b center)
{
    this->centerPoint = center;
    this->sumA = 0;
    this->sumB = 0;
    this->sumL = 0;
    this->n = 0;
}

Vec3b Center::getCenterPoint() {
    return centerPoint;
}

bool Center::recalculate() {
    if(n != 0) {
        oldCenter = centerPoint;
        uchar L = sumL / n;
        uchar a = sumA / n;
        uchar b = sumB / n;

        centerPoint[0] = L;
        centerPoint[1] = a;
        centerPoint[2] = b;

        sumA = 0;
        sumB = 0;
        sumL = 0;
        n = 0;

        if(oldCenter[0] == centerPoint[0] && oldCenter[1] == centerPoint[1] && oldCenter[2] == centerPoint[2]) {
            return true;
        }
    }
    return false;
}

void Center::setCluster(Vec3b pix) {
    sumL += pix[0];
    sumA += pix[1];
    sumB += pix[2];
    n++;
}

bool operator== (Center &c1, Center &c2) {
    if(c1.centerPoint == c2.centerPoint) {
        return true;
    }
    return false;
}
