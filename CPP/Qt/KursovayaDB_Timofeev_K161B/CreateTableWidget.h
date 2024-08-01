#ifndef CREATETABLEWIDGET_H
#define CREATETABLEWIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDebug>

/*
 *Создает небольшое окно для
 * ввода названия новой таблицы,
 * имён её столбцов,
 * отношений с другими таблицами
*/
namespace Ui {
    class TableCreator;
}

class CreateTableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CreateTableWidget(QWidget *parent = nullptr);
    ~CreateTableWidget();

    QString sqlRequest; // request to create new table

    QStringList foreignList;
    QStringList primaryList;

public slots:
    void getInfo(QStringList colsNamesList);

signals:
    void returnSQLRequest();
    void needRelationInfo(QString);

private:
    Ui::TableCreator *ui;

    QStandardItemModel *foreignModel;
    QStandardItemModel *primaryModel;

private slots:
    void on_ColsNamesLineEdit_editingFinished();
    void on_OKButton_clicked();
    void on_cancelButton_clicked();
    void on_isRelation_clicked();
    void on_chooseTableComboBox_activated(int index);
};

#endif // CREATETABLEWIDGET_H
