#include <qmessagebox.h>
#include "FindAndReplace.h"
#include "ui_FindAndReplace.h"
#include "QMenuBar"
#include "QMenu"

FindAndReplace::FindAndReplace(QWidget *parent, QTextEdit  * textEdit)
        : QDialog(parent), ui(new Ui::FindAndReplace)
{
    ui->setupUi(this);
    this->setWindowTitle("Search and Replace");
    QObject::connect(ui->btnFind, SIGNAL (clicked()), this, SLOT (onFindClicked()));
    QObject::connect(ui->btnReplace, SIGNAL (clicked()), this, SLOT (onReplaceClicked()));
    QObject::connect(ui->btnFindAll, SIGNAL (clicked()), this, SLOT (onFindAllClicked()));
    QObject::connect(ui->btnReplaceAll, SIGNAL (clicked()), this, SLOT (onReplaceAllClicked()));



    //Set events if the user change the search text
    QObject::connect(ui->editFind, SIGNAL (textChanged(QString)), this, SLOT (onFindSettingsChanged(QString)));

    this->textEdit  = textEdit;
    this->resetSearchValues();

}

/**
 * Getter for the values from the UI
 */
QTextDocument::FindFlags FindAndReplace::getFindFlags() {

    QTextDocument::FindFlags flags = 0;

    if(this->ui->checkDirectionBackwards->isChecked()){
        flags = flags | QTextDocument::FindBackward;
    }

    if(this->ui->checkCaseSensitive->isChecked()){
        flags = flags | QTextDocument::FindCaseSensitively;
    }
    return flags;
}
bool FindAndReplace::getSearchString(QString *searchString) {

    *searchString = this->ui->editFind->text();

    if(searchString->trimmed().size() == 0 ){
        QMessageBox::information(this,"Error","Plesase insert some search text");
        return false;
    }
    return true;
}

bool FindAndReplace::getReplaceString(QString *replaceString) {

    *replaceString = this->ui->editFindAndReplace->text();

    if(replaceString->trimmed().size() == 0 ){
        QMessageBox::information(this,"Error","Plesase insert some replace text");
        return false;
    }
    return true;
}


/**
 * Slots
 */
void FindAndReplace::onFindAllClicked() {

    this->resetSearchValues();
    textEdit->moveCursor(QTextCursor::Start);
    this->ui->btnReplace->setDisabled(false);
    this->ui->btnReplaceAll->setDisabled(false);
    this->ui->btnFind->setDisabled(true);

    QString searchString;
    if(this->getSearchString(&searchString)){
        this->findAll(searchString,this->getFindFlags());
        textEdit->setExtraSelections(*currentSelection);
    }



}

void FindAndReplace::onFindClicked() {

    //Only if this is a new search move the cursor to the top
    if(this->currentSelection->size() == 0 ){
        textEdit->moveCursor(QTextCursor::Start);
    }

    QString searchString;

    if(this->getSearchString(&searchString)){

        find(searchString, this->getFindFlags());
        textEdit->setExtraSelections(*currentSelection);
    }


}
void FindAndReplace::onReplaceAllClicked() {

    QString replaceString;
    if(this->getReplaceString(&replaceString)){
        this->replaceAll(replaceString);
        this->resetSearchValues();
    }
}

void FindAndReplace::onReplaceClicked() {


    if(this->currentSelection->size() == 0){
        QMessageBox::information(this, "Error", "Please click \"Find all \" before you replace");
    }

    QString replaceText;
    if(this->getReplaceString(&replaceText)){

        this->replace(replaceText);
    }


}

void FindAndReplace::onFindSettingsChanged(QString string) {
    this->resetSearchValues();
}


/**
 * Search logic
 */
bool FindAndReplace::findAll(QString replaceString,QTextDocument::FindFlags flags) {
    bool isOneFound = false;

    do{
        isOneFound = find(replaceString,flags);

    }while (isOneFound);

    return isOneFound;
}


bool FindAndReplace::find(QString searchString,QTextDocument::FindFlags flags) {

    QColor color = QColor(Qt::gray).lighter(130);

    if(textEdit->find(searchString,flags)){

        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);

        extra.cursor = textEdit->textCursor();

        currentSelection->append(extra);
        return true;
    };

    return false;
}
bool FindAndReplace::replaceAll(QString replaceString) {
    bool isStillOneToReplaceThere = false;

    do{
        isStillOneToReplaceThere = replace(replaceString);

    }while (isStillOneToReplaceThere);

    return isStillOneToReplaceThere;
}
bool FindAndReplace::replace(QString replaceString) {

    if(this->currentSelection->size() != 0){
        QTextEdit::ExtraSelection extra   = this->currentSelection->takeFirst();
        extra.cursor.insertText(replaceString);
        return true;
    }

    return false;
}


/**
 * Reset mehtod to reset the ui state
 */
void FindAndReplace::resetSearchValues() {

    this->ui->btnReplace->setDisabled(true);
    this->ui->btnReplaceAll->setDisabled(true);
    this->ui->btnFind->setDisabled(false);
    //
    /**
     * Bad way to clear selections but the following solutions not worked
     * this->currentSelection = new QList<QTextEdit::ExtraSelection>();
     * this->textEdit->setExtraSelections(*currentSelection)
     *
     * this->textEdit->extraSelections().clear();
     *
     *
     *     for(QTextEdit::ExtraSelection extraSelection : this->textEdit->extraSelections()){
            extraSelection.cursor.clearSelection();
            extraSelection.format.clearBackground();
            }
            this->textEdit->setExtraSelections(this->textEdit->extraSelections());
     *
     */



    //Bad solution but works clear the list, add a selection and after this clear the list again;
    this->currentSelection = new QList<QTextEdit::ExtraSelection>();


    QTextEdit::ExtraSelection extra;
    textEdit->moveCursor(QTextCursor::Start);
    extra.cursor = textEdit->textCursor();
    this->currentSelection->push_front(extra);
    this->textEdit->setExtraSelections(*currentSelection);


    this->currentSelection->clear();

}

FindAndReplace::~FindAndReplace()
{

}
