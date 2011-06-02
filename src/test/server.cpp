
#include"Servidor.h"
#include<QUdpSocket>

#define PUERTO	3490

int main(int argc, char **argv)
{
    QUdpSocket * sk = new QUdpSocket;
    sk->bind(PUERTO);

    delete sk;

    return 0;
}