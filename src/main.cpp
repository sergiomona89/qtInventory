
#include<QDebug>
#include<QApplication>
#include"autenticarse.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Autenticarse a;
    a.show();

    return app.exec();
}
