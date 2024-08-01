#include "filesystemtreeview.h"

FileSystemTreeView::FileSystemTreeView(QWidget *parent, QString startPath) : QWidget(parent)
{
    treeView = new QTreeView(this);
    pathLabel = new QLabel(this);
    messageLabel = new QLabel(this);
    timer = new QTimer(this);

    dir = new QDir();
    dir->setSorting(QDir::SortFlag::Name);
    fsm = new QFileSystemModel(treeView);
    fsm->setFilter(QDir::Dirs);

    refreshFileSys(startPath); // иницализируем fsm, dir, path, currentIndex, загружаем fsm в treeview

    treeView->setHeaderHidden(true); // прячем хедеры ( | имя | тип | размер | и т.п.)
    for(int i = 1; i < fsm->columnCount(); i++) { treeView->hideColumn(i);}

    treeView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setColumnWidth(0, treeView->geometry().width()*fsm->columnCount()); // для длинных имён

    connect(treeView, &QTreeView::clicked, this, &FileSystemTreeView::on_treeView_clicked);
    connect(treeView, &QTreeView::doubleClicked, this, &FileSystemTreeView::on_treeView_doubleClicked);
    connect(treeView, &QTreeView::customContextMenuRequested, this, &FileSystemTreeView::createContext);

    messageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    messageLabel->setWordWrap(true);
    messageLabel->setAlignment(Qt::AlignLeft);
    connect(timer, &QTimer::timeout, messageLabel, &QLabel::hide);

    pathLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pathLabel->setWordWrap(true);
    pathLabel->setAlignment(Qt::AlignLeft);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(pathLabel, 0);
    layout->addWidget(treeView, 6);
    layout->addWidget(messageLabel, 0);

    treeView->show(); pathLabel->show(); messageLabel->hide();
}

FileSystemTreeView::~FileSystemTreeView()
{
    delete fsm;
    delete dir;
    delete timer;
    delete treeView;
    delete pathLabel;
    delete messageLabel;
}

void FileSystemTreeView::refreshFileSys(const QString &new_path)
{
    if (QFileInfo(new_path).isFile()){message(2000, new_path + " не директория"); return;} // если путь к файлу -> выводим сообщение

    path = QtPrivate::convertToUtf8(new_path);
    dir->setPath(new_path);

    if (!dir->exists()){message(2000, "Пути " + dir->path() + " не существует");} // если пути не существует -> выводим сообщение
    else {
        fsm->setRootPath(dir->path());
        currentIndex = fsm->index(new_path, 0);
        treeView->setModel(fsm);
        treeView->setRootIndex(fsm->index(dir->path()));
        pathLabel->setText(dir->path());
    }
}

void FileSystemTreeView::getPath(const QString &path)
{
    if (QFileInfo(path).isFile()){message(2000, path + " не директория"); return;} // если путь к файлу -> выводим сообщение
    this->path = path;
    refreshFileSys(this->path);
}

void FileSystemTreeView::on_treeView_clicked(const QModelIndex &index)
{
    currentIndex = index;
}

void FileSystemTreeView::on_treeView_doubleClicked(const QModelIndex &index)
{
    currentIndex = index;

    if(QFileInfo(QString(path).append(fsm->data(index, Qt::DisplayRole).toString())).isFile())
    {   message(1500, fsm->data(index, Qt::DisplayRole).toString() + " не директория");
        return;}

    if(fsm->data(index, Qt::DisplayRole).toString() == '.')
    {   path = QDir::rootPath();}
    else if(fsm->data(index, Qt::DisplayRole).toString() == "..")
    {   int i = dir->path().lastIndexOf('/');
        path = dir->path().left(i+1);}
    else
    {
        if( dir->path().length() > 0 && dir->path().at( dir->path().length() - 1) != '/') path.append('/');
        path.append(fsm->data(index, Qt::DisplayRole).toString());

    }

    emit sendPath(path);
    refreshFileSys(path);
}

void FileSystemTreeView::createContext()
{
    QMenu *filtersMenu = new QMenu(this);

    QAction *dirsFilters = new QAction(QtPrivate::convertToUtf8(L"Только папки"), this);
    QAction *filesFilters = new QAction(QtPrivate::convertToUtf8(L"Включить файлы"), this);

    connect(dirsFilters, &QAction::triggered, this, [this]{ fsm->setFilter(QDir::Filter::Dirs);  message(1500, "Отфильтровано по папкам.");});
    connect(filesFilters, &QAction::triggered, this, [this]{ fsm->setFilter(QDir::Filter::AllEntries); message(1500, "Файлы включены.");});

    filtersMenu->addAction(dirsFilters);
    filtersMenu->addAction(filesFilters);

    filtersMenu->popup(QCursor::pos());
}

void FileSystemTreeView::message(int msec, const QString &message)
{
    messageLabel->hide();
    timer->start(msec);
    messageLabel->setText(message);
    messageLabel->show();
}
