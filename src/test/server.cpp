

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <netinet/in.h>


#include "types.h"

#include<QDebug>
#include<QApplication>

#include "DataBase.h"
#include "autenticarse.h"
#include "DBQueries.h"
#include "Info_usuario.h"
#include "AdministracionUsuario.h"


#define PUERTO	3490
#define RUTA	108
#define TAM_BUF	260

// Peticion _peticion = None;

int main(int argc, char **argv)
{
    // Estructura que contiene la IP del host local y el número del puerto a asignar
    struct sockaddr_in * server= new struct sockaddr_in;
    // Corresponden al servidor y al cliente
    struct sockaddr_in * user = new struct sockaddr_in;

    // REALIZAMOS LA APERTURA DEL SOCKET PARA TRABAJAR CON RED
    int ret_socket = socket ( AF_INET,SOCK_DGRAM,0 );//Socket para realizar la apertura del canal. AF_INET como dominio,SOCK_DGRAM como tipo no orientado a la conexion y protocolo 0
    if(ret_socket == -1)
    {
        std::cout << "No pudo hacerse la apertura de la conexión.\n";
        exit(1);
    }

    // ESTABLECEMOS LA CONEXIÓN CON EL USO DE BIND
    //Configuración de los miembros de la estructura
    server->sin_family = AF_INET;		//PROCESO PARA TRABAJAR ENTRE VARIAS MAQUINAS
    server->sin_port = htons(PUERTO);		//Convertimos a network byte order
    server->sin_addr.s_addr = INADDR_ANY;	//le llevamos nuestra propia ip

    if (bind(ret_socket, (struct sockaddr*) server, sizeof(struct sockaddr)) == -1) //bind se utiliza para atar el socket a un puerto y a una dirección IP
    {
        std::cout <<"No pudo realizarse la conexión con el socket.\n";
        exit(1);
    }

    //Funciones para transferencia de datos
    socklen_t size = sizeof(sockaddr); //Lo que pesa una estructura de ese tipo.
    char ruta[RUTA];	//Tamaño de buffer

    for(;;)	// for infinito para recibir peticiones
    {
        if(recvfrom(ret_socket, ruta, RUTA , 0,(struct sockaddr *)user, &size) == -1)
        {
            std::cout << "recvfrom" << std::endl;
            exit(-1);
        }

        Peticion p;

        if(p == Autenticar)
        {
// 	    _peticion = Autenticar;
            char id[10];
            char contrasena[100];
            if(recvfrom(ret_socket, id, RUTA , 0,(struct sockaddr *)user, &size) == -1)
            {
                std::cout << "usuario error" << std::endl;
                continue;
            }
            if(recvfrom(ret_socket, contrasena, RUTA , 0,(struct sockaddr *)user, &size) == -1)
            {
                std::cout << "contraseña error" << std::endl;
                continue;
            }
            bool  aut = DBQueries::autenticar(QString(id).toInt(), contrasena);
//             Respuesta r = done;
//             sendto(ret_socket, (char *) &r, sizeof(Respuesta), 0, (struct sockaddr *) user, size);
// 	    continue;
        }
        else
        {
            Respuesta r = error;
            sendto(ret_socket, (char *) &r, sizeof(Respuesta), 0, (struct sockaddr *) user, size);
        }

//         stat(ruta, &info);		//Obtener informacion administrativa del fichero

        //Banderas para st_mode
        //S_IFMT	0017000	máscara de bits para los campos de bit del tipo de fichero (no POSIX)
        //S_IFREG	0100000	fichero regular (no POSIX)

//         if((info.st_mode & S_IFMT) == S_IFREG) //Verificamos el estado del fichero para poder detectar su tamaño
//         {
//             bytes_fichero = info.st_size;
//             int pID = fork();		     //se crea el hilo para la ejecución
//
//             if(pID == -1) //Verificar si falló la creación del proceso hijo
//             {
//                 perror("fork:");
//                 return 1;
//             }
//             else if(pID == 0)
//             {
//                 socket_envio = socket(AF_INET, SOCK_DGRAM, 0);	//Apertura del socket para enviar datos
//
//                 sendto(socket_envio, (char *) &bytes_fichero, sizeof(int), 0, (struct sockaddr *)user, size);	//Enviar el numero de bytes al cliente.
//
//                 char buffer[TAM_BUF];	//Aquí se leen los datos
//
//                 file.seekg(0, ios::beg);		//Ubicamos el puntero al inicio del fichero
//
//
//
//                 //Establecemos la estructura para controlar el tiempo de espera del socket
//                 //   struct timeval time;
//                 fd_set socket_pack; //Estructura de sockets(conjunto de descriptores)
//
//                 //Configuramos el tiempo de espera para que el server responda
// //	time.tv_sec = 12;	//Ponemos 12 segundos
// //	time.tv_usec = 1;	//Ponemos 1 milisegundo
//
//
//
//                 FD_ZERO ( &socket_pack ); //limpia el conjunto de descriptores.
//                 FD_SET ( socket_envio, &socket_pack ); //agrega socket_envio(retorno de socket) a un conjunto.
//
//                 unsigned int acum=0;
//                 unsigned int cp = 0;	//Variable para contar los paquetes enviados
//
//                 while(!file.eof()) //Mientras el puntero no esté al final del archivo
//                 {
//
//                     FD_SET(socket_envio, &socket_pack);
//                     file.read(buffer + 4,TAM_BUF-4); 	//Se lee de a 512 bytes dejando los 4 primeros
//                     bytes_enviados = sendto(socket_envio, (char * ) memcpy (buffer, (char *) &cp, sizeof(cp)), file.gcount () + sizeof(cp), 0, (struct sockaddr *) user, size);
//                     //con memcpy copiamos el numero de bytes que nos diga cp al buffer, gount retorna el numero de caracteres leidos
//
//                     recvfrom(socket_envio, (char *) &acum, sizeof(acum), 0, (struct sockaddr *) user, &size);
//
//                     if(*((int *) &acum) != cp || bytes_enviados != (sizeof(int) + file.gcount()))
//                     {
//                         cout<<"Se enviaron menos bytes"<<endl;
//                         file.seekg(-file.gcount(), ios::cur);	//Ubica el cursor de nuevo dentro del archivo desde donde no se pudo leer
//                         continue; //Sale del ciclo
//                     }
//
//                     cp++; //Aumentamos los paquetes que se han logrado enviar
//                 }
//
//                 return 0;	//Fin del proceso hijo
//             }

//         }
//         else
//         {
//             int var = -1;
//             sendto(ret_socket, (char *) &var, sizeof(var), 0, (struct sockaddr *) user, size);
//             continue;
//         }
    }
}