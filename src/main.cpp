#include "headers/mainwindow.h"
#include <QApplication>
#include "headers/MyVector.h"
#include "headers/Arquivo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Arquivo arquivo("arquivo.json");
    MyVector<Usuario> usuarios(-10);
    MainWindow mainWindow(usuarios);

    arquivo.readFileTo(usuarios);
    mainWindow.show();
    app.exec();
    arquivo.writeFileFrom(usuarios);

    return 0;
}
