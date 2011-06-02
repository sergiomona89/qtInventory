
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "autenticarse.h"
#include "Interfaz.h"
#include "types.h"

#include<QDebug>
#include<QMessageBox>

#define HOST	"localhost"
#define PUERTO	3490
#define TAM_BUF	260

Autenticarse::Autenticarse(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    connect(AceptarPushButton, SIGNAL(clicked(void)), this, SLOT(autenticar(void)));
    connect(CancelarPushButton, SIGNAL(clicked(void)), this, SLOT(close(void)));
}

void Autenticarse::autenticar()
{
//     int ret_socket, ret_sendto;	//variables que almacenan el retorno de las funciones
    struct sockaddr_in *server=new struct sockaddr_in;	//Estructura que contiene la IP del host local y el número del puerto a asignar
    struct hostent *he=new struct hostent;	//convertir el nombre del host en su dirección IP
    socklen_t size = sizeof(sockaddr);	//Miramos el tamaño de la estructura

    //***************OBTENEMOS LA INFORMACIÓN DEL HOST MEDIANTE LA FUNCIÓN "gethostbyname"********************
    if ((he=gethostbyname(HOST)) == NULL)	//el valor de retorno de la función es la información del host
    {
        QMessageBox::critical(this, "Error", "No se pudo obtener información del servidor");
        exit(1);
    }

    //Configuramos los valores de la estructura
    server->sin_family = AF_INET;
    server->sin_port = htons(PUERTO);
    server->sin_addr = *((struct in_addr *)he->h_addr); //Asignamos la ip que obtenemos como argumento desde el argv[1]

    int r_socket;
    if ((r_socket = socket(AF_INET, SOCK_DGRAM,0)) == -1)
    {
        QMessageBox::critical(this, "Error", "No pudo hacerse la apertura de la conexión.");
    }

    Peticion p = Autenticar;
    if(sendto(r_socket, reinterpret_cast<char *>(&p), sizeof(p), 0, (struct sockaddr *) server, size) == -1)
    {
        QMessageBox::critical(this, "Error", "Problema al al enviar los datos de autenticación.");
        exit(1);
    }

    //Establecemos la estructura para controlar el tiempo de espera del socket
    struct timeval time;
    fd_set socket_pack; //Estructura de sockets(conjunto de descriptores)

    //Configuramos el tiempo de espera para que el server responda
    time.tv_sec = 5;	//Ponemos 5 segundos
    time.tv_usec = 0;	//Ponemos 0 milisegundos

    FD_ZERO ( &socket_pack ); //limpia el conjunto de descriptores.
    FD_SET ( r_socket, &socket_pack ); //agrega ret_socket(retorno de socket) a un conjunto.

    //*************FUNCION QUE PERMITE MONITOREAR UN CONJUNTO DE SOCKETS (3)********************
    select( r_socket +1, &socket_pack, NULL, NULL, &time);

    //Se usa el descriptor más alto + 1, los demás descripores permanecen en NULL ya que usamos sólo el primero
//     if (!FD_ISSET ( r_socket, &socket_pack) ) //Verifica si ret_socket está dentro de un conjunto
//     {
//         QMessageBox::critical(this, "Error", "No se pudo establecer la comunicación con el servidor.");
//         exit(1);
//     }

    const char * id = IdUsuarioLineEdit->text().toStdString().c_str();
    const char * pass = ContrasenaLineEdit->text().toStdString().c_str();
    if(sendto(r_socket, id, strlen(id), 0, (struct sockaddr *) server, size) == -1)
    {
        QMessageBox::critical(this, "Error", "Problema al al enviar los datos de autenticación.");
        exit(1);
    }
    if(sendto(r_socket, pass, strlen(pass), 0, (struct sockaddr *) server, size) == -1)
    {
        QMessageBox::critical(this, "Error", "Problema al al enviar los datos de autenticación.");
        exit(1);
    }
    int aut;
    recvfrom(r_socket, (char *) &aut, sizeof(int), 0, (struct sockaddr *) server, &size);
    qDebug() << "aut: "<< aut;
}