/*
	Exemplo de uso do ThingSpeak (Linux)
	Autor: Pedro Bertoleti
	Data: 05/2016
*/

#include <stdio.h>
#include "ThingSpeakLinux.h"

//para este teste, os dados estão indo para o seguinte canal: https://thingspeak.com/channels/118265
//para enviar para outro canal, basta trocar a chave abaixo.
#define CHAVE "E4AKR731LNBQ67EW"

void main(void)
{
	int ArrayCampos[3]={0, 1024, 2048};
	char Chave[]=CHAVE;
	
	EnviaRequisicaoThingSpeak(3,&ArrayCampos[0],Chave,sizeof(Chave));
}