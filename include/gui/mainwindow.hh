#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <vector>
#include <string>

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
    void addNextToken(); // Nouveau slot pour ajouter les tokens un par un

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    std::vector<std::string> tokenSentence; // Vecteur pour stocker les tokens
    size_t currentTokenIndex; // Indice du token actuel
};

#endif // MAINWINDOW_H
