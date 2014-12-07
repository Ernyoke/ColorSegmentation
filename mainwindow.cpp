#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sceneOriginal = new QGraphicsScene(this);
    sceneSegmented = new QGraphicsScene(this);
    pixMapOriginal = new QGraphicsPixmapItem();
    sceneOriginal->addItem(pixMapOriginal);
    pixMapSegmented = new QGraphicsPixmapItem();
    sceneSegmented->addItem(pixMapSegmented);

    ui->dispOriginal->setScene(sceneOriginal);
    ui->dispSegmented->setScene(sceneSegmented);

    connect(ui->loadImage, SIGNAL(clicked()), this, SLOT(loadImage()));
    connect(ui->segmentImage, SIGNAL(clicked()), this, SLOT(segmentImage()));
    connect(ui->webCam, SIGNAL(clicked()), this, SLOT(useWebcam()));

    img = new Image();
    thread = new QThread;
    thread->start();
    img->moveToThread(thread);

    connect(img, SIGNAL(finished()), thread, SLOT(quit()));
    connect(img, SIGNAL(finished()), img, SLOT(deleteLater()));
    connect(this, SIGNAL(newImage(Mat)), img, SLOT(readImage(Mat)));
    connect(this, SIGNAL(segment(int)), img, SLOT(colorSegment(int)));
    connect(img, SIGNAL(segmentFinished(Mat)), this, SLOT(showSegmented(Mat)));

    cam = NULL;
    imgOriginal = NULL;
    isCapturing = false;

    progressDialog = new ProgressDialog(this);
    connect(img, SIGNAL(updateIter(int)), progressDialog, SLOT(updateProgress(int)));
    connect(img, SIGNAL(segmentStatus(QString)), progressDialog, SLOT(displayText(QString)));
    connect(img, SIGNAL(segmentFinished(bool)), progressDialog, SLOT(progessFinished(bool)));
    connect(progressDialog, SIGNAL(cancelSegment()), img, SLOT(cancelSegment()), Qt::DirectConnection);
//    connect()
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pixMapOriginal;
    delete pixMapSegmented;
    delete img;
    delete cam;
}

void MainWindow::loadImage() {
    QFileDialog browser(this);
    browser.setNameFilter(tr("Images (*.png *.bmp *.jpg *.jpeg)"));
    QStringList files;
    if(browser.exec()) {
        files = browser.selectedFiles();
        if(files.size() != 0) {
            delete imgOriginal;
            Mat fromFile;
            fromFile = imread(files.at(0).toStdString(), CV_LOAD_IMAGE_COLOR);
            cvtColor(fromFile, fromFile, CV_BGR2RGB);
            imgOriginal = Mat2QImage(fromFile);
            emit newImage(fromFile);
            pixMapOriginal->setPixmap(QPixmap::fromImage(*imgOriginal));
            ui->dispOriginal->fitInView(pixMapOriginal, Qt::KeepAspectRatio);
        }
    }
}

void MainWindow::segmentImage() {
    QMessageBox msgBox;
    QString input = ui->clusterInput->text().trimmed();
    if(img != NULL) {
        if(!input.isEmpty()) {
            progressDialog->initialize();
            progressDialog->show();
            bool isValid;
            int clusters = input.toInt(&isValid);
            if(isValid) {
                emit segment(clusters);
            }
            else {
                msgBox.setText("Invalid input.");
                msgBox.setInformativeText("The number of colors must be an integer!");
                msgBox.setStandardButtons(QMessageBox::Ok);
                int ret = msgBox.exec();
            }
        }
    }
    else {
        msgBox.setText("No image selected!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        int ret = msgBox.exec();
    }
}

void MainWindow::showSegmented(Mat segmented) {
    imgSegmented = Mat2QImage(segmented);
    pixMapSegmented->setPixmap(QPixmap::fromImage(*imgSegmented));
    ui->dispSegmented->fitInView(pixMapSegmented, Qt::KeepAspectRatio);
}

void MainWindow::useWebcam() {
    if(isCapturing) {
        matOriginal = cam->capture();
        imgOriginal = Mat2QImage(matOriginal);
        isCapturing = false;
        loadImageFromWebcam();
    }
    else {
        if(cam == NULL) {
            cam = new Webcam(pixMapOriginal, 640, 480, 30, this);
        }
        cam->startCapture();
        isCapturing = true;
    }
}

void MainWindow::loadImageFromWebcam() {
    emit newImage(matOriginal);
}

QImage* MainWindow::Mat2QImage(Mat frame) {
    QImage *img = new QImage((uchar*) (frame.data), frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
    return img;
}
