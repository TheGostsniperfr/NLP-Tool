#include "gui/mainwindow.hh"
#include "gui/ui_mainwindow.h"

#include "factory/Factory.hh"
#include "factory/FactoryBuilder.hh"

#include "preMatching/list/ContractionModifier.hh"
#include "preMatching/list/UrlModifier.hh"
#include "preMatching/list/PonctModifier.hh"
#include "preMatching/list/LaposApiModifier.hh"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    fb->withPreMatchingModifier(new ContractionModifier());
    fb->withPreMatchingModifier(new UrlModifier());
    fb->withPreMatchingModifier(new PonctModifier());
    fb->withPreMatchingModifier(new LaposApiModifier());

    Factory* factory = fb->build();

    Sentence* sentence = factory->run(textInput.toStdString(), true);

    string resultText = sentence->toStringPosProcessWithDebug();
    cout << resultText;

    ui->resultTxt->setPlainText(QString::fromStdString(resultText));

}

