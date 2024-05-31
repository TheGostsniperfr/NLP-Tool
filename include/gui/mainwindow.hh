#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <vector>
#include <string>
#include <QThread>
#include <QTextCursor>

#include "factory/Factory.hh"
#include "factory/FactoryBuilder.hh"

#include "preMatching/list/ContractionModifier.hh"
#include "preMatching/list/UrlModifier.hh"
#include "preMatching/list/PonctModifier.hh"
#include "preMatching/list/LaposApiModifier.hh"

#include "gui/clickableTextEdit.hh"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void textAppend();
    void handleWordClicked(const QString &word, int wordIndex);
    Token* getTokenFromWord(const QString &word);
private:
    Ui::MainWindow *ui;
    Sentence* sentence;


};

#endif // MAINWINDOW_H
