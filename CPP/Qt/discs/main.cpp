
#include "funcs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    QApplication a(argc, argv);


    string str = DiscsInfo();

    for ( size_t i = 0; i < str.size(); i++) cout << str[i];

    QMainWindow *mw=new QMainWindow(0, Qt::Window);
                // Создали главное окно приложения. Первый параметр конструктора
                // указывает на родительский элемент (в данном случае 0 - окно
                // не имеет родителя), а второй - набор битовых флагов, влияющих
                // на внешний вид окна (флаг Qt::Windows означает, что элемент
                // будет выглядеть, как окно приложения, т.е. будет иметь строку
                // заголовка с системными кнопками для сворачивания на панель
                // задач, закрытия и т.д.).
    mw->setWindowTitle("DiscsInfo Application"); // Задали текст заголовка окна
    mw->resize (640, 480); // Определили размеры окна (ширину и высоту) в пикселах.
    mw->show(); // Вывели окно на экран.

    return a.exec();
}
