/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtFirstNb;
    QLineEdit *txtSecondNb;
    QPushButton *addBtn;
    QPushButton *minusBtn;
    QPushButton *multBtn;
    QPushButton *diviBtn;
    QLabel *label_3;
    QLineEdit *txtResulatNb;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(678, 362);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 100, 101, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 130, 101, 31));
        txtFirstNb = new QLineEdit(centralwidget);
        txtFirstNb->setObjectName(QString::fromUtf8("txtFirstNb"));
        txtFirstNb->setGeometry(QRect(230, 100, 113, 24));
        txtSecondNb = new QLineEdit(centralwidget);
        txtSecondNb->setObjectName(QString::fromUtf8("txtSecondNb"));
        txtSecondNb->setGeometry(QRect(230, 130, 113, 24));
        addBtn = new QPushButton(centralwidget);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(140, 200, 41, 24));
        minusBtn = new QPushButton(centralwidget);
        minusBtn->setObjectName(QString::fromUtf8("minusBtn"));
        minusBtn->setGeometry(QRect(200, 200, 41, 24));
        multBtn = new QPushButton(centralwidget);
        multBtn->setObjectName(QString::fromUtf8("multBtn"));
        multBtn->setGeometry(QRect(260, 200, 41, 24));
        diviBtn = new QPushButton(centralwidget);
        diviBtn->setObjectName(QString::fromUtf8("diviBtn"));
        diviBtn->setGeometry(QRect(320, 200, 41, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 250, 101, 31));
        txtResulatNb = new QLineEdit(centralwidget);
        txtResulatNb->setObjectName(QString::fromUtf8("txtResulatNb"));
        txtResulatNb->setGeometry(QRect(230, 250, 113, 24));
        txtResulatNb->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "First Number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Second Number", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        minusBtn->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multBtn->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        diviBtn->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "The result is", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
