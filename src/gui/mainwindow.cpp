#include "gui/mainwindow.hh"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ClickableTextEdit *resultTxt = qobject_cast<ClickableTextEdit*>(ui->resultTxt);
    if (resultTxt) {
        connect(resultTxt, &ClickableTextEdit::wordClicked, this, &MainWindow::handleWordClicked);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString textInput = ui->inputTxt->toPlainText();
    // qInfo() << textInput;

    // Get modifiers :
    bool basicModifierCheckbox = ui->basicModifierCheckbox->isChecked();
    bool urlModifierCheckbox = ui->urlModifierCheckbox->isChecked();
    bool pontModifierCheckbox = ui->ponctModifierCheckbox->isChecked();
    bool dateModifierCheckbox = ui->dateModifierCheckbox->isChecked();
    bool contractionModifierCheckbox = ui->contractionModifierCheckbox->isChecked();
    bool corpModifierCheckbox = ui->corpModifierCheckbox->isChecked();

    // qInfo() << "basicModifierCheckbox:" << basicModifierCheckbox;
    // qInfo() << "urlModifierCheckbox:" << urlModifierCheckbox;
    // qInfo() << "pontModifierCheckbox:" << pontModifierCheckbox;
    // qInfo() << "dateModifierCheckbox:" << dateModifierCheckbox;
    // qInfo() << "contractionModifierCheckbox:" << contractionModifierCheckbox;
    // qInfo() << "corpModifierCheckbox:" << corpModifierCheckbox;

    FactoryBuilder* fb = new FactoryBuilder();
    if (contractionModifierCheckbox) fb->withPreMatchingModifier(new ContractionModifier());
    if (urlModifierCheckbox) fb->withPreMatchingModifier(new UrlModifier());
    if (pontModifierCheckbox) fb->withPreMatchingModifier(new PonctModifier());
    if (basicModifierCheckbox) fb->withPreMatchingModifier(new LaposApiModifier());
    if (dateModifierCheckbox) fb->withPreMatchingModifier(new DateModifier());
    if (corpModifierCheckbox) fb->withPreMatchingModifier(new CorpModifier());

    Factory* factory = fb->build();

    sentence = factory->run(textInput.toStdString(), true);

    std::string resultText = sentence->toStringPosProcessWithDebug();
    qInfo() << QString::fromStdString(resultText);

    ui->resultTxt->setPlainText("");

    textAppend();
}

void MainWindow::textAppend()
{
    QTextCursor cursor(ui->resultTxt->textCursor());
    for(Token* token : sentence->getTokenSentence()) {
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(QString::fromStdString(token->getPostProcessingString()));
        QApplication::processEvents();
        QThread::msleep(50);
    }
}

void MainWindow::handleWordClicked(const QString &word, __attribute__((unused)) int wordIndex)
{   
    if(word == "") {
        ui->PosTagLabel->setText("");
        return;
    }    

    Token* token = getTokenFromWord(word);
    if(token == nullptr) {
        ui->PosTagLabel->setText("");
    } else {
        if(token->getPosTag() == NONE) {
            ui->PosTagLabel->setText(QString::fromStdString(
                "No tag found"));
        } else {
            ui->PosTagLabel->setText(QString::fromStdString(
                "Tags: " + getPosTagInfo(token->getPosTag()).tagName + "\n" +
                "Info: " + getPosTagInfo(token->getPosTag()).description
            ));
        }
        
    }
}

Token* MainWindow::getTokenFromWord(const QString &word) {
    for(Token* token : sentence->getTokenSentence()) {
        QString qstr = QString::fromStdString(token->getPostProcessingString());
        if(qstr == word) {
            return token;
        }
    }

    return nullptr;
}