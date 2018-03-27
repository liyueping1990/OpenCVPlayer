/********************************************************************************
** Form generated from reading UI file 'OpenCVPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENCVPLAYER_H
#define UI_OPENCVPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "MyOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_OpenCVPlayerClass
{
public:
    QWidget *centralWidget;
    MyOpenGLWidget *openGLWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OpenCVPlayerClass)
    {
        if (OpenCVPlayerClass->objectName().isEmpty())
            OpenCVPlayerClass->setObjectName(QStringLiteral("OpenCVPlayerClass"));
        OpenCVPlayerClass->resize(600, 500);
        centralWidget = new QWidget(OpenCVPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openGLWidget = new MyOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 600, 400));
        openGLWidget->setMouseTracking(false);
        openGLWidget->setTabletTracking(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 410, 101, 41));
        OpenCVPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OpenCVPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        OpenCVPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OpenCVPlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OpenCVPlayerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OpenCVPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OpenCVPlayerClass->setStatusBar(statusBar);

        retranslateUi(OpenCVPlayerClass);
        QObject::connect(pushButton, SIGNAL(clicked()), OpenCVPlayerClass, SLOT(openCam()));

        QMetaObject::connectSlotsByName(OpenCVPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *OpenCVPlayerClass)
    {
        OpenCVPlayerClass->setWindowTitle(QApplication::translate("OpenCVPlayerClass", "OpenCVPlayer", nullptr));
        pushButton->setText(QApplication::translate("OpenCVPlayerClass", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OpenCVPlayerClass: public Ui_OpenCVPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENCVPLAYER_H
