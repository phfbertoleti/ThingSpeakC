/*
Módulo: Comunicação com ThingSpeak (via Socket TCP) para Linux
Autor:  Pedro Bertoleti
Data:   05/2016
*/

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "ThingSpeakLinux.h"

//defines
#define URL_THINGSPEAK             "api.thingspeak.com"
#define PORTA_THINGSPEAK           80
#define INICIO_REQUISICAO_HTTP     "GET /update?key="
#define TERMINADOR_REQUISICAO_HTTP "\r\n\r\n"
#define MAX_CARACTERES             9999

//variáveis locais

//prototypes

//implementações / funções


char EnviaRequisicaoThingSpeak(int NumCampos, int * ArrayCampos, char * Chave, int TamChave)
{
	int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *ServerTCP;
	int TamanhoStringRequisicao;
	int i;
	char LinhaRequisicao[MAX_CARACTERES];
	char InicioRequisicaoHTTP[]=INICIO_REQUISICAO_HTTP;
	char TerminadorRequisicaoHTTP[]=TERMINADOR_REQUISICAO_HTTP;
	char *ptLinha;
	
	if (NumCampos <=0)
		return ERRO_PARAMETROS;
	
	/*
	     Montagem da string de requisição HTTP
	*/
	
	bzero(&LinhaRequisicao,sizeof(LinhaRequisicao));
	
	//1- inicio da montagem da string de requisição HTTP (inicio e chave)
	sprintf(LinhaRequisicao,"%s%s",InicioRequisicaoHTTP,Chave);
	
	//2- inclusao dos campos
	ptLinha = &LinhaRequisicao[0]+(int)strlen(LinhaRequisicao);
	
	for(i=1; i<= NumCampos; i++)
	{
		sprintf(ptLinha,"&field%d=%d",i,ArrayCampos[i-1]);
		ptLinha = &LinhaRequisicao[0]+(int)strlen(LinhaRequisicao);
	}
	
	//3- Acrescenta terminador
	sprintf(ptLinha,"%s",TerminadorRequisicaoHTTP);
	
	
	portno = PORTA_THINGSPEAK;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
	//tenta abrir socket
	if (sockfd < 0)
		return ERRO_AO_ABRIR_SOCKET;
	
	//verifica se host esta online
	ServerTCP = gethostbyname(URL_THINGSPEAK);
	if (ServerTCP == NULL) 
	    return ERRO_THINGSPEAK_OFFLINE;
    
	//configura estrutura de socket com dados do servidor
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)ServerTCP->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         ServerTCP->h_length);
    serv_addr.sin_port = htons(portno);
    
	//tenta conectar no servidor
	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		return ERRO_CONEXAO_THINGSPEAK;
	
	//envia requisição HTTP
    write(sockfd,LinhaRequisicao,strlen(LinhaRequisicao));
		
	//fecha conexão
    close(sockfd);    
}
		   