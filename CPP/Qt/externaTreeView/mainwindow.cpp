#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fstv = new FileSystemTreeView(this);
    ui->verticalLayout->addWidget(fstv);
    connect(ui->le, &QLineEdit::editingFinished, fstv, [this](){fstv->getPath(ui->le->text());});
}

MainWindow::~MainWindow()
{
    delete fstv;
    delete ui;
}

