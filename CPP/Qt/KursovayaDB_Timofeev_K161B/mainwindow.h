#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define HOSTNAME "localhost"
#define PATH     "C:/Qt/KursovayaDB_Timofeev_K161B/DB/test/BERUA_Of_TECH_INVENTORY.sqlite"
#define USERNAME "root"
#define PASSWORD "1703"

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QSqlRecord>
#include <QSqlRelationalDelegate>
#include <QObject>
#include <QFile>
#include <QDebug>

#include "CreateTableWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void addNewTable();

    void onPrimeInsert(int row, QSqlRecord &record);

    void setRelationInfo(QString relationTableName);

    void on_add_clicked();

    void on_managment_clicked(const QModelIndex &index);

    void on_comboBox_activated(int index);

    void on_save_clicked();

    void on_cancel_clicked();

    void on_addTable_clicked();

    void on_sqlRequestLineEdit_editingFinished();

    void on_del_clicked();

    void on_delTabel_clicked();

signals:
    void sendInfo(QStringList colsNamesList);

private:
    Ui::MainWindow *ui;

    QSqlDatabase db;
    QSqlRelationalTableModel *model;
    QSqlQueryModel *qmodel;

    QString currTable;
    int selectedRowIndex;

    CreateTableWidget createTableWidget;

    void createRequest(QString request);
    void createDataBase();
    void setComboBoxItems();
};
#endif // MAINWINDOW_H
