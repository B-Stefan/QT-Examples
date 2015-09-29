#include "TextEditorWindow.h"


#include <QMainWindow>
#include <QTextEdit>
#include <QStatusBar>
#include "TextEditorWindow.h"
#include "FindAndReplace.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QApplication>
#include <QAction>
#include <QTextStream>
#include <QMenuBar>
#include <QMenu>
#include <qfiledialog.h>


TextEditorWindow::TextEditorWindow(QWidget *parent, Qt::WindowFlags flags)
        : QMainWindow(parent, flags)
{
    textEdit = new QTextEdit;
    QTextDocument *htmlDoc = textEdit->document();
    htmlDoc->setHtml("<h1>Edit title!</h1> <p>Normal paragraph</p> <ul><li>Some</li>  <li>Fancy</li> <li>Listing</li>  </ul> " );
    textEdit->setLineWrapMode(QTextEdit::NoWrap);
    textEdit->setDocument(htmlDoc);
    setCentralWidget(textEdit);
    setWindowTitle(tr("Your own Basic Text editor"));
    statusBar()->showMessage(tr("Status Bar"));

    createActions();
    createMainMenu();
}

void TextEditorWindow::createMainMenu() {

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAction);
    fileMenu->addAction(findAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&?"));
    helpMenu->addAction(aboutAction);


}

void TextEditorWindow::createActions() {

    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("Create a new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open a text file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save this text file"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip(tr("Quit the programm"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(quitProgramm()));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("About this programm"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));


    findAction = new QAction(tr("&Find and Replace"), this);
    findAction->setStatusTip(tr("Dilaog for find and replace function "));
    connect(findAction, SIGNAL(triggered()), this, SLOT(openFindAndReplace()));

}

/**
 * Slots
 */

void TextEditorWindow::closeEvent(QCloseEvent *event) {

}
void TextEditorWindow::about() {
    QMessageBox::about(0, "About", "Always pass on what you learned ");
}

void TextEditorWindow::newFile() {
    TextEditorWindow * newWindow = new TextEditorWindow(this->parentWidget(),this->windowFlags());
    newWindow->move(0,-300);
    newWindow->show();
}

void TextEditorWindow::openFile() {

    QString fileName =  QFileDialog::getOpenFileName(this,tr("Open File"), "/");
    this->setCurrentFile(fileName);
    if(this->load(this->currentFileName)){
        QMessageBox::information(0, "Loaded!", "File successful loaded");
    }

}

void TextEditorWindow::saveFile() {

    if(this->currentFileName == nullptr)
    {
        QString fileName =  QFileDialog::getSaveFileName(this, tr("Open File"), "/");
        this->setCurrentFile(fileName);
    }


    if(this->save(currentFileName)){
        QMessageBox::information(0, "Saved!", "File successful saved");
    };

}

void TextEditorWindow::openFindAndReplace() {
    FindAndReplace * findAndReplace = new FindAndReplace(this,this->textEdit);
    findAndReplace->move(0,400);
    findAndReplace->show();
}

/**
 * Logic
 */
bool TextEditorWindow::load(const QString &fname) {

    QFile file(fname);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return false;
    }

    QString text = file.readAll();
    textEdit->setHtml(text);

    return true;
}

bool TextEditorWindow::save(const QString &fname) {

    QFile file(fname);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){

        return false ;
    }
    QTextStream out(&file);
    out << textEdit->toHtml();

    return true;
}

void TextEditorWindow::setCurrentFile(const QString &fname) {

    this->setWindowTitle(fname);
    this->currentFileName = fname;
}

void TextEditorWindow::quitProgramm() {
    QApplication::quit();
}

