#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <signal.h>
#include <sys/un.h>
#include <sys/types.h>
using namespace std;
int main ()
{
int acum1=0, acum2=0, asumar;
srand(time(0));

int sockets[2];
socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);	//socketpair - crea un par de conectores conectados. AF_UNIX porque los procesos son en la mismoa máquina
int pID= fork();
    

if(pID==0)      //--------------------------------------------- PID del Hijo----------------------------------------------------
{
	srand(time(0));	//Función para obtener valores aleotorios diferentes cada vez que se ejecute el programa. (Semilla)
	close(sockets[0]);     //Cerramos el socket del padre que no necesitamos
		
		for(;;) //Ciclo infinito para los procesos
		{
			recv(sockets[1], (char *) &acum1, sizeof(asumar), 0);	//Esperamos el resultado del padre
			
		//-------------------------------------------- JUGADOR 2 --------------------------------------------------------

			asumar=(rand()%6)+1; //Formula que determina el avance de posición que tendrá el jugador		
			if(acum1 == 30)
			{
				cout<<"\n   ¡¡¡¡ GANADOR = JUGADOR 1 ¡¡¡¡\n";	
				exit (1);
			}
			else if (acum1==acum2)
			{
				acum2=0;
				cout<<"\n <<< El jugador 1 ha alcanzado al 2 por lo tanto el jugador 2 regresa a la posición 0 >>> \n";
			}
			else if(acum2==30)
			{
				cout<<"\n      ---- FIN DEL JUEGO ---- \n\n\n";
			}		
			else if ((asumar+acum2)<=30)
			{
				acum2=acum2+asumar;
				cout<<"\n JUGADOR 2 --> Avance: "<<asumar<<" Posicion(2): "<<acum2;
				cin.get();
			}
			else
			{
				cout<<"\n JUGADOR 2 --> Avance: "<<asumar<<" Posicion(2): "<<acum2;
				cout<<"\n\n	 La posicion no ha aumentado porque supera el limite (!) \n";
				//El jugador no podrá avanzar más allá de la posición 30				
				cin.get();
			}	
				 send(sockets[1], (char *) &acum2, sizeof(acum2), 0);	//Enviamos la posición del hijo hacia el padre
				  
		}
}
    
		//--------------------------------------------- PID del Padre ----------------------------------------------------
else 
{		
	close(sockets[1]);	//Ahora abre el socket que corresponde al padre
	srand(pID);		//Siembra la semilla para el padre.
			
	cout<<"\n\n	--- BIENVENIDO AL JUEGO ---\n\n"<<" *Presione ENTER para iniciar el juego ";
	cin.ignore();

		//--------------------------------------------- JUGADOR 1 ----------------------------------------------------				

	asumar=(rand()%6)+1; //Formula que determina el avance (aleatorio) de posición  que tendrá el jugador		
	acum1=acum1+asumar;
	cout<<"\n JUGADOR 1 --> Avance: "<<asumar<<" Posicion(1): "<<acum1;
	cin.get();

	for(;;)
	{			
		send(sockets[0], (char *) &acum1, sizeof(acum1), 0);	//Informa de la posición del padre al hijo
		recv(sockets[0], (char *) &acum2, sizeof(asumar), 0);		//y luego recibe el avance y la posición final del hijo (JUGADOR 2)
		asumar=(rand()%6)+1;
		
		if(acum2==30)
		{
			cout<<"\n   ¡¡¡¡ GANADOR = JUGADOR 2 ¡¡¡¡\n";
			kill(pID, 0); //Finaliza el proceso			
			exit (1);
		}		

		else if(acum2 == acum1) 
		{
			  cout<<"\n <<< El jugador 2 ha alcanzado al 1 por lo tanto el jugador 1 pierde su posición >>> \n";
			  acum1 = 0;
		}
	
		else if(acum1==30)
		{
			cout<<"\n      ---- FIN DEL JUEGO ---- \n\n\n";
		}
	    
		else if ((asumar+acum1)<=30)
		{
			acum1=acum1+asumar;
			cout<<"\n JUGADOR 1 --> Avance: "<<asumar<<" Posicion(1): "<<acum1;
			cin.get();
		}

		else
		{
			cout<<"\n JUGADOR 1 --> Avance: "<<asumar<<" Posicion(1): "<<acum1;
			cout<<"\n\n	 La posicion no ha aumentado porque supera el limite (!) \n";
			cin.get();
		}				
	}    
}
return 0; //Fin del main.
}
