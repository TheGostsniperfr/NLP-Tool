#include "gui/mainwindow.hh"
#include "gui/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addBtn, &QPushButton::clicked, this, [this]() { calculate([](int a, int b) { return a + b; }); });
    connect(ui->minusBtn, &QPushButton::clicked, this, [this]() { calculate([](int a, int b) { return a - b; }); });
    connect(ui->multBtn, &QPushButton::clicked, this, [this]() { calculate([](int a, int b) { return a * b; }); });
    connect(ui->diviBtn, &QPushButton::clicked, this, [this]() { calculate([](int a, int b) { return a / b; }); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate(std::function<int(int, int)> operation)
{
    int firstNb = this->ui->txtFirstNb->text().toInt();
    int secondNb = this->ui->txtSecondNb->text().toInt();
    int result = operation(firstNb, secondNb);
    this->ui->txtResulatNb->setText(QString::number(result));
}
