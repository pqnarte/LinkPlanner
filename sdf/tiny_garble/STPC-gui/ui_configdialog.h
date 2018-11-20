/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLineEdit *tgIpInput;
    QLineEdit *tgPortInput;
    QLabel *tgWarning;
    QDialogButtonBox *buttonBox_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QLineEdit *keyIpInput;
    QLineEdit *keyPortInput;
    QLabel *keyWarning;
    QLabel *label_2;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(400, 240);
        ConfigDialog->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        frame = new QFrame(ConfigDialog);
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
        tgIpInput = new QLineEdit(frame_2);
        tgIpInput->setObjectName(QStringLiteral("tgIpInput"));
        tgIpInput->setGeometry(QRect(10, 10, 251, 25));
        tgIpInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        tgIpInput->setAlignment(Qt::AlignCenter);
        tgPortInput = new QLineEdit(frame_2);
        tgPortInput->setObjectName(QStringLiteral("tgPortInput"));
        tgPortInput->setGeometry(QRect(270, 10, 101, 25));
        tgPortInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        tgPortInput->setAlignment(Qt::AlignCenter);
        tgWarning = new QLabel(frame_2);
        tgWarning->setObjectName(QStringLiteral("tgWarning"));
        tgWarning->setGeometry(QRect(0, 40, 381, 20));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        tgWarning->setFont(font);
        tgWarning->setMouseTracking(true);
        tgWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        tgWarning->setAlignment(Qt::AlignCenter);
        buttonBox_2 = new QDialogButtonBox(ConfigDialog);
        buttonBox_2->setObjectName(QStringLiteral("buttonBox_2"));
        buttonBox_2->setGeometry(QRect(120, 200, 161, 41));
        buttonBox_2->setOrientation(Qt::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);
        buttonBox_2->setCenterButtons(true);
        frame_3 = new QFrame(ConfigDialog);
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
        keyIpInput = new QLineEdit(frame_4);
        keyIpInput->setObjectName(QStringLiteral("keyIpInput"));
        keyIpInput->setGeometry(QRect(10, 10, 251, 25));
        keyIpInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        keyIpInput->setAlignment(Qt::AlignCenter);
        keyPortInput = new QLineEdit(frame_4);
        keyPortInput->setObjectName(QStringLiteral("keyPortInput"));
        keyPortInput->setGeometry(QRect(270, 10, 101, 25));
        keyPortInput->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"border:2px solid black;"));
        keyPortInput->setAlignment(Qt::AlignCenter);
        keyWarning = new QLabel(frame_4);
        keyWarning->setObjectName(QStringLiteral("keyWarning"));
        keyWarning->setGeometry(QRect(0, 40, 381, 20));
        keyWarning->setFont(font);
        keyWarning->setMouseTracking(true);
        keyWarning->setStyleSheet(QStringLiteral("color:rgb(204, 0, 0);"));
        keyWarning->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 3, 381, 20));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(ConfigDialog);

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ConfigDialog", "Tiny Garble network configuration", nullptr));
        tgIpInput->setText(QString());
        tgIpInput->setPlaceholderText(QApplication::translate("ConfigDialog", "Insert Alice IP adress", nullptr));
        tgPortInput->setText(QString());
        tgPortInput->setPlaceholderText(QApplication::translate("ConfigDialog", "Insert PORT", nullptr));
        tgWarning->setText(QApplication::translate("ConfigDialog", "<html><head/><body><p><br/></p></body></html>", nullptr));
        keyIpInput->setText(QString());
        keyIpInput->setPlaceholderText(QApplication::translate("ConfigDialog", "Insert the Key provider IP adress", nullptr));
        keyPortInput->setText(QString());
        keyPortInput->setPlaceholderText(QApplication::translate("ConfigDialog", "Insert PORT", nullptr));
        keyWarning->setText(QApplication::translate("ConfigDialog", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("ConfigDialog", "Key provider network configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
