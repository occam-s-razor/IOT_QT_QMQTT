/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *light;
    QTextEdit *fan;
    QTextEdit *light1;
    QLabel *video;
    QPushButton *pushButton_2;
    QTextEdit *UARTGET;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 210, 99, 27));
        light = new QTextEdit(centralWidget);
        light->setObjectName(QString::fromUtf8("light"));
        light->setGeometry(QRect(10, 110, 121, 31));
        fan = new QTextEdit(centralWidget);
        fan->setObjectName(QString::fromUtf8("fan"));
        fan->setGeometry(QRect(10, 70, 121, 31));
        light1 = new QTextEdit(centralWidget);
        light1->setObjectName(QString::fromUtf8("light1"));
        light1->setGeometry(QRect(10, 30, 121, 31));
        video = new QLabel(centralWidget);
        video->setObjectName(QString::fromUtf8("video"));
        video->setGeometry(QRect(140, 210, 640, 480));
        video->setMinimumSize(QSize(640, 480));
        video->setMaximumSize(QSize(640, 480));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 170, 99, 27));
        UARTGET = new QTextEdit(centralWidget);
        UARTGET->setObjectName(QString::fromUtf8("UARTGET"));
        UARTGET->setGeometry(QRect(190, 30, 121, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "SEND", nullptr));
        video->setText(QString());
        pushButton_2->setText(QApplication::translate("MainWindow", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
