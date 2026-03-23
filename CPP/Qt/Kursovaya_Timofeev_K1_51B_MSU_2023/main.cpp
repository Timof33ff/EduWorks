#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    std::setlocale(LC_ALL, "rus");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
