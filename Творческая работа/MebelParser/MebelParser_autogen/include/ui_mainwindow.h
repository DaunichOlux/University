/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *searchInput;
    QPushButton *searchButton;
    QTableWidget *resultsTable;
    QLabel *label;
    QPushButton *findBestOfferButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1229, 683);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        searchInput = new QLineEdit(centralwidget);
        searchInput->setObjectName("searchInput");
        searchInput->setGeometry(QRect(10, 40, 181, 31));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(20, 90, 161, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        searchButton->setFont(font);
        resultsTable = new QTableWidget(centralwidget);
        resultsTable->setObjectName("resultsTable");
        resultsTable->setGeometry(QRect(210, 40, 971, 591));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 0, 301, 31));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        label->setFont(font1);
        findBestOfferButton = new QPushButton(centralwidget);
        findBestOfferButton->setObjectName("findBestOfferButton");
        findBestOfferButton->setGeometry(QRect(20, 160, 162, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1229, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MebelParser", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\202\320\260\320\273\320\276\320\263 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\262", nullptr));
        findBestOfferButton->setText(QCoreApplication::translate("MainWindow", "\320\233\321\203\321\207\321\210\320\265\320\265 \320\277\321\200\320\265\320\264\320\273\320\276\320\266\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
