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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QRadioButton *velocity;
    QRadioButton *height;
    QRadioButton *tangazh;
    QRadioButton *trajectoryAngle;
    QRadioButton *tyaga;
    QRadioButton *angleVelocity;
    QRadioButton *atackAngle;
    QRadioButton *dp;
    QRadioButton *heightControl;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QDoubleSpinBox *start_spinbox;
    QDoubleSpinBox *step_spinbox;
    QLabel *label_4;
    QDoubleSpinBox *end_spinbox;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *I_spinbox;
    QLabel *label;
    QDoubleSpinBox *P_spinbox;
    QDoubleSpinBox *D_spinbox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_10;
    QDoubleSpinBox *setH_spinbox;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *DSpinBox;
    QDoubleSpinBox *ISpinBox;
    QLabel *label_9;
    QDoubleSpinBox *PSpinBox;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_11;
    QDoubleSpinBox *setV_spinbox;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 1147);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_10 = new QWidget(centralwidget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout = new QHBoxLayout(widget_10);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(widget_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        groupBox_2 = new QGroupBox(widget_10);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        velocity = new QRadioButton(groupBox_2);
        velocity->setObjectName(QString::fromUtf8("velocity"));

        gridLayout->addWidget(velocity, 1, 0, 1, 1);

        height = new QRadioButton(groupBox_2);
        height->setObjectName(QString::fromUtf8("height"));

        gridLayout->addWidget(height, 0, 0, 1, 1);

        tangazh = new QRadioButton(groupBox_2);
        tangazh->setObjectName(QString::fromUtf8("tangazh"));

        gridLayout->addWidget(tangazh, 2, 1, 1, 1);

        trajectoryAngle = new QRadioButton(groupBox_2);
        trajectoryAngle->setObjectName(QString::fromUtf8("trajectoryAngle"));

        gridLayout->addWidget(trajectoryAngle, 3, 1, 1, 1);

        tyaga = new QRadioButton(groupBox_2);
        tyaga->setObjectName(QString::fromUtf8("tyaga"));

        gridLayout->addWidget(tyaga, 3, 0, 1, 1);

        angleVelocity = new QRadioButton(groupBox_2);
        angleVelocity->setObjectName(QString::fromUtf8("angleVelocity"));

        gridLayout->addWidget(angleVelocity, 2, 0, 1, 1);

        atackAngle = new QRadioButton(groupBox_2);
        atackAngle->setObjectName(QString::fromUtf8("atackAngle"));

        gridLayout->addWidget(atackAngle, 1, 1, 1, 1);

        dp = new QRadioButton(groupBox_2);
        dp->setObjectName(QString::fromUtf8("dp"));

        gridLayout->addWidget(dp, 4, 0, 1, 1);

        heightControl = new QRadioButton(groupBox_2);
        heightControl->setObjectName(QString::fromUtf8("heightControl"));

        gridLayout->addWidget(heightControl, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(widget_10);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        start_spinbox = new QDoubleSpinBox(groupBox_4);
        start_spinbox->setObjectName(QString::fromUtf8("start_spinbox"));

        gridLayout_3->addWidget(start_spinbox, 0, 1, 1, 1);

        step_spinbox = new QDoubleSpinBox(groupBox_4);
        step_spinbox->setObjectName(QString::fromUtf8("step_spinbox"));
        step_spinbox->setDecimals(3);
        step_spinbox->setMaximum(10.000000000000000);
        step_spinbox->setSingleStep(0.001000000000000);
        step_spinbox->setValue(0.010000000000000);

        gridLayout_3->addWidget(step_spinbox, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        end_spinbox = new QDoubleSpinBox(groupBox_4);
        end_spinbox->setObjectName(QString::fromUtf8("end_spinbox"));
        end_spinbox->setSingleStep(0.500000000000000);
        end_spinbox->setValue(1.000000000000000);

        gridLayout_3->addWidget(end_spinbox, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(widget_10);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        I_spinbox = new QDoubleSpinBox(groupBox_3);
        I_spinbox->setObjectName(QString::fromUtf8("I_spinbox"));
        I_spinbox->setSingleStep(0.020000000000000);

        gridLayout_2->addWidget(I_spinbox, 2, 1, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        P_spinbox = new QDoubleSpinBox(groupBox_3);
        P_spinbox->setObjectName(QString::fromUtf8("P_spinbox"));
        P_spinbox->setSingleStep(0.020000000000000);
        P_spinbox->setValue(1.000000000000000);

        gridLayout_2->addWidget(P_spinbox, 1, 1, 1, 1);

        D_spinbox = new QDoubleSpinBox(groupBox_3);
        D_spinbox->setObjectName(QString::fromUtf8("D_spinbox"));
        D_spinbox->setSingleStep(0.020000000000000);

        gridLayout_2->addWidget(D_spinbox, 3, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 0, 0, 1, 1);

        setH_spinbox = new QDoubleSpinBox(groupBox_3);
        setH_spinbox->setObjectName(QString::fromUtf8("setH_spinbox"));
        setH_spinbox->setMaximum(10000.000000000000000);
        setH_spinbox->setValue(150.000000000000000);

        gridLayout_2->addWidget(setH_spinbox, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(widget_10);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        DSpinBox = new QDoubleSpinBox(groupBox_5);
        DSpinBox->setObjectName(QString::fromUtf8("DSpinBox"));
        DSpinBox->setSingleStep(0.020000000000000);

        gridLayout_4->addWidget(DSpinBox, 3, 1, 1, 1);

        ISpinBox = new QDoubleSpinBox(groupBox_5);
        ISpinBox->setObjectName(QString::fromUtf8("ISpinBox"));
        ISpinBox->setSingleStep(0.020000000000000);

        gridLayout_4->addWidget(ISpinBox, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 3, 0, 1, 1);

        PSpinBox = new QDoubleSpinBox(groupBox_5);
        PSpinBox->setObjectName(QString::fromUtf8("PSpinBox"));
        PSpinBox->setSingleStep(0.020000000000000);
        PSpinBox->setValue(1.000000000000000);

        gridLayout_4->addWidget(PSpinBox, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        setV_spinbox = new QDoubleSpinBox(groupBox_5);
        setV_spinbox->setObjectName(QString::fromUtf8("setV_spinbox"));
        setV_spinbox->setMaximum(1000.000000000000000);
        setV_spinbox->setValue(250.000000000000000);

        gridLayout_4->addWidget(setV_spinbox, 0, 1, 1, 1);


        horizontalLayout->addWidget(groupBox_5);


        horizontalLayout_2->addWidget(widget_10);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QCustomPlot(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_3->addWidget(widget);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(1, 20);

        verticalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1033, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", nullptr));
        velocity->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        height->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        tangazh->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \321\202\320\260\320\275\320\263\320\260\320\266\320\260", nullptr));
        trajectoryAngle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\275\320\260\320\272\320\273\320\276\320\275\320\260 \321\202\321\200\320\260\320\265\320\272\321\202\320\276\321\200\320\270\320\270", nullptr));
        tyaga->setText(QCoreApplication::translate("MainWindow", "\320\242\321\217\320\263\320\260", nullptr));
        angleVelocity->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\273\320\276\320\262\320\260\321\217 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        atackAngle->setText(QCoreApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\260\321\202\320\260\320\272\320\270", nullptr));
        dp->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\202\320\276\321\200 \321\202\321\217\320\263\320\270", nullptr));
        heightControl->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\320\273\321\214 \320\262\321\213\321\201\320\276\321\202\321\213", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\275\320\270\321\210", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\202\320\276\321\200 \320\277\320\276 \320\262\321\213\321\201\320\276\321\202\320\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264. \320\262\321\213\321\201\320\276\321\202\320\260", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\202\320\276\321\200 \320\277\320\276 \321\202\321\217\320\263\320\265", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264. \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
