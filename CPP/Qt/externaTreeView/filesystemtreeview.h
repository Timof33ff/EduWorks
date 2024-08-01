#ifndef FILESYSTEMTREEVIEW_H
#define FILESYSTEMTREEVIEW_H

#include <QWidget>
#include <QTreeView>
#include <QLabel>
#include <QLayout>
#include <QDir>
#include <QFileSystemModel>
#include <QMenu>
#include <QAction>
#include <QTimer>

#define PATH "c:/"

class FileSystemTreeView : public QWidget
{
    Q_OBJECT

public:
    explicit FileSystemTreeView(QWidget *parent, QString startPath = PATH);
    ~FileSystemTreeView();

    QTreeView *treeView;
    QLabel *pathLabel;
    QLabel *messageLabel;

    void refreshFileSys(const QString &newPath);                // обновляем файловую системы

signals:
    void sendPath(QString);                                     // передаем путь к выбранной в дереве директории

public slots:
    void getPath(const QString &path);                          // получаем путь от главного окна геоллогера
    void on_treeView_clicked(const QModelIndex &index);         // задаем индекс кликнутой папки как текущий индекс
    void on_treeView_doubleClicked(const QModelIndex &index);   // переходим внутрь дважды кликнутой папки
    void createContext();                                       // создаём контекстное меню для выбора фильтров

private:
    QDir *dir;                  // текущая директория
    QString path;               // путь к текущей корневой папке
    QFileSystemModel *fsm;      // объект файловой системы
    QModelIndex currentIndex;   // текущий индекс fsm
    QTimer *timer;

    void message(int msec, const QString &message);
};

#endif // FILESYSTEMTREEVIEW_H
