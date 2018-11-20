/********************************************************************************
** Form generated from reading UI file 'networkconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKCONFIG_H
#define UI_NETWORKCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_networkConfig
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QLineEdit *portInput;
    QLabel *portWarning;
    QDialogButtonBox *buttonBox_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *portWarning_2;
    QLabel *label_2;

    void setupUi(QDialog *networkConfig)
    {
        if (networkConfig->objectName().isEmpty())
            networkConfig->setObjectName(QStringLiteral("networkConfig"));
        networkConfig->resize(400, 240);
        networkConfig->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        frame = new QFrame(networkConfig);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 381, 91));
        frame->setStyleSheet(QLatin1String("background-color: rgb(211, 215, 207);\n"
"border-radius:10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 3, 381, 20));
        label->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 26, 381, 65));
        frame_2->setStyleSheet(QLatin1String("border-top-left-radius:0px;\n"
"border-top-right-radius:0px;\n"
"background-color: rgb(127, 156, 150);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 251, 25));
        lineEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        lineEdit->setAlignment(Qt::AlignCenter);
        portInput = new QLineEdit(frame_2);
        portInput->setObjectName(QStringLiteral("portInput"));
        portInput->setGeometry(QRect(270, 10, 101, 25));
        portInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        portInput->setAlignment(Qt::AlignCenter);
        portWarning = new QLabel(frame_2);
        portWarning->setObjectName(QStringLiteral("portWarning"));
        portWarning->setGeometry(QRect(0, 40, 381, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        portWarning->setFont(font);
        portWarning->setMouseTracking(true);
        portWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        portWarning->setAlignment(Qt::AlignCenter);
        buttonBox_2 = new QDialogButtonBox(networkConfig);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(120, 200, 161, 41));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        frame_3 = new QFrame(networkConfig);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(10, 110, 381, 91));
        frame_3->setStyleSheet(QLatin1String("background-color: rgb(211, 215, 207);\n"
"border-radius:10px;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 26, 381, 65));
        frame_4->setStyleSheet(QLatin1String("\n"
"background-color: rgb(127, 156, 150);\n"
"border-top-left-radius:0px;\n"
"border-top-right-radius:0px;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 10, 251, 25));
        lineEdit_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_3 = new QLineEdit(frame_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(270, 10, 101, 25));
        lineEdit_3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        lineEdit_3->setAlignment(Qt::AlignCenter);
        portWarning_2 = new QLabel(frame_4);
        portWarning_2->setObjectName(QStringLiteral("portWarning_2"));
        portWarning_2->setGeometry(QRect(0, 40, 381, 20));
        portWarning_2->setFont(font);
        portWarning_2->setMouseTracking(true);
        portWarning_2->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        portWarning_2->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 3, 381, 20));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(networkConfig);

        QMetaObject::connectSlotsByName(networkConfig);
    } // setupUi

    void retranslateUi(QDialog *networkConfig)
    {
        networkConfig->setWindowTitle(QApplication::translate("networkConfig", "Dialog", nullptr));
        label->setText(QApplication::translate("networkConfig", "Tiny Garble network configuration", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("networkConfig", "Insert Alice IP adress", nullptr));
        portInput->setText(QString());
        portInput->setPlaceholderText(QApplication::translate("networkConfig", "Insert PORT", nullptr));
        portWarning->setText(QApplication::translate("networkConfig", "<html><head/><body><p>asdf</p></body></html>", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QApplication::translate("networkConfig", "Insert the Key provider IP adress", nullptr));
        lineEdit_3->setPlaceholderText(QApplication::translate("networkConfig", "Insert PORT", nullptr));
        portWarning_2->setText(QApplication::translate("networkConfig", "<html><head/><body><p>asdf</p></body></html>", nullptr));
        label_2->setText(QApplication::translate("networkConfig", "Key provider network configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class networkConfig: public Ui_networkConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKCONFIG_H
