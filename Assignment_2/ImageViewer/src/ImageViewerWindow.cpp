#include <qmessagebox.h>
#include "ImageViewerWindow.h"
#include "ui_ImageViewerWindow.h"
#include "QMenuBar"
#include "QMenu"
#include "QDebug"

ImageViewerWindow::ImageViewerWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::ImageViewerWindow)
{
    ui->setupUi(this);
    // setting all images from the resource file
    loadImages();
    counter=0;
    // Connecting signals/slot
    QObject::connect(ui->nextButton, SIGNAL(clicked()), this,
                     SLOT(nextImage()));
    QObject::connect(ui->prevButton, SIGNAL(clicked()), this,
                     SLOT(prevImage()));
    QObject::connect(ui->scaleButton, SIGNAL(clicked()), this ,
                     SLOT(showScaled()));

    this->nextImage();
}
void ImageViewerWindow::loadImages() {
    images.push_back(scale(QPixmap(":/res/images/d1.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d2.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d3.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d4.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d5.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d6.jpeg")));
    images.push_back(scale(QPixmap(":/res/images/d7.jpeg")));


}
void ImageViewerWindow::nextImage() {
    if (counter >= images.size()-1) counter=0;
    else counter++;
    qDebug() << counter;
    ui->imgLabel->setPixmap(images.at(counter));
}
void ImageViewerWindow::prevImage () {
    if (counter == 0 ) counter=images.size()-1;
    else counter--;
    qDebug() << counter;
    ui->imgLabel->setPixmap(images.at(counter));
}
void ImageViewerWindow::showScaled () {

    QPixmap currentImage = this->images.at(counter);
    QPixmap scaled = scale(currentImage, 2);
    ui->imgLabel->setPixmap(scaled);
};

ImageViewerWindow::~ImageViewerWindow()
{

}

QPixmap ImageViewerWindow::scale(QPixmap pixmap, int factor) {

    return pixmap.scaled(this->ui->imgLabel->width() * factor,
                         this->ui->imgLabel->height() * factor,
                         Qt::KeepAspectRatio);
}
