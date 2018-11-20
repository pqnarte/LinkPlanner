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
    QLineEdit *functionsLoc;
    QLineEdit *tinyGarbleLoc;
    QToolButton *tinyGarbleDir;
    QToolButton *functionsDir;
    QLabel *tgWarning;
    QLabel *fWarning;
    QFrame *line_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(420, 230);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        alice_button = new QPushButton(centralWidget);
        alice_button->setObjectName(QStringLiteral("alice_button"));
        alice_button->setGeometry(QRect(20, 20, 181, 71));
        QFont font;
        font.setPointSize(15);
        alice_button->setFont(font);
        alice_button->setStyleSheet(QStringLiteral("background-color: rgb(163, 109, 22);"));
        alice_button->setCheckable(false);
        alice_button->setChecked(false);
        bob_button = new QPushButton(centralWidget);
        bob_button->setObjectName(QStringLiteral("bob_button"));
        bob_button->setGeometry(QRect(220, 20, 181, 71));
        bob_button->setFont(font);
        bob_button->setStyleSheet(QStringLiteral("background-color: rgb(163, 109, 22);"));
        bob_button->setCheckable(false);
        bob_button->setChecked(false);
        functionsLoc = new QLineEdit(centralWidget);
        functionsLoc->setObjectName(QStringLiteral("functionsLoc"));
        functionsLoc->setGeometry(QRect(20, 180, 341, 25));
        functionsLoc->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        functionsLoc->setAlignment(Qt::AlignCenter);
        tinyGarbleLoc = new QLineEdit(centralWidget);
        tinyGarbleLoc->setObjectName(QStringLiteral("tinyGarbleLoc"));
        tinyGarbleLoc->setGeometry(QRect(20, 130, 341, 25));
        tinyGarbleLoc->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        tinyGarbleLoc->setAlignment(Qt::AlignCenter);
        tinyGarbleDir = new QToolButton(centralWidget);
        tinyGarbleDir->setObjectName(QStringLiteral("tinyGarbleDir"));
        tinyGarbleDir->setGeometry(QRect(370, 130, 31, 24));
        tinyGarbleDir->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));
        functionsDir = new QToolButton(centralWidget);
        functionsDir->setObjectName(QStringLiteral("functionsDir"));
        functionsDir->setGeometry(QRect(370, 180, 31, 24));
        QFont font1;
        font1.setPointSize(11);
        functionsDir->setFont(font1);
        functionsDir->setStyleSheet(QStringLiteral("background-color: rgb(186, 189, 182);"));
        tgWarning = new QLabel(centralWidget);
        tgWarning->setObjectName(QStringLiteral("tgWarning"));
        tgWarning->setGeometry(QRect(20, 157, 381, 20));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        tgWarning->setFont(font2);
        tgWarning->setMouseTracking(true);
        tgWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        tgWarning->setAlignment(Qt::AlignCenter);
        fWarning = new QLabel(centralWidget);
        fWarning->setObjectName(QStringLiteral("fWarning"));
        fWarning->setGeometry(QRect(20, 207, 381, 20));
        fWarning->setFont(font2);
        fWarning->setMouseTracking(true);
        fWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        fWarning->setAlignment(Qt::AlignCenter);
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
        functionsLoc->setText(QApplication::translate("MainWindow", "/home/enamak/circuits/moda", nullptr));
        functionsLoc->setPlaceholderText(QApplication::translate("MainWindow", "Insert path to the folder containing scd files", nullptr));
        tinyGarbleLoc->setText(QString());
        tinyGarbleLoc->setPlaceholderText(QApplication::translate("MainWindow", "Insert path to TinyGarble directory", nullptr));
        tinyGarbleDir->setText(QApplication::translate("MainWindow", "...", nullptr));
        functionsDir->setText(QApplication::translate("MainWindow", "...", nullptr));
        tgWarning->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        fWarning->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
