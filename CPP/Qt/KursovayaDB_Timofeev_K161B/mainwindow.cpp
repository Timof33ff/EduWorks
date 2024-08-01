#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    createDataBase();   // set DB name     // set DB tables

    model = new QSqlRelationalTableModel(this, db);
    qmodel = new QSqlQueryModel(this);
    model->setEditStrategy(QSqlRelationalTableModel::OnManualSubmit);
    model->setJoinMode(QSqlRelationalTableModel::LeftJoin);

    setComboBoxItems(); // set DB tables`s names to combobox
    ui->managment->setItemDelegate(new QSqlRelationalDelegate(ui->managment));

    QObject::connect(this, SIGNAL(sendInfo(QStringList)), &createTableWidget, SLOT(getInfo(QStringList)));
    QObject::connect(&createTableWidget, SIGNAL(returnSQLRequest()), this, SLOT(addNewTable()));
    QObject::connect(&createTableWidget, static_cast<void (CreateTableWidget::*)(QString)>(&CreateTableWidget::needRelationInfo), this, &MainWindow::setRelationInfo);
    QObject::connect(model, SIGNAL(primeInsert(int, QSqlRecord&)), this, SLOT(onPrimeInsert(int, QSqlRecord&)));

    ui->requestTableView->setHidden(true);
}

MainWindow::~MainWindow()
{
    db.close();
    delete model;
    delete ui;
}

void MainWindow::addNewTable()
{
    createRequest(createTableWidget.sqlRequest);
}

void MainWindow::onPrimeInsert(int row, QSqlRecord &record)
{
    QSqlQuery q = db.exec("create generator gen;"
                          "select gen_id(gen, 1) from rdb$database;");
    if(q.next())
    {record.setValue(row, q.value(0));
        record.setGenerated(row, true);}
}

void MainWindow::setRelationInfo(QString relationTableName)
{
    QSqlRecord record = db.record(relationTableName);
    for( int i = 0; i < record.count(); i++){
        createTableWidget.primaryList << record.fieldName(i);}
}

void MainWindow::createDataBase()
{
    // Bureau of Technical Inventory
    db.setHostName( HOSTNAME);
    db.setDatabaseName( PATH);
    db.setUserName( USERNAME);
    db.setPassword( PASSWORD);
    db.open( USERNAME, PASSWORD);

    //QSqlQuery *query = new QSqlQuery(db);

}

void MainWindow::setComboBoxItems()
{
    ui->comboBox->addItems( db.tables());
}

void MainWindow::createRequest( QString request)
{
    QSqlQuery q = db.exec(request);
    if(q.exec()) {qDebug()<<"Complete " << request;}
    ui->comboBox->clear();
    ui->comboBox->addItems(db.tables());
    ui->managment->reset();
    qmodel->setQuery(q);
    ui->requestTableView->setModel(qmodel);
    ui->requestTableView->setHidden(false);
}

void MainWindow::on_add_clicked()
{
    model->insertRow( model->rowCount());
}

void MainWindow::on_managment_clicked( const QModelIndex &index)
{
    selectedRowIndex = index.row();
}

void MainWindow::on_comboBox_activated( int index)
{
    currTable = ui->comboBox->itemText( index);
    model->setTable( currTable);
    model->select();
    ui->managment->setModel( model);
    ui->managment->reset();
}

void MainWindow::on_save_clicked()
{
    model->submitAll();
}

void MainWindow::on_cancel_clicked()
{
    model->revert();
}


void MainWindow::on_addTable_clicked()
{
    emit sendInfo(db.tables());
    createTableWidget.show();
}

void MainWindow::on_sqlRequestLineEdit_editingFinished()
{
    createRequest(ui->sqlRequestLineEdit->text());
}


void MainWindow::on_del_clicked()
{
    if(selectedRowIndex>=0) model->removeRow(selectedRowIndex);
    else qDebug() << "No row selected for removing.";
}


void MainWindow::on_delTabel_clicked()
{
    QSqlQuery q;

    QMessageBox msgBox(this);
    msgBox.setText("Are you sure?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.show();
    int res = msgBox.exec();

    switch (res){
        case QMessageBox::Yes:
                        db.transaction();
            if(q.exec("drop table " + currTable + ";")) qDebug()<<"Table " << currTable << "dropped;";
            db.commit();
            model->submitAll();
            ui->comboBox->clear();
            ui->comboBox->addItems(db.tables());
            ui->managment->reset();
            break;
        case QMessageBox::No:
            break;
    }
}

