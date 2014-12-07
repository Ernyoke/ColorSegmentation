#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "image.h"
#include "webcam.h"
#include "progressdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sceneOriginal;
    QGraphicsPixmapItem *pixMapOriginal;
    QGraphicsScene *sceneSegmented;
    QGraphicsPixmapItem *pixMapSegmented;
    QImage *imgOriginal;
    QImage *imgSegmented;

    Image *img;
    Webcam *cam;
    bool isCapturing;

    Mat matOriginal;

    void loadImageFromWebcam();
    QImage* Mat2QImage(Mat);

    QThread *thread;

    ProgressDialog *progressDialog;

private slots:
    void loadImage();
    void segmentImage();
    void useWebcam();
    void showSegmented(Mat);

signals:
    void newImage(Mat);
    void segment(int);
    void processFinished();
};

#endif // MAINWINDOW_H
