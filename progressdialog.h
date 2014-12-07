#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include "image.h"

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QWidget *parent = 0);
    ~ProgressDialog();

    void initialize();

private:
    Ui::ProgressDialog *ui;
    int iteration;
    QString textLine;

private slots:
    void cancel();
    void ok();
    void updateProgress(int);
    void displayText(QString);
    void progessFinished(bool);

signals:
    void cancelSegment();
};

#endif // PROGRESSDIALOG_H
