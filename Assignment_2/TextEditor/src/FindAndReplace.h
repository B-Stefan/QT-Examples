//
// Created by Stefan B. on 27.09.15.
//

#ifndef QT_ASSIGNMENTS_FINDANDREPLACE_H
#define QT_ASSIGNMENTS_FINDANDREPLACE_H

#include <QMainWindow>
#include <QWidget>
#include <QDialog>
#include <QScopedPointer>
#include <qtextedit.h>


namespace Ui
{
    class FindAndReplace;
}

class FindAndReplace : public QDialog {
Q_OBJECT
public:
    explicit FindAndReplace(QWidget *parent = 0, QTextEdit * textEdit = 0);


private slots:
    void onFindSettingsChanged(QString string);
    void onReplaceClicked();
    void onFindClicked();
    void onFindAllClicked();
    void onReplaceAllClicked();
private:
    virtual ~FindAndReplace();

    void resetSearchValues();
    QScopedPointer<Ui::FindAndReplace> ui;
    QTextEdit * textEdit;
    QList<QTextEdit::ExtraSelection> * currentSelection;


    bool getSearchString(QString *searchString);
    bool getReplaceString(QString *searchString);
    QTextDocument::FindFlags getFindFlags();
    bool find(QString searchString, QTextDocument::FindFlags = 0 );
    bool findAll(QString searchString, QTextDocument::FindFlags = 0 );
    bool replace(QString replaceString);
    bool replaceAll(QString replaceString);
};


#endif //QT_ASSIGNMENTS_FINDANDREPLACE_H
