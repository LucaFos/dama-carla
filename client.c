#include <sys/types.h>
#include <sys/socket.h>
//"in" per "sockaddr_in"
#include <netinet/in.h>
//"netdb" per "gethostbyname"
#include <netdb.h>

void ChiudiSocket(int sock)
{
	close(sock);
	return;
}

int CreaSocket(char* Destinazione, int Porta)
{
	struct sockaddr_in temp; 
	struct hostent *h;
	int sock;
	int errore;
	
	//Tipo di indirizzo
	temp.sin_family=AF_INET;
	temp.sin_port=htons(Porta);
	h=gethostbyname(Destinazione);
	if (h==0) 
	{
		printf("Gethostbyname fallito\n");
		exit(1);
	}
	bcopy(h->h_addr,&temp.sin_addr,h->h_length);
	//Creazione socket. 
	sock=socket(AF_INET,SOCK_STREAM,0);
	//Connessione del socket. Esaminare errore per compiere azioni
	//opportune in caso di errore.
	errore=connect(sock, (struct sockaddr*) &temp, sizeof(temp));
	return sock;
}

void SpedisciMessaggio(int sock, char* Messaggio)
{
	printf("Client: %s\n",Messaggio);
	//Si puo' notare il semplice utilizzo di write: 
	//write(socket, messaggio, lunghezza messaggio)
	if (write(sock,Messaggio,strlen(Messaggio))<0)
	{
		printf("Impossibile mandare il messaggio.\n");
		ChiudiSocket(sock);
		exit(1);
	}
	printf("Messaggio spedito con successo.\n");
	return;
}

int main(int argc,char* argv[])
{
	char  buffer[512];
	int DescrittoreSocket,NuovoSocket;
	int exitCond=0;
	int Quanti;
	
	
	//Creo e connetto il socket
	DescrittoreSocket=CreaSocket(argv[1],atoi(argv[2]));
	
	//Spedisco il messaggio voluto
	if ((argc==2)&&(strcmp(argv[3],"exit")==0))
		SpedisciMessaggio(DescrittoreSocket,"exit");
	else
		SpedisciMessaggio(DescrittoreSocket,argv[3]);
	
	while (!exitCond)
	{
		//Lettura dei dati dal socket (messaggio ricevuto)
		if ((Quanti=read(DescrittoreSocket,buffer,sizeof(buffer)))>0)
		{
			//Aggiusto la lunghezza...
			buffer[Quanti]=0;
			//Elaborazione dati ricevuti
			
			printf("Server response: %s \n", buffer);
			exitCond = 1;
		}
	}
	
	//Chiudo il socket.
	ChiudiSocket(DescrittoreSocket);

	return 0;
}
