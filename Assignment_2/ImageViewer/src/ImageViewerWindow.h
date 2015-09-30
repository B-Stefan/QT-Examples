//
// Created by Stefan B. on 27.09.15.
//

#ifndef QT_ASSIGNMENTS_ImageViewerWindow_H
#define QT_ASSIGNMENTS_ImageViewerWindow_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QScopedPointer>
#include <qtextedit.h>


namespace Ui
{
    class ImageViewerWindow;
}

class ImageViewerWindow : public QMainWindow {
Q_OBJECT
public:
    explicit ImageViewerWindow(QWidget *parent = 0);
    virtual ~ImageViewerWindow();

private slots:
    void showScaled();
    void prevImage();
    void nextImage();

private:

    QList<QPixmap> images;
    int counter;
    void loadImages();
    QPixmap scale(QPixmap pixmap, int factor = 1);
    QScopedPointer<Ui::ImageViewerWindow> ui;
};


#endif //QT_ASSIGNMENTS_ImageViewerWindow_H
