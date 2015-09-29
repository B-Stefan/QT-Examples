//
// Created by Stefan B. on 27.09.15.
//

#ifndef QT_ASSIGNMENTS_TEXTEDITORWINDOW_H
#define QT_ASSIGNMENTS_TEXTEDITORWINDOW_H


#include <QMainWindow>
#include <QTextEdit>
#include <QString>

class TextEditorWindow : public QMainWindow {
Q_OBJECT
public:
    TextEditorWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);

protected:
    void closeEvent(QCloseEvent *event);

private slots:

    void newFile();

    void openFile();

    void saveFile();

    void about();

    void quitProgramm();

    void openFindAndReplace();

private:
    void createMainMenu(); // creates main menu bar

    void createActions(); // creates actions for menus

    bool load(const QString &fname);

    bool save(const QString &fname);

    void setCurrentFile(const QString &fname);

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *aboutAction;
    QAction *findAction;
    QAction *quitAction;
    QTextEdit *textEdit;
    QString currentFileName;
};


#endif //QT_ASSIGNMENTS_TEXTEDITORWINDOW_H
