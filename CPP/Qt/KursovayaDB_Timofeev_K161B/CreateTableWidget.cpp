#include "CreateTableWidget.h"
#include "ui_CreateTableWidget.h"

CreateTableWidget::CreateTableWidget(QWidget *parent):
    QWidget{parent},
    ui(new Ui::TableCreator)
{
    ui->setupUi(this);

    ui->isRelation->setChecked(true);

    ui->chooseTableComboBox->hide();
    ui->relationComboBox->hide();
    ui->foreignKeyComboBox->hide();
    ui->primaryKeyComboBox->hide();

    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();

    foreignModel = new QStandardItemModel(this);
    primaryModel = new QStandardItemModel(this);

}

CreateTableWidget::~CreateTableWidget()
{
    delete ui;
}

void CreateTableWidget::on_ColsNamesLineEdit_editingFinished()
{
    QString newTableCols = ui->ColsNamesLineEdit->text();
    if(newTableCols.length()==0 || newTableCols.contains(';') || newTableCols.contains('.'))
    {
        QMessageBox msgBox(this);
        msgBox.setText("Incorrect input");
        msgBox.show();
        msgBox.exec();
    }
}

void CreateTableWidget::on_OKButton_clicked()
{
    sqlRequest = "CREATE TABLE " + ui->TableNameLineEdit->text() + " (" + ui->ColsNamesLineEdit->text();

    QStringList *choosenForeignKeys = new QStringList();
    QStringList *choosenPrimaryKeys = new QStringList();

    QString fkey;
    QString pkey;

    for(int i = 0; i < foreignModel->rowCount(); i++)
    {
      if(foreignModel->item(i,0)->checkState() == Qt::Checked) { choosenForeignKeys->append(foreignModel->item(i,0)->text());}
    }

    for(int i = 0; i < primaryModel->rowCount(); i++)
    {
      if(primaryModel->item(i,0)->checkState() == Qt::Checked) { choosenPrimaryKeys->append(primaryModel->item(i,0)->text());}
    }

    if(ui->isRelation->isChecked())
    {
        switch (ui->relationComboBox->currentIndex()) {
            case 0: // none, same as default
                sqlRequest += ");";
                break;
            case 1: // one-to-one

                  fkey = choosenForeignKeys->at(0);
                  pkey = choosenPrimaryKeys->at(0);

                  sqlRequest = ", FOREIGN KEY (" + fkey + ")" + " REFERENCES " + ui->chooseTableComboBox->currentText() +  "(" + pkey +")";
                break;
            case 2: // one-to-many

                  fkey = choosenForeignKeys->at(0);
                  for(auto i = choosenPrimaryKeys->begin(); i < choosenPrimaryKeys->end(); i++)
                  {
                      pkey += i->toUtf8() + ',';
                  }
                  pkey.chop(1);
                  sqlRequest = ", FOREIGN KEY (" + fkey + ")" + " REFERENCES " + ui->chooseTableComboBox->currentText() +  "(" + pkey + ")";
                break;
            case 3: // many-to-one

                  for(auto i = choosenForeignKeys->begin(); i < choosenForeignKeys->end(); i++)
                  {
                      fkey += i->toUtf8() + ',';
                  }
                  fkey.chop(1);
                  pkey = choosenPrimaryKeys->at(0);

                sqlRequest += ", FOREIGN KEY (" + fkey + ")" + " REFERENCES " + ui->chooseTableComboBox->currentText() +  "(" + pkey + ")";
                break;
            case 4: // many-to-many
                  for(auto i = choosenForeignKeys->begin(); i < choosenForeignKeys->end(); i++)
                  {
                      fkey += i->toUtf8() + ',';
                  }
                  fkey.chop(1);
                  for(auto i = choosenPrimaryKeys->begin(); i < choosenPrimaryKeys->end(); i++)
                  {
                      pkey += i->toUtf8() + ',';
                  }
                  pkey.chop(1);
                sqlRequest += ", FOREIGN KEY (" + fkey + ")" + " REFERENCES " + ui->chooseTableComboBox->currentText() +  "(" + pkey + ")";
                break;
            default:
                sqlRequest += "";
                break;
        }
    }
    sqlRequest += ");";
    qDebug() << sqlRequest;
    emit returnSQLRequest();
}


void CreateTableWidget::on_cancelButton_clicked()
{
    this->close();
}

void CreateTableWidget::getInfo(QStringList tablesNamesList)
{
    ui->chooseTableComboBox->clear();
    ui->chooseTableComboBox->addItems(tablesNamesList);
}

void CreateTableWidget::on_isRelation_clicked()
{
    bool b = ui->isRelation->isChecked();

    ui->chooseTableComboBox->setHidden(b);
    ui->relationComboBox->setHidden(b);
    ui->foreignKeyComboBox->setHidden(b);
    ui->primaryKeyComboBox->setHidden(b);

    ui->label->setHidden(b);
    ui->label_2->setHidden(b);
    ui->label_3->setHidden(b);
    ui->label_4->setHidden(b);

    ui->relationComboBox->clear();
    ui->relationComboBox->addItems(QStringList() << "none" << "one-to-one" << "one-to-many" << "many-to-one" << "many-to-many");

    ui->foreignKeyComboBox->clear();
    ui->primaryKeyComboBox->clear();

    foreignList.clear();
    foreignList = ui->ColsNamesLineEdit->text().split(QRegExp("\\,"));

    int row = 0;

    for(auto i = foreignList.begin(); i!= foreignList.end(); i++)
    {
        QStandardItem *foreignKeyItem  = new QStandardItem();
        foreignKeyItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        foreignKeyItem->setData(Qt::Unchecked, Qt::CheckStateRole);

        foreignKeyItem->setText(QString(i->data()).toUtf8());
        foreignModel->setItem(row, 0, foreignKeyItem);

        row++;
    }
    ui->foreignKeyComboBox->setModel(foreignModel);
}


void CreateTableWidget::on_chooseTableComboBox_activated(int index)
{
    int row = 0;
    primaryList.clear();
    emit needRelationInfo(ui->chooseTableComboBox->currentText());
    ui->primaryKeyComboBox->clear();

    for(auto i = primaryList.begin(); i!= primaryList.end(); i++)
    {
        QStandardItem *primaryKeyItem = new QStandardItem();
        primaryKeyItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        primaryKeyItem->setData(Qt::Unchecked, Qt::CheckStateRole);

        primaryKeyItem->setText(QString(i->data()).toUtf8());
        primaryModel->setItem(row, 0, primaryKeyItem);

        row++;
    }

    ui->primaryKeyComboBox->setModel(primaryModel);
}
