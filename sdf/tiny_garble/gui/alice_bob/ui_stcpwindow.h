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
    QPushButton *getInput_button;
    QLabel *hostLabel;
    QFrame *line;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *output;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *input0;
    QLineEdit *input1;
    QWidget *tab_3;

    void setupUi(QMainWindow *STCPWindow)
    {
        if (STCPWindow->objectName().isEmpty())
            STCPWindow->setObjectName(QStringLiteral("STCPWindow"));
        STCPWindow->resize(411, 330);
        STCPWindow->setStyleSheet(QStringLiteral("background-color: rgb(220, 220, 220);"));
        centralwidget = new QWidget(STCPWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 411, 331));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(400, 0));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(160, 160, 160);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setIconSize(QSize(16, 16));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        start_button = new QPushButton(tab);
        start_button->setObjectName(QStringLiteral("start_button"));
        start_button->setGeometry(QRect(260, 160, 121, 61));
        start_button->setStyleSheet(QStringLiteral("background-color: rgb(193, 125, 17);"));
        getInput_button = new QPushButton(tab);
        getInput_button->setObjectName(QStringLiteral("getInput_button"));
        getInput_button->setGeometry(QRect(260, 80, 121, 61));
        getInput_button->setStyleSheet(QStringLiteral("background-color: rgb(193, 125, 17);"));
        hostLabel = new QLabel(tab);
        hostLabel->setObjectName(QStringLiteral("hostLabel"));
        hostLabel->setGeometry(QRect(0, 0, 411, 61));
        QFont font;
        font.setPointSize(25);
        hostLabel->setFont(font);
        hostLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-10, 60, 421, 2));
        line->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 230, 351, 53));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(13);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        output = new QLineEdit(widget);
        output->setObjectName(QStringLiteral("output"));
        output->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        output->setAlignment(Qt::AlignCenter);
        output->setReadOnly(true);

        verticalLayout_2->addWidget(output);

        widget1 = new QWidget(tab);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 80, 201, 61));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        input0 = new QLineEdit(widget1);
        input0->setObjectName(QStringLiteral("input0"));
        input0->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input0->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(input0);

        input1 = new QLineEdit(widget1);
        input1->setObjectName(QStringLiteral("input1"));
        input1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        input1->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(input1);

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
        getInput_button->setText(QApplication::translate("STCPWindow", "GetInputs", nullptr));
        hostLabel->setText(QApplication::translate("STCPWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("STCPWindow", "Output", nullptr));
        input0->setPlaceholderText(QApplication::translate("STCPWindow", "Input 0", nullptr));
        input1->setPlaceholderText(QApplication::translate("STCPWindow", "Input 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("STCPWindow", "TinyGarble", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("STCPWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class STCPWindow: public Ui_STCPWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STCPWINDOW_H
