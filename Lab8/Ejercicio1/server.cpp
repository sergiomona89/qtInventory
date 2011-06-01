#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>

using namespace std;

#define PUERTO 3490
#define RUTA 108
#define TAM_BUF 260

int main ()
{
    int ret_socket, ret_bind, ret_sendto, ret_bytes, socket_envio;//variables que almacenan el retorno de las funciones
    struct sockaddr_in *server= new struct sockaddr_in;//Estructura que contiene la IP del host local y el número del puerto a asignar
    struct sockaddr_in *user = new struct sockaddr_in;//Corresponden al servidor y al cliente

//********************REALIZAMOS LA APERTURA DEL SOCKET PARA TRABAJAR CON RED***********************************
    ret_socket = socket ( AF_INET,SOCK_DGRAM,0 );//Socket para realizar la apertura del canal. AF_INET como dominio,SOCK_DGRAM como tipo no orientado a la conexion y protocolo 0
    if (ret_socket==-1)
    {
        perror("socket");
        cout <<"No pudo hacerse la apertura de la conexión.\n";
        exit(1);
    }

//********************ESTABLECEMOS LA CONEXIÓN CON EL USO DE BIND************************************
    //Configuración de los miembros de la estructura
    server->sin_family = AF_INET; //PROCESO PARA TRABAJAR ENTRE VARIAS MAQUINAS
    server->sin_port = htons(PUERTO);//Convertimos a network byte order
    server->sin_addr.s_addr = INADDR_ANY; //le llevamos nuestra propia ip

    ret_bind= bind(ret_socket, (struct sockaddr*) server, sizeof(struct sockaddr)); //bind se utiliza para atar el socket a un puerto y a una dirección IP
    if (ret_bind==-1)
    {
        perror("bind");
        cout <<"No pudo realizarse la conexión con el socket.\n";
        exit(1);
    }

//Funciones para transferencia de datos
    socklen_t size = sizeof(sockaddr); //Lo que pesa una estructura de ese tipo.
    char ruta[RUTA];	//Tamaño de buffer

    for(;;)	//For infinito para recibir peticiones
    {
        ret_bytes = recvfrom(ret_socket, ruta, RUTA , 0,(struct sockaddr *)user, &size);
        /*
        int recvfrom ( int sockfd, void *buf, int len, unsigned int flags, struct sockaddr *from, int *fromlen )
        ret_socket : Descriptor socket por donde se recibirán los datos.
        ruta: Puntero a un buffer donde se almacenarán los datos recibidos.
        RUTA: Longitud del buffer buf.
        flags 0: Ver la página del manual de recv().
        from: Puntero a una estructura sockaddr que contiene la dirección IP y
              número de puerto del host origen (usuario) de los datos.
        &size: Debe ser inicializado al tamaño de struct sockaddr ( sizeof (struct
                 sockaddr) ).
        */


        if (ret_bytes == -1)
        {
            perror("recvfrom");
            exit(1);
        }
        fstream file(ruta, ios::in | ios::binary); //Este es el archivo que el cliente quiere descargar guardado en binario
        if(!file)	//Intenta abrir el archivo que solicitó el cliente y mira si existe
        {
            int var = -1;
            sendto(ret_socket, (char *) &var, sizeof(var), 0, (struct sockaddr *) user, size);	//No existe el fichero
            continue;	//Sale del for
        }
        //Estructura para ver el estado del fichero
        struct stat info;		//Información del fichero
        int bytes_fichero=0;
        int bytes_enviados=0;

        stat(ruta, &info);		//Obtener informacion administrativa del fichero

        //Banderas para st_mode
        //S_IFMT	0017000	máscara de bits para los campos de bit del tipo de fichero (no POSIX)
        //S_IFREG	0100000	fichero regular (no POSIX)

        if((info.st_mode & S_IFMT) == S_IFREG) //Verificamos el estado del fichero para poder detectar su tamaño
        {
            bytes_fichero = info.st_size;
            int pID = fork();		     //se crea el hilo para la ejecución

            if(pID == -1) //Verificar si falló la creación del proceso hijo
            {
                perror("fork:");
                return 1;
            }
            else if(pID == 0)
            {
                socket_envio = socket(AF_INET, SOCK_DGRAM, 0);	//Apertura del socket para enviar datos

                sendto(socket_envio, (char *) &bytes_fichero, sizeof(int), 0, (struct sockaddr *)user, size);	//Enviar el numero de bytes al cliente.

                char buffer[TAM_BUF];	//Aquí se leen los datos

                file.seekg(0, ios::beg);		//Ubicamos el puntero al inicio del fichero



                //Establecemos la estructura para controlar el tiempo de espera del socket
                //   struct timeval time;
                fd_set socket_pack; //Estructura de sockets(conjunto de descriptores)

                //Configuramos el tiempo de espera para que el server responda
//	time.tv_sec = 12;	//Ponemos 12 segundos
//	time.tv_usec = 1;	//Ponemos 1 milisegundo



                FD_ZERO ( &socket_pack ); //limpia el conjunto de descriptores.
                FD_SET ( socket_envio, &socket_pack ); //agrega socket_envio(retorno de socket) a un conjunto.

                unsigned int acum=0;
                unsigned int cp = 0;	//Variable para contar los paquetes enviados

                while(!file.eof()) //Mientras el puntero no esté al final del archivo
                {

                    FD_SET(socket_envio, &socket_pack);
                    file.read(buffer + 4,TAM_BUF-4); 	//Se lee de a 512 bytes dejando los 4 primeros
                    bytes_enviados = sendto(socket_envio, (char * ) memcpy (buffer, (char *) &cp, sizeof(cp)), file.gcount () + sizeof(cp), 0, (struct sockaddr *) user, size);
                    //con memcpy copiamos el numero de bytes que nos diga cp al buffer, gount retorna el numero de caracteres leidos

                    recvfrom(socket_envio, (char *) &acum, sizeof(acum), 0, (struct sockaddr *) user, &size);

                    if(*((int *) &acum) != cp || bytes_enviados != (sizeof(int) + file.gcount()))
                    {
                        cout<<"Se enviaron menos bytes"<<endl;
                        file.seekg(-file.gcount(), ios::cur);	//Ubica el cursor de nuevo dentro del archivo desde donde no se pudo leer
                        continue; //Sale del ciclo
                    }

                    cp++; //Aumentamos los paquetes que se han logrado enviar
                }

                return 0;	//Fin del proceso hijo
            }

        }
        else
        {
            int var = -1;
            sendto(ret_socket, (char *) &var, sizeof(var), 0, (struct sockaddr *) user, size);
            continue;
        }
    }
}
