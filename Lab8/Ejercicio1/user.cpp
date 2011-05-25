#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>//librería que contiene las estructuras de conector
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <netdb.h>

#define PUERTO 3490
#define TAM_BUF 260

using namespace std;

int main(int argc, char *argv[])
{
      if(argc<3) //Verificamos si pasó la IP del servidor y la ruta como argumento
	 {			
	 cout<<"Debe ingresar IP del servidor y la dirección absoluta del fichero que desea descargar."<<endl;
	 return 1;		
	 };
	
    int ret_socket, ret_sendto;	//variables que almacenan el retorno de las funciones
    struct sockaddr_in *server=new struct sockaddr_in;	//Estructura que contiene la IP del host local y el número del puerto a asignar
    struct hostent *he=new struct hostent;	//convertir el nombre del host en su dirección IP
    socklen_t size = sizeof(sockaddr);	//Miramos el tamaño de la estructura
    
  //***************OBTENEMOS LA INFORMACIÓN DEL HOST MEDIANTE LA FUNCIÓN "gethostbyname"********************
   if ((he=gethostbyname(argv[1])) == NULL)	//el valor de retorno de la función es la información del host
    { 
      perror("gethostbyname");
      cout <<"No se pudo obtener información del servidor\n";
      exit(1);
    }
    
  //Configuramos los valores de la estructura
  	server->sin_family = AF_INET;
	server->sin_port = htons(PUERTO);
     server->sin_addr = *((struct in_addr *)he->h_addr); //Asignamos la ip que obtenemos como argumento desde el argv[1]
    
  //********************REALIZAMOS LA APERTURA DEL SOCKET PARA TRABAJAR CON RED***********************************
      ret_socket = socket ( AF_INET,SOCK_DGRAM,0);	//Socket para realizar la apertura del canal. AD_INET como dominio,SOCK_DGRAM como tipo no orientado a la conexión UDP y protocolo 0
      if (ret_socket==-1)
      {
        perror("socket");
        cout <<"No pudo hacerse la apertura de la conexión.\n";
      }
      
  //*********************FUNCIÓN PARA COMENZAR EL ENVIO DE DATOS****************************
      ret_sendto=sendto(ret_socket, argv[2], strlen(argv[2]) + 1 , 0, (struct sockaddr *) server, size);

/*	
int sendto(int sockfd, const void *msg, int len, unsigned int flags, const struct sockaddr *to, int tolen)
ret_socket : Descriptor socket por donde se enviarán los datos.
argv[2] ((Ruta)) : Puntero a los datos a ser enviados.
strlen(argv[2]) : Longitud de los datos en bytes.
flags 0: Leer : man 2 sendto
(struct sockaddr *) server : Puntero a una estructura sockaddr que contiene la dirección IP y
     número de puerto destino.
size : Debe ser inicializado al tamaño de struct sockaddr ( sizeof (struct
        sockaddr) ).
sendto() retorna el número de bytes enviados, el cual puede ser menor que len,
igual que en send().
*/



      if ( ret_sendto == -1) 
      {
        perror("sendto");
        cout <<"Problema al al enviar los datos.\n";
        exit(1);
      }
      
  //Establecemos la estructura para controlar el tiempo de espera del socket
      struct timeval time;	
      fd_set socket_pack; //Estructura de sockets(conjunto de descriptores)
      
      //Configuramos el tiempo de espera para que el server responda
 	time.tv_sec = 5;	//Ponemos 5 segundos
	time.tv_usec = 0;	//Ponemos 0 milisegundos
  
        FD_ZERO ( &socket_pack ); //limpia el conjunto de descriptores.
        FD_SET ( ret_socket, &socket_pack ); //agrega ret_socket(retorno de socket) a un conjunto.

  //*************FUNCION QUE PERMITE MONITOREAR UN CONJUNTO DE SOCKETS (3)********************
      select ( ret_socket +1, &socket_pack, NULL, NULL, &time);
      
      //Se usa el descriptor más alto + 1, los demás descripores permanecen en NULL ya que usamos sólo el primero
      if (!FD_ISSET ( ret_socket, &socket_pack) ) //Verifica si ret_socket está dentro de un conjunto
      {
        cout << "No se pudo establecer la comunicación con el servidor.\n";
	  return 1;	
      }
      
  //******************FUNCION PARA RECIBIR LOS DATOS*************************
        //Identificamos  el número de bytes que llegan y los que se han recibido
        int bytes_llegando=0, bytes_acumulados=0;
        
      recvfrom(ret_socket, (char *) &bytes_llegando, sizeof(int), 0, (struct sockaddr *) server, &size);
      
        //Verificamos si el archivo que llega tiene un tamaño (si existe).
      if(bytes_llegando== -1)
      {		
        cout<<"El archivo especificado no existe en el servidor"<<endl;
        return 1;
      }
      else //Si llega algo si se inicia el otro ciclo
      {	
	
	
        fstream file(strrchr(argv[2],'/') + 1, ios::out | ios::binary);//Creamos el archivo para guardarlo.
        //La función strrchr() imprime desde la ultima aparición del caracter al que se le pone a apuntar, asi asignamos el nombre del fichero recibido
        //long ipserver = servidor->sin_addr.s_addr;	//En que direcion esta el servidor.
	
	char buffer[TAM_BUF];	//Puntero que almacenará los paquetes que llegan 
	

    unsigned int cp = 0;//Acumulación de paquetes. 
    
	 while(bytes_acumulados < bytes_llegando)	//recibimos el fichero hasta el momento en que los bytes que han llegado son iguales a los acumulados
	 { 
	   int acum;
	   bytes_acumulados += acum = (recvfrom(ret_socket, buffer,TAM_BUF, 0, (struct sockaddr *) server, &size) - sizeof(int));
	   //Hay que recordar que recvfrom() retorna el numero de bytes recibidos
	   
		if((*((int *) buffer)) < cp)	//Realizamos un cast para ver el tamaño de los paquetes recibidos
		{
		  sendto(ret_socket, buffer, sizeof(int), 0, (struct sockaddr *) server, size);	//Se ha recibido
		  bytes_acumulados -= acum;	//Se habia recibido, por lo cual es necesario restarlo-
		  continue;	//Finalizamos todo el ciclo
		}
		
		if(acum != TAM_BUF-4 && bytes_acumulados < bytes_llegando)	//No llega lo correspondiente
		{
		  bytes_acumulados -= acum;
		  int var = -1;
		  sendto(ret_socket, (char *) &var, sizeof(var), 0, (struct sockaddr *) server, size);
		  continue;	//Finalizamos el ciclo
		}
	 
		  file.write(buffer + sizeof(int) , acum); //Comenzamos a escribir en el archivo aquello que alacena acum
		  sendto(ret_socket, buffer,sizeof(int), 0, (struct sockaddr *) server, size);	//Se envía una confirmacion del recibido
		  cp++;
	 }
	
	file.close();	//Cerramos el fichero
	close(ret_socket);	//Cerramos el socket
	
      }	//Fin del else
	return 0;
}
