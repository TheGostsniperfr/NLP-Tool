#include "gui/mainwindow.hh"
#include "gui/ui_mainwindow.h"


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
    QString text = ui->inputTxt->toPlainText();
    qInfo() << text;

    // Get modifiers :
    bool basicModifierCheckbox = ui->basicModifierCheckbox->isChecked();
    bool urlModifierCheckbox = ui->urlModifierCheckbox->isChecked();
    bool pontModifierCheckbox = ui->ponctModifierCheckbox->isChecked();
    bool dateModifierCheckbox = ui->dateModifierCheckbox->isChecked();

    qInfo() << "basicModifierCheckbox:" << basicModifierCheckbox;
    qInfo() << "urlModifierCheckbox:" << urlModifierCheckbox;
    qInfo() << "pontModifierCheckbox:" << pontModifierCheckbox;
    qInfo() << "dateModifierCheckbox:" << dateModifierCheckbox;
}

