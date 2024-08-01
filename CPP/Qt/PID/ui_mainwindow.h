/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QRadioButton *In_radioButton;
    QRadioButton *Out_radioButton;
    QRadioButton *PID_radioButton;
    QRadioButton *P_I_D_radioButton;
    QRadioButton *Err_radioButton;
    QRadioButton *BasePIDRadioButton;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *Step_radioButton;
    QRadioButton *SQRT_radioButton;
    QRadioButton *Sin_radioButton;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_6;
    QSpacerItem *verticalSpacer_3;
    QCustomPlot *plotLayOut;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1171, 914);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(11, -1, -1, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 1);
        startButton = new QPushButton(groupBox);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(startButton->sizePolicy().hasHeightForWidth());
        startButton->setSizePolicy(sizePolicy1);
        startButton->setMinimumSize(QSize(5, 2));
        startButton->setMaximumSize(QSize(60, 90));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        startButton->setFont(font);
        startButton->setAutoDefault(false);
        startButton->setFlat(false);

        horizontalLayout->addWidget(startButton);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        groupBox_5->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        In_radioButton = new QRadioButton(groupBox_5);
        In_radioButton->setObjectName(QString::fromUtf8("In_radioButton"));
        QFont font2;
        font2.setBold(false);
        font2.setUnderline(false);
        In_radioButton->setFont(font2);
        In_radioButton->setChecked(true);

        gridLayout_2->addWidget(In_radioButton, 0, 0, 1, 1);

        Out_radioButton = new QRadioButton(groupBox_5);
        Out_radioButton->setObjectName(QString::fromUtf8("Out_radioButton"));
        Out_radioButton->setFont(font2);

        gridLayout_2->addWidget(Out_radioButton, 1, 0, 1, 1);

        PID_radioButton = new QRadioButton(groupBox_5);
        PID_radioButton->setObjectName(QString::fromUtf8("PID_radioButton"));
        PID_radioButton->setFont(font2);

        gridLayout_2->addWidget(PID_radioButton, 0, 1, 1, 1);

        P_I_D_radioButton = new QRadioButton(groupBox_5);
        P_I_D_radioButton->setObjectName(QString::fromUtf8("P_I_D_radioButton"));
        P_I_D_radioButton->setFont(font2);

        gridLayout_2->addWidget(P_I_D_radioButton, 1, 1, 1, 1);

        Err_radioButton = new QRadioButton(groupBox_5);
        Err_radioButton->setObjectName(QString::fromUtf8("Err_radioButton"));
        Err_radioButton->setFont(font2);

        gridLayout_2->addWidget(Err_radioButton, 3, 0, 1, 1);

        BasePIDRadioButton = new QRadioButton(groupBox_5);
        BasePIDRadioButton->setObjectName(QString::fromUtf8("BasePIDRadioButton"));
        BasePIDRadioButton->setFont(font2);

        gridLayout_2->addWidget(BasePIDRadioButton, 3, 1, 1, 1);


        horizontalLayout->addWidget(groupBox_5);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Step_radioButton = new QRadioButton(groupBox_2);
        Step_radioButton->setObjectName(QString::fromUtf8("Step_radioButton"));
        Step_radioButton->setFont(font2);
        Step_radioButton->setChecked(true);

        verticalLayout_2->addWidget(Step_radioButton);

        SQRT_radioButton = new QRadioButton(groupBox_2);
        SQRT_radioButton->setObjectName(QString::fromUtf8("SQRT_radioButton"));
        SQRT_radioButton->setFont(font2);

        verticalLayout_2->addWidget(SQRT_radioButton);

        Sin_radioButton = new QRadioButton(groupBox_2);
        Sin_radioButton->setObjectName(QString::fromUtf8("Sin_radioButton"));
        Sin_radioButton->setFont(font2);

        verticalLayout_2->addWidget(Sin_radioButton);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFont(font1);
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(150);
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        doubleSpinBox = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        QFont font3;
        font3.setBold(false);
        font3.setUnderline(false);
        font3.setKerning(true);
        doubleSpinBox->setFont(font3);
        doubleSpinBox->setDecimals(5);
        doubleSpinBox->setMaximum(10000.000000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setFont(font3);
        doubleSpinBox_2->setDecimals(5);
        doubleSpinBox_2->setMaximum(1000.000000000000000);
        doubleSpinBox_2->setSingleStep(0.500000000000000);
        doubleSpinBox_2->setValue(3.000000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_2);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox_3);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setFont(font2);
        doubleSpinBox_3->setDecimals(5);
        doubleSpinBox_3->setMaximum(5.000000000000000);
        doubleSpinBox_3->setSingleStep(0.001000000000000);
        doubleSpinBox_3->setValue(0.010000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_3);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setFont(font1);
        formLayout_2 = new QFormLayout(groupBox_4);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setHorizontalSpacing(150);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setFont(font2);
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMinimum(-1000.000000000000000);
        doubleSpinBox_4->setMaximum(1000.000000000000000);
        doubleSpinBox_4->setSingleStep(0.500000000000000);
        doubleSpinBox_4->setValue(1.000000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox_4);

        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setFont(font2);
        doubleSpinBox_5->setDecimals(4);
        doubleSpinBox_5->setMinimum(-1000.000000000000000);
        doubleSpinBox_5->setMaximum(1000.000000000000000);
        doubleSpinBox_5->setSingleStep(0.500000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_5);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox_4);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setFont(font2);
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMinimum(-1000.000000000000000);
        doubleSpinBox_6->setMaximum(1000.000000000000000);
        doubleSpinBox_6->setSingleStep(0.500000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_6);


        horizontalLayout->addWidget(groupBox_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(4, 4);

        verticalLayout->addWidget(groupBox);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        plotLayOut = new QCustomPlot(centralwidget);
        plotLayOut->setObjectName(QString::fromUtf8("plotLayOut"));
        plotLayOut->setMinimumSize(QSize(1040, 620));
        plotLayOut->setBaseSize(QSize(400, 100));

        verticalLayout->addWidget(plotLayOut);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(2, 15);

        horizontalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1171, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        startButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Selectable", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Plot type", nullptr));
        In_radioButton->setText(QCoreApplication::translate("MainWindow", "Input", nullptr));
        Out_radioButton->setText(QCoreApplication::translate("MainWindow", "Output", nullptr));
        PID_radioButton->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        P_I_D_radioButton->setText(QCoreApplication::translate("MainWindow", "P & I & D", nullptr));
        Err_radioButton->setText(QCoreApplication::translate("MainWindow", "Error", nullptr));
        BasePIDRadioButton->setText(QCoreApplication::translate("MainWindow", "Base PID", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Functions", nullptr));
        Step_radioButton->setText(QCoreApplication::translate("MainWindow", "1(t)", nullptr));
        SQRT_radioButton->setText(QCoreApplication::translate("MainWindow", "sqrt(t)", nullptr));
        Sin_radioButton->setText(QCoreApplication::translate("MainWindow", "sin(t)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Time param", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "End", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "PID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Kp", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ki", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Kd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
