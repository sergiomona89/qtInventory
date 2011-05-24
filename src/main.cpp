
#include"DataBase.h"
#include"Interfaz.h"
#include<QApplication>
#include<QDebug>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Interfaz a;
    a.show();

    return app.exec();
}
