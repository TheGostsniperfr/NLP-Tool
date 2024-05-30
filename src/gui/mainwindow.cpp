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
    qInfo() << textInput;

    // Get modifiers :
    bool basicModifierCheckbox = ui->basicModifierCheckbox->isChecked();
    bool urlModifierCheckbox = ui->urlModifierCheckbox->isChecked();
    bool pontModifierCheckbox = ui->ponctModifierCheckbox->isChecked();
    bool dateModifierCheckbox = ui->dateModifierCheckbox->isChecked();

    qInfo() << "basicModifierCheckbox:" << basicModifierCheckbox;
    qInfo() << "urlModifierCheckbox:" << urlModifierCheckbox;
    qInfo() << "pontModifierCheckbox:" << pontModifierCheckbox;
    qInfo() << "dateModifierCheckbox:" << dateModifierCheckbox;

    FactoryBuilder* fb = new FactoryBuilder();
    if (dateModifierCheckbox) fb->withPreMatchingModifier(new ContractionModifier());
    if (urlModifierCheckbox) fb->withPreMatchingModifier(new UrlModifier());
    if (pontModifierCheckbox) fb->withPreMatchingModifier(new PonctModifier());
    if (basicModifierCheckbox) fb->withPreMatchingModifier(new LaposApiModifier());

    Factory* factory = fb->build();

    Sentence* sentence = factory->run(textInput.toStdString(), true);

    std::string resultText = sentence->toStringPosProcessWithDebug();
    qInfo() << QString::fromStdString(resultText);

    ui->resultTxt->setPlainText("");

    textAppend(sentence);
}

void MainWindow::textAppend(Sentence* sentence)
{
    QTextCursor cursor(ui->resultTxt->textCursor());
    for(Token* token : sentence->getTokenSentence()) {
        cursor.movePosition(QTextCursor::End);
        cursor.insertText(QString::fromStdString(token->getPostProcessingString()));
        QApplication::processEvents();
        QThread::msleep(50);
    }
}

void MainWindow::handleWordClicked(const QString &word)
{
    qInfo() << "Word clicked:" << word;
}
