#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(Image::MAX_ITER);

    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(ok()));
}

void ProgressDialog::initialize() {
    ui->progressBar->setValue(0);
    ui->okBtn->setDisabled(true);
    ui->cancelBtn->setDisabled(false);
    ui->textBrowser->clear();
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}

void ProgressDialog::cancel() {
    emit cancelSegment();
    ui->okBtn->setDisabled(false);
    ui->cancelBtn->setDisabled(true);
    this->displayText("\nSegmentation Canceled!");
}

void ProgressDialog::ok() {
    this->hide();
}

void ProgressDialog::updateProgress(int progress) {
    ui->progressBar->setValue(progress);
    ui->iterLine->setText(QString::number(progress));
    this->displayText("Iteration: " + QString::number(progress));
}

void ProgressDialog::displayText(QString text) {
    ui->textBrowser->append(text);
}

void ProgressDialog::progessFinished(bool fin) {
    if(fin) {
        this->displayText("Segmentation finished succesfully!");
        ui->progressBar->setValue(Image::MAX_ITER);
    }
}
