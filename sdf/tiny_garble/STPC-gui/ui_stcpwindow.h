/********************************************************************************
** Form generated from reading UI file 'stcpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STCPWINDOW_H
#define UI_STCPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_STCPWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *start_button;
    QLabel *hostLabel;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *output;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *input0;
    QLineEdit *input1;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QLabel *socketLabel;
    QLabel *messageLabel;
    QPushButton *getInput_button;
    QWidget *tab_3;

    void setupUi(QMainWindow *STCPWindow)
    {
        if (STCPWindow->objectName().isEmpty())
            STCPWindow->setObjectName(QStringLiteral("STCPWindow"));
        STCPWindow->resize(455, 340);
        STCPWindow->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        centralwidget = new QWidget(STCPWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(1, 0, 454, 325));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(400, 0));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setIconSize(QSize(16, 16));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        start_button = new QPushButton(tab);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(310, 80, 121, 60));
        QFont font;
        font.setPointSize(12);
        start_button->setFont(font);
        start_button->setStyleSheet(QStringLiteral("background-color: rgb(163, 109, 22);"));
        hostLabel = new QLabel(tab);
        hostLabel->setObjectName(QStringLiteral("hostLabel"));
        hostLabel->setGeometry(QRect(0, 0, 446, 61));
        QFont font1;
        font1.setPointSize(25);
        hostLabel->setFont(font1);
        hostLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-10, 60, 461, 1));
        line->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 230, 151, 53));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font2;
        font2.setPointSize(13);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        output = new QLineEdit(layoutWidget);
        output->setObjectName(QStringLiteral("output"));
        output->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:8px;\n"
"border:2px solid black;"));
        output->setAlignment(Qt::AlignCenter);
        output->setReadOnly(true);

        verticalLayout_2->addWidget(output);

        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 80, 131, 61));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        input0 = new QLineEdit(layoutWidget1);
        input0->setObjectName(QStringLiteral("input0"));
        input0->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:8px;\n"
"border:2px solid black;"));
        input0->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(input0);

        input1 = new QLineEdit(layoutWidget1);
        input1->setObjectName(QStringLiteral("input1"));
        input1->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:8px;\n"
"border:2px solid black;"));
        input1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(input1);

        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 160, 411, 61));
        frame->setStyleSheet(QLatin1String("background-color: rgb(67, 116, 180);\n"
"border-radius:20px;\n"
"border: 1px solid black;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        socketLabel = new QLabel(frame);
        socketLabel->setObjectName(QStringLiteral("socketLabel"));
        QFont font3;
        font3.setFamily(QStringLiteral("Ubuntu"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        socketLabel->setFont(font3);
        socketLabel->setStyleSheet(QStringLiteral("border: 0px solid black;"));
        socketLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(socketLabel);

        messageLabel = new QLabel(frame);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        messageLabel->setFont(font3);
        messageLabel->setStyleSheet(QStringLiteral("border: 0px solid black;"));
        messageLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(messageLabel);

        getInput_button = new QPushButton(tab);
        getInput_button->setObjectName(QStringLiteral("getInput_button"));
        getInput_button->setGeometry(QRect(20, 80, 121, 60));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(getInput_button->sizePolicy().hasHeightForWidth());
        getInput_button->setSizePolicy(sizePolicy1);
        getInput_button->setFont(font);
        getInput_button->setStyleSheet(QStringLiteral("background-color: rgb(163, 109, 22);"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        STCPWindow->setCentralWidget(centralwidget);

        retranslateUi(STCPWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(STCPWindow);
    } // setupUi

    void retranslateUi(QMainWindow *STCPWindow)
    {
        STCPWindow->setWindowTitle(QApplication::translate("STCPWindow", "MainWindow", nullptr));
        start_button->setText(QApplication::translate("STCPWindow", "Start", nullptr));
        hostLabel->setText(QApplication::translate("STCPWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("STCPWindow", "Output", nullptr));
        input0->setPlaceholderText(QApplication::translate("STCPWindow", "Input 0", nullptr));
        input1->setPlaceholderText(QApplication::translate("STCPWindow", "Input 1", nullptr));
        socketLabel->setText(QString());
        messageLabel->setText(QApplication::translate("STCPWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
        getInput_button->setText(QApplication::translate("STCPWindow", "GetInputs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("STCPWindow", "TinyGarble", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("STCPWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class STCPWindow: public Ui_STCPWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STCPWINDOW_H
