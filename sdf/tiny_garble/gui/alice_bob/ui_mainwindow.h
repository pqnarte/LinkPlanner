/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *alice_button;
    QPushButton *bob_button;
    QLineEdit *portInput;
    QLineEdit *functionsLoc;
    QLineEdit *tinyGarbleLoc;
    QToolButton *tinyGarbleDir;
    QToolButton *functionsDir;
    QLabel *tbWarning;
    QLabel *fWarning;
    QLabel *portWarning;
    QFrame *line_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(420, 283);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(160, 160, 160);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        alice_button = new QPushButton(centralWidget);
        alice_button->setObjectName(QStringLiteral("alice_button"));
        alice_button->setGeometry(QRect(20, 20, 181, 71));
        QFont font;
        font.setPointSize(15);
        alice_button->setFont(font);
        alice_button->setStyleSheet(QStringLiteral("background-color: rgb(193, 125, 17);"));
        bob_button = new QPushButton(centralWidget);
        bob_button->setObjectName(QStringLiteral("bob_button"));
        bob_button->setGeometry(QRect(220, 20, 181, 71));
        bob_button->setFont(font);
        bob_button->setStyleSheet(QStringLiteral("background-color: rgb(193, 125, 17);"));
        portInput = new QLineEdit(centralWidget);
        portInput->setObjectName(QStringLiteral("portInput"));
        portInput->setGeometry(QRect(150, 230, 121, 25));
        portInput->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        portInput->setAlignment(Qt::AlignCenter);
        functionsLoc = new QLineEdit(centralWidget);
        functionsLoc->setObjectName(QStringLiteral("functionsLoc"));
        functionsLoc->setGeometry(QRect(20, 180, 341, 25));
        functionsLoc->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        functionsLoc->setAlignment(Qt::AlignCenter);
        tinyGarbleLoc = new QLineEdit(centralWidget);
        tinyGarbleLoc->setObjectName(QStringLiteral("tinyGarbleLoc"));
        tinyGarbleLoc->setGeometry(QRect(20, 130, 341, 25));
        tinyGarbleLoc->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        tinyGarbleLoc->setAlignment(Qt::AlignCenter);
        tinyGarbleDir = new QToolButton(centralWidget);
        tinyGarbleDir->setObjectName(QStringLiteral("tinyGarbleDir"));
        tinyGarbleDir->setGeometry(QRect(370, 130, 31, 24));
        tinyGarbleDir->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));
        functionsDir = new QToolButton(centralWidget);
        functionsDir->setObjectName(QStringLiteral("functionsDir"));
        functionsDir->setGeometry(QRect(370, 180, 31, 24));
        functionsDir->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));
        tbWarning = new QLabel(centralWidget);
        tbWarning->setObjectName(QStringLiteral("tbWarning"));
        tbWarning->setGeometry(QRect(20, 157, 381, 20));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        tbWarning->setFont(font1);
        tbWarning->setMouseTracking(true);
        tbWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        tbWarning->setAlignment(Qt::AlignCenter);
        fWarning = new QLabel(centralWidget);
        fWarning->setObjectName(QStringLiteral("fWarning"));
        fWarning->setGeometry(QRect(20, 207, 381, 20));
        fWarning->setFont(font1);
        fWarning->setMouseTracking(true);
        fWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        fWarning->setAlignment(Qt::AlignCenter);
        portWarning = new QLabel(centralWidget);
        portWarning->setObjectName(QStringLiteral("portWarning"));
        portWarning->setGeometry(QRect(20, 257, 381, 20));
        portWarning->setFont(font1);
        portWarning->setMouseTracking(true);
        portWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        portWarning->setAlignment(Qt::AlignCenter);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 110, 421, 2));
        line_2->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        alice_button->setText(QApplication::translate("MainWindow", "Alice", nullptr));
        bob_button->setText(QApplication::translate("MainWindow", "Bob", nullptr));
        portInput->setText(QString());
        portInput->setPlaceholderText(QApplication::translate("MainWindow", "Insert PORT", nullptr));
        functionsLoc->setText(QString());
        functionsLoc->setPlaceholderText(QApplication::translate("MainWindow", "Insert path to the folder containing scd files", nullptr));
        tinyGarbleLoc->setText(QString());
        tinyGarbleLoc->setPlaceholderText(QApplication::translate("MainWindow", "Insert path to TinyGarble directory", nullptr));
        tinyGarbleDir->setText(QApplication::translate("MainWindow", "...", nullptr));
        functionsDir->setText(QApplication::translate("MainWindow", "...", nullptr));
        tbWarning->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        fWarning->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        portWarning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
